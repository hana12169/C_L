/*************************************************************************
    > File Name: sock_server.c
    > Author: zguiq
    > Mail: guiqiang.zhang@163.com 
    > Created Time: Fri 02 Sep 2016 07:50:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<ctype.h>
#include<string.h>

int port = 8000;

int main(int argc, char **argv)
{
	struct sockaddr_in sin;
	struct sockaddr_in pin;
	int sock_descriptor;
	int temp_sock_descriptor;
	int address_size;
	char buf[16348];

	int i, len;
	sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if( -1 == sock_descriptor )
	{
		printf("call to socket failed.\n");
		exit(1);
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);

	if( -1 == bind (sock_descriptor, (struct sockaddr *)&sin, sizeof(sin)))
	{
		printf("call to bind failed.\n");
		exit(1);
	}

	if( listen ( sock_descriptor, 20)== -1)
	{
		printf("call to listen failed.\n");
		exit(1);
	}

	printf("start accepting connections.\n");

	while ( 1 )
	{
		temp_sock_descriptor =  accept ( sock_descriptor, (struct sockaddr*) &pin, &address_size );
		if ( -1 == temp_sock_descriptor )
		{
			perror ("call to accept.\n");
			exit ( 1 );
		}

		if ( recv (temp_sock_descriptor, buf, 16384, 0) == -1)
		{
			printf("call to recv\n");
			exit ( 1);
		}
		printf ( "received from client:%s.\n", buf);
		len = strlen ( buf);
		for ( i= 0; i<len; i++)
		{
			buf [i] = toupper ( buf [i]);
		}
		if ( send ( temp_sock_descriptor, buf, len, 0) == -1)
		{
			printf ( "call to send.\n");
			exit (1);
		}
		close (temp_sock_descriptor);
	}
	return 0;
}
