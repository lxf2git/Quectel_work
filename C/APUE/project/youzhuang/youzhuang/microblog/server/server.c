#include "../microblog.h"
#include "../apue.h"
#include "pool.h"

int main()
{
		printf("run...\n");
		int sockfd, confd, fun, ret;
		sockfd = getsockfd();
		pool_init( 10 );
		init_user_info( &puihead );

		while(1)
		{
				confd = accept(sockfd, NULL, NULL);
				if(confd < 0)
				{
						perror("confd");
						close(sockfd);
						continue;
				}
				bzero(&fun, sizeof(fun));
				ret = read(confd, &fun, sizeof(fun));
				if(ret < 0)
				{
						close(confd);
						continue;
				}
				switch( fun )
				{
						case LOGIN:
								pool_add_worker(Login, confd);
								break;
						case REGISTER:
								pool_add_worker(Register, confd);
								break;
						case SEARCH:
								pool_add_worker(Search, confd);
								break;
						case ATTENTION:
								pool_add_worker(Find_friend, confd);
								break;
						case FANC:
								pool_add_worker(Find_fanc, confd);
								break;
						case PUBLISH:
								pool_add_worker(Publish_microblog, confd);
								break;
						case DELBLOG:
								pool_add_worker(Del_microblog, confd);
								break;
						case CHANGEPWD:
								pool_add_worker(Rewrite_basic_info, confd);
								break;
						case 100:
								pool_add_worker(Own_zone, confd);
						default:
								break;
				}
		}
		pool_destroy();
		return 0;
}


int getsockfd()
{
		int sockfd, ret;
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(8888);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
		sockfd = socket( AF_INET, SOCK_STREAM, 0 );
		if( sockfd < 0 )
		{
				perror("socket");
				exit(-1);
		}
		ret = bind( sockfd, (struct sockaddr *)&addr, sizeof(addr));
		if(ret < 0)
		{
				perror("bind");
				close(sockfd);
				exit(-1);
		}
		ret = listen( sockfd, 10);
		if(ret < 0)
		{
				perror("listen");
				close(sockfd);
				exit(-1);
		}
		return sockfd;
}
