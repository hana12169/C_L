/*************************************************************************
    > File Name: sock_client.c
    > Author: zguiq
    > Created Time: Fri 02 Sep 2016 08:55:41 PM CST
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

char *host_name = "127.0.0.1";
int port = 8000;
int socket_descriptor;
struct sockaddr_in pin;
char recv_buf [512];
char send_buf [512];
pthread_t pthread;

void *thread_recev (void *arg);
void *thread_recev (void *arg)
{
	while ( 1)
	{
		if ( -1 == recv ( socket_descriptor, recv_buf, 512, 0))
		{
			printf ("Error in receiving response from server.\n");
			exit (1);
		}
		if ( 0 == strlen( recv_buf))
			continue;
		printf ("Server:%s\n",recv_buf);
		memset ( recv_buf, 0, strlen(recv_buf));
	}
}


int main (int argc, char **argv)
{
	//char buf [8192];
	//char message [256];

	struct hostent *server_host_name;
	//char *str = "A default test string";
	//if ( argc < 2)
	//{
	//	printf ("Usage:clint.out\"Any test string\"\n");
	//	printf ("A default test string will be sent\n");
	//}
	//else
	//{
	//	str = argv[1];
	//}
	if ( 0 == (server_host_name = gethostbyname ( host_name)))
	{
		printf ("Error resolving local host.\n");
		exit ( 1);
	}
	bzero ( &pin, sizeof ( pin));
	pin.sin_family = AF_INET;
	pin.sin_addr.s_addr = htonl ( INADDR_ANY);
	pin.sin_addr.s_addr = ( ( struct in_addr *) ( server_host_name->h_addr))->s_addr;
	pin.sin_port =  htons ( port);

	if ( -1 == ( socket_descriptor = socket ( AF_INET, SOCK_STREAM, 0)))
	{
		printf ( "Error opening socket.\n");
		exit ( 1);
	}
	if ( -1 == connect ( socket_descriptor, ( void *)&pin, sizeof (pin)))
	{
		printf ("Error connecting to socket.\n");
		exit (1);
	}

	pthread_create ( &pthread, NULL, thread_recev, NULL);

	while ( scanf("%s", send_buf)!= EOF)
	{
		//printf ("Client:");
		//scanf("%s", send_buf);
		//if ( memcmp (send_buf, "exit"))
		if ( NULL == strstr (send_buf, "Server"))
		{
			if ( -1 == send (socket_descriptor, send_buf, strlen ( send_buf), 0))
			{
				printf ("Error in sending.\n");
				exit(1);
			}
		}
		memset ( send_buf, 0, strlen(send_buf));

	}

	//printf ("Sending message %s to server.\n", str);
	//printf ("...sent message... wait for response.\n");
	//if ( -1 == recv ( socket_descriptor, buf, 8192, 0))
	//{
	//	printf("Error in receiving response from server.\n");
	//	exit ( 1);
	//}
	//printf ("Response from server:\n%s\n", buf);
	close ( socket_descriptor);
	return 0;
	
}
