#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <math.h>
#include <pthread.h>

int sockfd, sockfd2, sockfd3, sockfd4, sockfd5;
double curr, curr1, curr2, curr3, curr4, curr5;
double rtt[5];
double error, avg;
struct sockaddr_in servaddr, servaddr2, servaddr3, servaddr4, servaddr5;
char sendline[20], recvline[20], buffer[20], buffer2[20], buffer3[20], buffer4[20], buffer5[20];
double t[5];
double rt[5];
struct timeval  tv, tv1, tv2, tv3, tv4, tv5;
struct timezone tz;
int n1, n2, n3, n4, n5;
pthread_t th1, th2, th3, th4, th5;

double square (double a) {
    return a*a;
}

void* receive () {
    pthread_t id = pthread_self();
    
    if (pthread_equal(id, th1)) {
		n1 = recvfrom (sockfd, buffer, 64, 0, NULL, NULL);
		gettimeofday (&tv1, 0);
		t[0] = atof(buffer);
        printf ("\n%f\n", t[0]);
		rt[0] = (double)tv1.tv_sec + (double) (tv1.tv_usec)/1000000.0;
		rtt[0] = rt[0] - curr;
		printf ("System: %f\tServer1: %f\tRTT1: %f\n", curr, rt[0], rtt[0]);
	}
    
	else if (pthread_equal(id, th2)) {
        n2 = recvfrom (sockfd2, buffer2, 64, 0, NULL, NULL);
        gettimeofday (&tv2, 0);
        t[1] = atof(buffer2);
        rt[1] = (double)tv2.tv_sec + (double) (tv2.tv_usec)/1000000.0;
        rtt[1] = rt[1] - curr;
        printf ("System: %f\tServer2: %f\tRTT2: %f\n", curr, rt[1], rtt[1]);
    }

	else if (pthread_equal(id, th3)) {
        n3 = recvfrom (sockfd3, buffer3, 64, 0, NULL, NULL);
        gettimeofday (&tv3, 0);
        t[2] = atof(buffer3);
        rt[2] = (double)tv3.tv_sec + (double) (tv3.tv_usec)/1000000.0;
        rtt[2] = rt[2] - curr;
        printf ("System: %f\tServer3: %f\tRTT3: %f\n", curr, rt[2], rtt[2]);
    }

	else if (pthread_equal(id, th4)) {
        n4 = recvfrom (sockfd4, buffer4, 64, 0, NULL, NULL);
        gettimeofday (&tv4, 0);
        t[3] = atof(buffer4);
        rt[3] = (double)tv4.tv_sec + (double) (tv4.tv_usec)/1000000.0;
        rtt[3] = rt[3] - curr;
        printf ("System: %f\tServer4: %f\tRTT4: %f\n", curr, rt[3], rtt[3]);
    }
	
	else if (pthread_equal(id, th5)) {
        n5 = recvfrom (sockfd5, buffer5, 64, 0, NULL, NULL);
        gettimeofday (&tv5, 0);
        t[4] = atof(buffer5);
        rt[4] = (double)tv5.tv_sec + (double) (tv5.tv_usec)/1000000.0;
        rtt[4] = rt[4] - curr;
        printf ("System: %f\tServer5: %f\tRTT5: %f\n", curr, rt[4], rtt[4]);
    }

    return NULL;
}

int main(int argc, char **argv) {
    
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
    
    while (fgets (sendline, 20, stdin) != NULL) {
		gettimeofday(&tv, 0);
        curr = tv.tv_sec + ((float)tv.tv_usec/1000000.0);
        printf ("Current Time : %f\n", curr);
        sendto(sockfd,sendline,strlen(sendline),0,
            (struct sockaddr *)&servaddr,sizeof(servaddr));
        sendto(sockfd2,sendline,strlen(sendline),0,
            (struct sockaddr *)&servaddr2,sizeof(servaddr2));
        sendto(sockfd3,sendline,strlen(sendline),0,
            (struct sockaddr *)&servaddr3,sizeof(servaddr3));
        sendto(sockfd4,sendline,strlen(sendline),0,
            (struct sockaddr *)&servaddr4,sizeof(servaddr4));
        sendto(sockfd5,sendline,strlen(sendline),0,
            (struct sockaddr *)&servaddr5,sizeof(servaddr5));

        pthread_create (&th1, NULL, receive, NULL);
        pthread_create (&th2, NULL, receive, NULL);
		pthread_create (&th3, NULL, receive, NULL);
        pthread_create (&th4, NULL, receive, NULL);
		pthread_create (&th5, NULL, receive, NULL);

		pthread_join (th1, NULL);
		pthread_join (th2, NULL);
		pthread_join (th3, NULL);
		pthread_join (th4, NULL);
		pthread_join (th5, NULL);

      /*  error = square(t1-avg-(rtt1/2)) + square(t2-avg-(rtt2/2)) +
                square(t3-avg-(rtt3/2)) + square(t4-avg-(rtt4/2))
                + square(t5-avg-(rtt5/2)); */
            
    }
    return 0;
}
