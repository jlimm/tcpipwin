#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ErrorHandling(char* message);

int main(int argc, char **argv)
{
	WSADATA wsaData;
	SOCKET hServSock;
	SOCKET hClntSock;
	SOCKADDR_IN servAddr;
	SOCKADDR_IN clntAddr;
	int szClntAddr;
	char message[] = "Hello World!\n";

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		getchar();
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // LOAD WINSOCKET 2.2DLL
		ErrorHandling("WSASTARTUP() error");

	hServSock = socket(PF_INET, SOCK_STREAM, 0); // create server socket
	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) //give adress to socket
		ErrorHandling("bind() error");

	if (listen(hServSock, 5) == SOCKET_ERROR)  //wait for connection
		ErrorHandling("listen() error");

	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr); //accept the connection
	if (hClntSock == INVALID_SOCKET)
		ErrorHandling("accept() error");

	send(hClntSock, message, sizeof(message), 0); //sending data

	closesocket(hClntSock); //connection end
	WSACleanup();
	getchar();
	return 0;

}

void ErrorHandling(char * message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	getchar();
	exit(1);
}
