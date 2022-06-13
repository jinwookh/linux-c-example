# Usage
  
1. compile it
```
gcc -o http_server http_server.c
```

2. execute with wanted directory(ex: current directory(.))
Default directory is (.)
```
./http_server .
```

3. You can also make additional arguments.
Default port is 80.
```
./http_server --debug --port 80
```

3. request
```
curl localhost:80
```


# TODO
- process is created every request and becomes zombie as it ends. Zombie process needs to be deleted as child process ends.

- Connection between client and server is keep being established. Keeping connection alive may have some benefit, however this is not intended, and don't know why connection is being alive.

- child process takes over parent process, and listens port and establishes connection with client. There should be only one process who listens to the port.
