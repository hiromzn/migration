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
    short port = 1234;
    char *address = "127.0.0.1";
 
    addr.sin_family = AF_INET;
    addr.sin_port = htons( port );
    addr.sin_addr.s_addr = inet_addr( address );
 
    printf( "host native port# (host byte order): %d\n", port );
    printf( "struct sockaddr_in.sin_port(network byte order) : %d\n", addr.sin_port );
    printf( "struct sockaddr_in.sin_port(with ntohs()) : %d\n", ntohs( addr.sin_port ) );

    printf( "\n" );
    printf( "address (string): %s\n", address );
    printf( "struct sockaddr_in.sin_addr.s_addr(network byte order) : %08X\n", addr.sin_addr.s_addr );
    printf( "struct sockaddr_in.sin_addr.s_addr(with ntohl()) : %08X\n", ntohl( addr.sin_addr.s_addr ) );
}
