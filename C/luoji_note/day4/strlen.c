

void fun(void);

int _start()
{

	unsigned int  (*strlen)(const char*) = (void*)0x43e25fa8;
	int (*printf)(const char *, ...) = (void*)0x43e11a2c;
	void * (*malloc)(unsigned int) = (void*)0x43e1227c;
	char *(*strcpy)(char *, const char *) = (void*)0x43e25e38;

	char* p =(char*)malloc(100u);
	strcpy(p,"hello world!\n");
	unsigned int len;
	len = strlen(p);
	printf("len:%u\n",len);
	printf("%s",p);	
	fun();
}

void fun(void)
{
	int (*printf)(const char *, ...) = (void*)0x43e11a2c;
	printf("I am fun\n");
	printf("fun--addressa %p\n", fun);

}


