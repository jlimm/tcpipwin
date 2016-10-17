#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>

void ErrorHandling(char* message);


int main(int argc, char** argv)
{
	SOCKADDR_IN addr1, addr2;
	char* str;
	addr1.sin_addr.s_addr = htonl(0x1020304);
	addr2.sin_addr.s_addr = htonl(0x1010101);

	str = inet_ntoa(addr1.sin_addr); //32bit int to dotted-decimal
	printf("Dotted-decimal notation : %s \n", str);

	inet_ntoa(addr2.sin_addr);
	printf("Dotted-decimal notation : %s \n", str);
	getchar();
	return 0;
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}