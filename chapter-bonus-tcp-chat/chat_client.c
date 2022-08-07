#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define DEFAULT_PORT "5555"

static int open_connection(char *host, char *service);

int main(int argc, char *argv[]) {
    int sock;
   
    FILE* responseFd;
    FILE* requestFd; 
    char buf[1024];

    char* port = DEFAULT_PORT;

    
    sock = open_connection((argc > 1 ? argv[1] : "localhost"), port);

    for (;;) {
	fgets(buf, sizeof buf, stdin);

	int bytes = write(sock, buf, sizeof buf);
	char bytesToStr[40];
	sprintf(bytesToStr, "%d", bytes);

	puts(bytesToStr);
	puts("request flushed!");
	memset(buf, '\0', sizeof buf);
	/** fgets(buf, sizeof buf, requestFd); **/

	read(sock, buf, sizeof buf);

	/** fclose(requestFd); **/

	fputs(buf, stdout);
    }

    exit(0);

}

static int open_connection(char *host, char *service) {
    int sock;
    struct addrinfo hints, *res, *ai;
    int err;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((err = getaddrinfo(host, service, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo(3): %s\n", gai_strerror(err));
	exit(1);
    }
    
    for (ai = res; ai; ai = ai -> ai_next) {
        sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
	if (sock < 0) {
	    continue;
	}
	if (connect(sock, ai -> ai_addr, ai -> ai_addrlen) < 0) {
	    close(sock);
	    continue;
	}
	freeaddrinfo(res);
	return sock;
    }
    fprintf(stderr, "socket(2)/connect(2) failed");
    freeaddrinfo(res);
    exit(1);
}















