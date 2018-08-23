
typedef void(*P)(char*);

_start()
{
	P put = (P)0x43e11a2c;
	char* pointer = (char*)put;
	(*pointer) = "FSD";
	put("hello world\n");
}
