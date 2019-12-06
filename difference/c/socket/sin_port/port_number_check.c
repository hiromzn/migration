#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
int main() {
    int sockfd;
    struct sockaddr_in addr;
    int i;
    short port = 0x1234;
    int int_port;
    char *address = "127.0.0.1";
 
    addr.sin_family = AF_INET;
    addr.sin_port = htons( port );
    addr.sin_addr.s_addr = inet_addr( address );
 
    printf( "host native port# (host byte order): 0x%08X\n", port );
    printf( "struct sockaddr_in.sin_port(network byte order) : 0x%08X\n", addr.sin_port );
    printf( "struct sockaddr_in.sin_port(with ntohs()) : 0x%08X\n", ntohs( addr.sin_port ) );

    printf( "\n" );
    printf( "convert to short : ntohs( sin_port ) : 0x%08X\n", ntohs( addr.sin_port ) );
    printf( "convert to int   : ntohl( sin_port ) : 0x%08X\n", ntohl( addr.sin_port ) );
}
