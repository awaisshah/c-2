#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
     int k=0,sockfd, newsockfd, portno, i=0;
     socklen_t clilen;
     unsigned char buffer[256];
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
     printf("The received string is : %s\n", buffer);
     for (i=0; buffer[i]!='\0'; i++)
     {
	if (buffer[i] == ' ') {
	  if (buffer[i+2]>=48 && buffer[i+2]<=57) 
	  {	
	   k=(buffer[i+1]-48)*10 + (buffer[i+2]-48); 
	  }
	  else
	   k=buffer[i+1]-48;
	   break;
	}
     }
     printf("Value of k is : %d\n",k);
     for (i=0;buffer[i]!=' ';i++)
     {
	buffer[i] = buffer[i] + k;
	if (buffer[i]>122)
	   buffer[i] = buffer[i] - 26;
     }
     buffer[i] = '\0';
     printf("The encrypted string is : %s\n", buffer);
     if (n < 0) { 
         perror("ERROR reading from socket");
         exit(1);
     }
     n = write(newsockfd,"Got your message",18);
     if (n < 0) {
         perror("ERROR writing to socket");
         exit(1);
     }
     close(newsockfd);
     close(sockfd);
     return 0;
}
