/*
    Simple udp server
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data
 
void die()
{
    exit(1);
}
 
int main(void)
{
    // This struct saves informations that are useful for getAddrInfo
    struct sockaddr_in me;
    struct sockaddr_storage other;
    // This is the socket file descriptor
    int sock; 
    // This saves the size of "from"
    socklen_t otherLen;

    // This is the buffer that stores the received message
    char buf[BUFLEN] = {'\0'}; 

    //Creating a socket using the infos. I've got with getAddrInfo
    //Note: I should check for errors during this call
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // zero out the structure
    memset((char *) &me, 0, sizeof(me));
     
    me.sin_family = AF_INET;
    me.sin_port = htons(PORT);
    me.sin_addr.s_addr = htonl(INADDR_ANY);

    //Now that I have a socket, I need to bind it to one of my PC ports using bind()
    bind(sock , (struct sockaddr*)&me, sizeof(me) );
     
    while(true){
        //clear our buffer
        memset((char *) &buf, 0, BUFLEN);

        // This reads some message that I've received
        recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr*)&other, &otherLen);
        printf("Data received: %s\n", buf);
        // This sends a message to the client
        sendto(sock, "Received\n", strlen("Received\n"), 0, (struct sockaddr*)&other, otherLen);
    }
    
    //freeing the used memory
    close(sock);
    return 0;
}