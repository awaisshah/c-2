#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr, cliaddr;
    char sendline[20], recvline[20];
    
    time_t t = time(NULL);
    struct tm *tmptr = localtime(&t);
    time_t result = mktime(tmptr);
    printf ("Current time : %ld\n", result);
    sockfd = socket (AF_INET, SOCK_DGRAM, 0);
    
    bzero (&servaddr, sizeof (servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr (argv[1]);
    servaddr.sin_port = htons (5000);
    while (fgets (sendline, 20, stdin) != NULL)
    {
        sendto(sockfd,sendline,strlen(sendline),0,
               (struct sockaddr *)&servaddr,sizeof(servaddr));
        n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
        recvline[n]=0;
        fputs(recvline,stdout);
    }
    return 0;
}
