#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
	int sockfd, sockfd2, sockfd3, sockfd4, sockfd5, n;
	double curr, curr2, rtt1, rtt2=0.0, rtt3=0.0, rtt4=0.0, rtt5=0.0;
	struct sockaddr_in servaddr, servaddr2, servaddr3, servaddr4, servaddr5;
	char sendline[20], recvline[20], recvline2[20], recvline3[20], recvline4[20], recvline5[20];

    struct timeval  tv;
    struct timezone tz;
    
    sockfd = socket (AF_INET, SOCK_DGRAM, 0);
	bzero (&servaddr, sizeof (servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr ("54.169.67.45");
	servaddr.sin_port = htons (5000);
    
    sockfd2 = socket (AF_INET, SOCK_DGRAM, 0);
    bzero (&servaddr2, sizeof (servaddr2));
    servaddr2.sin_family = AF_INET;
    servaddr2.sin_addr.s_addr = inet_addr ("54.207.15.207");
    servaddr2.sin_port = htons (5000);
    
    sockfd3 = socket (AF_INET, SOCK_DGRAM, 0);
    bzero (&servaddr3, sizeof (servaddr3));
    servaddr3.sin_family = AF_INET;
    servaddr3.sin_addr.s_addr = inet_addr ("54.191.73.92");
    servaddr3.sin_port = htons (5000);
    
    sockfd4 = socket (AF_INET, SOCK_DGRAM, 0);
    bzero (&servaddr4, sizeof (servaddr4));
    servaddr4.sin_family = AF_INET;
    servaddr4.sin_addr.s_addr = inet_addr ("128.111.44.106");
    servaddr4.sin_port = htons (12291);
    
    sockfd5 = socket (AF_INET, SOCK_DGRAM, 0);
    bzero (&servaddr5, sizeof (servaddr5));
    servaddr5.sin_family = AF_INET;
    servaddr5.sin_addr.s_addr = inet_addr ("54.172.168.244");
    servaddr5.sin_port = htons (5000);
    
	while (fgets (sendline, 20, stdin) != NULL)
    {
		gettimeofday(&tv, &tz);
        curr = tv.tv_sec + ((float)tv.tv_usec/1000000.0);
        printf ("System  : %f\n", curr);
        sendto(sockfd,sendline,strlen(sendline),0,
             (struct sockaddr *)&servaddr,sizeof(servaddr));
        n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
        recvline[n]=0;
		gettimeofday (&tv, &tz);
        curr2 = tv.tv_sec+((float)tv.tv_usec/1000000.0);
        rtt1 = curr2 - curr;
        
        sendto(sockfd2,sendline,strlen(sendline),0,
               (struct sockaddr *)&servaddr2,sizeof(servaddr2));
        n=recvfrom(sockfd2,recvline2,10000,0,NULL,NULL);
        recvline2[n]=0;
        gettimeofday (&tv, &tz);
        curr = tv.tv_sec+((float)tv.tv_usec/1000000.0);
        rtt2 = curr - curr2;
        
        sendto(sockfd3,sendline,strlen(sendline),0,
               (struct sockaddr *)&servaddr3,sizeof(servaddr3));
        n=recvfrom(sockfd3,recvline3,10000,0,NULL,NULL);
        recvline3[n]=0;
        gettimeofday (&tv, &tz);
        curr2 = tv.tv_sec + ((float) tv.tv_usec/1000000.0);
        rtt3 = curr2 - curr;
        
        sendto(sockfd4,sendline,strlen(sendline),0,
               (struct sockaddr *)&servaddr4,sizeof(servaddr4));
        n=recvfrom(sockfd4,recvline4,10000,0,NULL,NULL);
        recvline4[n]=0;
        gettimeofday (&tv, &tz);
        curr = tv.tv_sec + ((float) tv.tv_usec/1000000.0);
        rtt4 = curr - curr2;
        
        sendto(sockfd5,sendline,strlen(sendline),0,
               (struct sockaddr *)&servaddr5,sizeof(servaddr5));
        n=recvfrom(sockfd5,recvline5,10000,0,NULL,NULL);
        recvline5[n]=0;
        gettimeofday (&tv, &tz);
        curr2 = tv.tv_sec + ((float) tv.tv_usec/1000000.0);
        rtt5 = curr2 - curr;
        
        printf ("Server 1: %s\nRTT1: %f\nServer 2: %s\nRTT2: %f\nServer 3: %s\nRTT3: %f\nServer 4: %s\nRTT4: %f\nServer 5: %s\nRTT5: %f\n", recvline, rtt1, recvline2, rtt2, recvline3, rtt3, recvline4, rtt4, recvline5, rtt5);
    }
	return 0;
}
