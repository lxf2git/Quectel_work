#include "P12306.h"

int db_open()
{
	if ((db_12306.db_train_fd = open("database/train.db", O_RDWR)) < 0){
		perror("database open error");
		return -1;
	}
	if ((db_12306.db_index_fd = open("database/index.db", O_RDWR)) < 0){
		perror("database open error");
		return -1;
	}

	if ((db_12306.db_data_fd = open("database/data.db", O_RDWR)) < 0){
		perror("database open error");
		return -1;
	}
	pthread_rwlock_init(&(db_12306.rwlock), NULL);

	return 0;
}


int db_close()
{
	close(db_12306.db_train_fd);
	close(db_12306.db_index_fd);
	close(db_12306.db_data_fd);
	pthread_rwlock_destroy(&(db_12306.rwlock));
	return 0;
}

int db_train_info(char place[50], char *data)
{
	struct db_train train;
	int count;

	pthread_rwlock_rdlock(&(db_12306.rwlock));
	lseek(db_12306.db_train_fd, 0, SEEK_SET);
	
	while(1){
		memset(&train, 0, sizeof(train));
		count = read(db_12306.db_train_fd, &train, sizeof(train));
		if (0 == count){
			break;	
		}
		else if (!strcmp(train.place, place)){
			sprintf(data, "%s:%s:%d", train.train, train.place, train.num);
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
	}

	pthread_rwlock_unlock(&(db_12306.rwlock));
	return -1;

}


int db_add_user(char username[30], char passwd[20])
{
	ssize_t count;
	struct db_user user;
	
	memset(&user, 0, sizeof(user));
	pthread_rwlock_wrlock(&(db_12306.rwlock));
	lseek(db_12306.db_index_fd, 0, SEEK_SET);
	while(1){
		count = read(db_12306.db_index_fd, &user, sizeof(user));	
		if (!strcmp(user.name, username)){
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return -1;
		}
		else if (count == 0)
			break;
	}
	
	memset(&user, 0, sizeof(user));
	strcpy(user.name, username);
	strcpy(user.passwd, passwd);
	user.index = lseek(db_12306.db_data_fd, 0, SEEK_END);
	write(db_12306.db_index_fd, &user, sizeof(user));
	pthread_rwlock_unlock(&(db_12306.rwlock));
	return 0;
}


int db_user_passwd(char username[30], char *passwd)
{
	ssize_t count;
	struct db_user user;

	memset(&user, 0, sizeof(user));
	pthread_rwlock_rdlock(&(db_12306.rwlock));
	lseek(db_12306.db_index_fd, 0, SEEK_SET);
	while(1){
		count = read(db_12306.db_index_fd, &user, sizeof(user));	
		printf("%s\n", user.name);
		if (!strcmp(user.name, username)){
			strcat(passwd, user.passwd);
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
		else if (count == 0){
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return -1;
		}
	}
}


int db_user_info(char username[30], char *data)
{
	ssize_t count;
	struct db_user user;
	struct db_user_info user_info;

	memset(&user_info, 0, sizeof(user_info));
	memset(&user, 0, sizeof(user));
	pthread_rwlock_rdlock(&(db_12306.rwlock));
	lseek(db_12306.db_index_fd, 0, SEEK_SET);
	while(1){
		count = read(db_12306.db_index_fd, &user, sizeof(user));	
		if (!strcmp(user.name, username)){
			lseek(db_12306.db_data_fd, user.index, SEEK_SET);
			read(db_12306.db_data_fd, &user_info, sizeof(user_info));
			strcpy(data, user_info.train);
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
	}
}


int db_add_ticket(char username[30], char train[10])
{
	ssize_t count;
	struct db_user user;
	struct db_user_info user_info;

	memset(&user, 0, sizeof(user));
	memset(&user_info, 0, sizeof(user_info));
	pthread_rwlock_wrlock(&(db_12306.rwlock));
	lseek(db_12306.db_index_fd, 0, SEEK_SET);
	while(1){
		count = read(db_12306.db_index_fd, &user, sizeof(user));	
		if (!strcmp(user.name, username)){
			lseek(db_12306.db_data_fd, user.index, SEEK_SET);
			read(db_12306.db_data_fd, &user_info, sizeof(user_info));
			strcat(user_info.train, ":");
			strcat(user_info.train, train);
			lseek(db_12306.db_data_fd, user.index, SEEK_SET);
			write(db_12306.db_data_fd, &user_info, sizeof(user_info));
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
	}
}


int db_del_ticket(char username[30], char train[10])
{
	ssize_t count;
	char *del_tmp, del_buf[5];
	struct db_user user;
	struct db_user_info user_info;

	memset(&user, 0, sizeof(user));
	memset(&user_info, 0, sizeof(user_info));
	memset(&del_buf, 0, sizeof(del_buf));
	pthread_rwlock_wrlock(&(db_12306.rwlock));
	lseek(db_12306.db_index_fd, 0, SEEK_SET);
	while(1){
		count = read(db_12306.db_index_fd, &user, sizeof(user));	
		if (!strcmp(user.name, username)){
			lseek(db_12306.db_data_fd, user.index, SEEK_SET);
			read(db_12306.db_data_fd, &user_info, sizeof(user_info));
			sprintf(del_buf, ":%s", train);
			del_tmp = strstr(user_info.train, del_buf);
			if (NULL == del_tmp){
				pthread_rwlock_unlock(&(db_12306.rwlock));
				return -1;
			}
			*del_tmp = 0;
			strcat(user_info.train, del_tmp+6);
			lseek(db_12306.db_data_fd, user.index, SEEK_SET);
			write(db_12306.db_data_fd, &user_info, sizeof(user_info));
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
	}
}

int db_change_train(char train[10], char flag)
{
	int count;
	struct db_train train_tmp;

	pthread_rwlock_wrlock(&(db_12306.rwlock));
	lseek(db_12306.db_train_fd, 0, SEEK_SET);
	while(1){
		memset(&train_tmp, 0, sizeof(train_tmp));
		count = read(db_12306.db_train_fd, &train_tmp, sizeof(train_tmp));
		puts(train_tmp.train);
		if (count == 0){
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return -1;
		}
		else if (!strcmp(train_tmp.train, train)){
			if (flag == '+'){
				train_tmp.num++;
			}
			else{
				train_tmp.num--;
			}
			lseek(db_12306.db_train_fd, (sizeof(train_tmp)-2*sizeof(train_tmp)), SEEK_CUR);
			write(db_12306.db_train_fd, &train_tmp, sizeof(train_tmp));
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
	}
}


int db_ticket_num(char train[10])
{
	int count;
	struct db_train train_tmp;

	pthread_rwlock_wrlock(&(db_12306.rwlock));
	lseek(db_12306.db_train_fd, 0, SEEK_SET);
	while(1){
		memset(&train_tmp, 0, sizeof(train_tmp));
		count = read(db_12306.db_train_fd, &train_tmp, sizeof(train_tmp));
		if (count == 0){
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return -1;
		}
		else if (!strcmp(train_tmp.train, train)){
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return train_tmp.num;	
		}
	}
}

int db_ticket_place(char train[10], char *data)
{
	int count;
	struct db_train train_tmp;

	pthread_rwlock_wrlock(&(db_12306.rwlock));
	lseek(db_12306.db_train_fd, 0, SEEK_SET);
	while(1){
		memset(&train_tmp, 0, sizeof(train_tmp));
		count = read(db_12306.db_train_fd, &train_tmp, sizeof(train_tmp));
		if (count == 0){
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return -1;
		}
		else if (!strcmp(train_tmp.train, train)){
			strcpy(data, train_tmp.place);	
			pthread_rwlock_unlock(&(db_12306.rwlock));
			return 0;
		}
	}
}

