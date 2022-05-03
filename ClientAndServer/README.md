# LAB11

```
Yiming Ge
Who did you work with? Myself
How long did you spend on this? 3 hours 
What outside resources did you use? 
https://en.wikipedia.org/wiki/Transmission_Control_Protocol
https://man7.org/linux/man-pages/man3/getaddrinfo.3.html
```

# How to run the code
```
Use make run_echo_server to start the server program first
Use make run_echo_client to start the client program second
Use cmd + c to force quit the while loop

Sample output:

CLIENT SIDE:
Enter your message: hi
SENDING: hi

FROM SERVER: How many times you want to repeat?
Enter your message: 4
SENDING: 4

FROM SERVER: hi
hi
hi
hi

Enter your message: bye
SENDING: bye

FROM SERVER: How many times you want to repeat?
Enter your message: 3
SENDING: 3

FROM SERVER: bye
bye
bye

==============================
SERVER SIDE:

stening on file descriptor 3, port 1234
Waiting for connection...
Connection made: client_fd=4
hi

bye

see you

```
