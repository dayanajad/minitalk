*This project has been created as part of the 42 curriculum by dbinti-m.*

## MINITALK

## Descriptions

Minitalk is a small data exchange program using UNIX signals. The project consists of a client and a server that communicate using only two signals: SIGUSR1 and SIGUSR2. The client sends a string to the server character by character, converting each character to binary and transmitting each bit as a signal.

Key concepts:
- UNIX signals (SIGUSR1, SIGUSR2)
- Bitwise operations for character encoding/decoding
- Process communication via kill() and signal handlers
- Server acknowledgment system (bonus)

## Instructions

## Compilation

```
make
```

For bonus:
```
make bonus
```

## Execution

Start the server first:
```
./server
```

The server will display its PID. Use this PID to send messages from the client:
```
./client [server_pid] "Your message here"
```

Example:
```
./server
# Output: Server PID: 12345

./client 12345 "Hello, World!"
# Server displays: Hello, World!
```

## RESOURCES

- [UNIX Signals Programming](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)
- [Bitwise Operations in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

## AI Usage

Used AI as a study buddy for understanding UNIX signals and bitwise operations
