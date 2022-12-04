//Alonso Montelongo
//Project_2
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "ws2_32_.lib")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2spi.h>
#include <ws2tcpip.h>
#include <winsock.h>



//gcc Alonso_Montelongo_Project2_P1.c -o Alonso_Montelogno_Project2_P1.o -lws2_32
int main(int argc, char *argv[])
{
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t addressSize;
    int family = AF_INET;  //IPV4
    int type = SOCK_STREAM; //Allows for two way communication
    int protocol = IPPROTO_TCP; //TCP
    int port;
    char*localIP;
    char hostbuffer[256];
    struct hostent *localhost;
    int hostname;
    int n;
    int server_sock, client_sock;
    char buffer[1024];
    


    if(argc<2)
    {
        printf("\nNo port was passed! Server was not created.");
        return 0;
    }
    else
    {   
        port = atoi(argv[1]);
        printf("\nPORT:%d",port);
        
    }
    //SOCKET sock = INVALID_SOCKET;
    SOCKET sock;
    sock = socket(family,type,protocol);
    if(sock<0)
    {
        printf("\nSocket was not created.");
        return 0;
    }
    else
    {
        printf("\nSocket was succesfully created");
        printf("TestOne");
    }
   

    
    hostname =gethostname(hostbuffer,sizeof(hostbuffer));
    localhost =gethostbyname(hostbuffer);
    localIP = inet_ntoa(*((struct in_addr*)
                           localhost->h_addr_list[0]));
  
    printf("Hostname: %s\n", hostbuffer);
    printf("Host IP: %s", localIP);
    //localIP = inet_ntoa (*(struct in_addr *)*localhost ->h_addr_list);
    

    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr =inet_addr(localIP);
    serverAddress.sin_port = htons(port);
    printf("\nset server sockaddr structure");


    n = bind(sock,(SOCKADDR*) &serverAddress,sizeof(serverAddress));
    
    if (n< 0)
    {
        printf("\nSocket was not binded");
        return 0;
    }
    else
    {
        printf("\nSocket was binded succesfully to port: %d",port);
    }
   
    listen(sock,5);
    printf("\nListening...");

    while(1)
    {   
        addressSize -sizeof(clientAddress);
        client_sock =accept(server_sock,(struct sockaddr*)&clientAddress, &addressSize);
        printf("\nclient connected");
    }

}


