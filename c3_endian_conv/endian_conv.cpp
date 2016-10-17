#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>

void ErrorHandling(char* message);

int main(int argc, char **argv)
{
	WSADATA wsaData;
	short hostOrdPort = 0x1234;
	short netOrdPort;

	long hostOrdAdd = 0x12345678;
	long netOrdAdd;
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("wsastartup() error");

	netOrdPort = htons(hostOrdPort);
	netOrdAdd = htonl(hostOrdAdd);

	printf("host ordered port: %x \n", hostOrdPort);
	printf("network ordered port: %x \n", netOrdPort);

	printf("host ordered address: %x \n", hostOrdAdd);
	printf("network ordered address: %x \n", netOrdAdd);

	WSACleanup();
	getchar();
	return 0;
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}