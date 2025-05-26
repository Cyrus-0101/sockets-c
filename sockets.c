#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define IP "172.217.170.196" /* www.google.com */
#define PORT 80              /* http */

int main()
{
    // File descriptor for the socket
    int s;

    // Structure for handling Internet addresses
    struct sockaddr_in sock;

    // Buffer to store server's response
    char buff[512];

    // HTTP request to send to server
    char *data;

    // Simple HTTP HEAD request with double newline as per HTTP spec
    data = "HEAD / HTTP/1.0\n\n";

    // Create TCP/IP socket (AF_INET for IPv4, SOCK_STREAM for TCP, 0 for default protocol)
    s = socket(AF_INET, SOCK_STREAM, 0);

    // If error is returned log
    if (s < 0)
    {
        printf("ERROR: socket() error\n");
        return -1;
    }

    // Configure server address structure
    sock.sin_addr.s_addr = inet_addr(IP);    // Convert IP to binary form
    sock.sin_port = htons(PORT);             // Convert port to network byte order
    sock.sin_family = AF_INET;               // Use IPv4

    if (connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) != 0)
    {
        printf("ERROR: connect() error\n");
        close(s);

        return -1;
    }
    // Send HTTP request to server
    write(s, data, strlen(data));

    // Clear buffer before reading response
    memset(buff, 0, 512);

    // Read server's response (limiting to 511 bytes to ensure null termination)
    read(s, buff, 511);

    // Clean up by closing the socket
    close(s);

    // Print server's response
    printf("\n%s\n", buff);

    return 0;
}