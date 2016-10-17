#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ErrorHandling(char* message);

int main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET hTCPSock;
	SOCKET hUDPSock;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // LOad Winsock 2.2dll
		ErrorHandling("WSAStartup() error");

	// Create TCPSOCKET
	hTCPSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hTCPSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	// Create UDPSocket
	hUDPSock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (hUDPSock == INVALID_SOCKET)
		ErrorHandling("Socket() Error");

	printf("created handle of tcp socket: %d \n", hTCPSock);
	printf("created handle of udp socket: %d \n", hUDPSock);

	closesocket(hTCPSock);
	closesocket(hUDPSock);

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