#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
     {
    	perror("ERROR creating socket");
     	exit(1);
     }	
     memset((char*) &serv_addr, 0, sizeof(serv_addr));
     portno = 1024;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
     {
   	 perror("Error binding");
    	 exit(1);
     }
     listen(sockfd,5); //Listen to incoming connections
     // The number 5 specifies the number of connections the server will accept
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
     { 
    	perror("ERROR accepting");
    	exit(1);
     }
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) { 
         perror("ERROR reading from socket");
         exit(1);
     }
     printf("Client says: %s\n",buffer);
     n = write(newsockfd,"Got your message",18);
     if (n < 0) {
         perror("ERROR writing to socket");
         exit(1);
     }
     close(newsockfd);
     close(sockfd);
     return 0;
}
