#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>

void ErrorHandling(char* message);


int main(int argc, char** argv)
{
	char * addr1 = "1.2.3.4"; //works
	char * addr2 = "1.2.3.256"; //see if inet_addr works correctly
	unsigned long conv_addr;

	conv_addr = inet_addr(addr1);
	if (conv_addr == INADDR_NONE)
		printf("Error Occur : %d \n", conv_addr);
	else
		printf("Unsigned long addr(network odered) : %x \n", conv_addr);

	conv_addr = inet_addr(addr2);
	if (conv_addr == INADDR_NONE)
		printf("Error Occured : %d \n", conv_addr);
	else
		printf("Unsigned long addr(network ordered) : %x \n", conv_addr);

	getchar();
	return 0;


}