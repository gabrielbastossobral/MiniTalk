
# MiniTalk

This project consists of a conversation between the server and the client. The client will send its message and it will be displayed on the server, but in two separate programs.

To complete this project I had to learn more about the signal.h library, through which I can send signals that can represent something. In my case, I made the signals represent 1 or 0 and in this way I passed the message to the server bit by bit.

Execution process there is a PID, a number of identification, we use that to communicate with the server trough the client.
## How to use

```bash
make
```
```bash
./server
Get the PID man!
{PID number}
```
```bash
./client {PID} message
```

![Logo](https://github.com/willtrigo/willtrigo/raw/main/42_badges/minitalkm.png)

