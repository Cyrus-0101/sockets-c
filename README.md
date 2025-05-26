# sockets-c
An implementation of TCP Sockets in C. Writing a TCP Connection on Port 80 using Hyper Text Transfer Protocol (HTTP) over the web. We will not be using a DNS, just a hardcoded, and only IPv4

TO-DO: Change IP address to a working IP.

# What is a Socket?
It is an IP connection, where you connect with another device on the internet or in your local network and send/share data.

# Compile Script
```sh
    clang sockets.c -o sockets 
    # or if you use gcc
    gcc sockets.c -o sockets
```

# Debug Script
```sh
    strace -f ./sockets
```

# Run Script
```sh
    ./sockets
```

# References
```sh
man 2 socket
man 3 inet_addr
man 3 htons
man 2 connect
```
