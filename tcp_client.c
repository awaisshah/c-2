#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256] = "Hi Server"; //Message to be sent to server
    if (argc < 2) {
       fprintf(stderr,"usage %s hostname\n", argv[0]); // Command to used for running the client is : ./(executable) host_address
        //e.g : ./client 127.0.0.1 (If you are implementing client-server on the same machine
       exit(0);
    }
    portno = 1024; //You can choose any port number between 1024-65535
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Creating the socket
    if (sockfd < 0) { 
        perror("ERROR opening socket");
	exit(1);
    }
    server = gethostbyname(argv[1]); //argv[1] would be the host_addr specified while running the code (e.g : 127.0.0.1)
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    memset((char*) &serv_addr, 0, sizeof(serv_addr)); //Set the memory allotted to serv_addr to 0
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    {
	perror("ERROR connecting");
	exit(1);
    }
    n = write(sockfd,buffer,strlen(buffer));  //Send the hello message to server
    if (n < 0)
    { 
        perror("ERROR writing to socket");
	exit(1);
    }
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd,buffer,255); //Read server's response
    if (n < 0) { 
        perror("ERROR reading from socket");
	exit(1);	
    }
    printf("%s\n",buffer);
    close(sockfd);
    return 0;
}