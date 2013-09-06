#include <stdio.h>
void cookie(char msg[])
{
	printf("Message is %s\n",msg);
	printf("Message Size is %i\n",sizeof(msg));
}
int main(int argc, char const *argv[])
{
	/* code */
	cookie("Hello World");
	return 0;
}
