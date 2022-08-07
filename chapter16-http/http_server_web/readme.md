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

# example response
```
HTTP/1.1 404 Not Found
Date: Wed, 27 Jul 2022 02:43:51 GMT
Server: hello/1
Connection: close
Content-Type: text/html
```


# TODO
- process is created every request and becomes zombie as it ends. Zombie process needs to be deleted as child process ends.    
-> problem solved.
set `SA_NOCLDWAIT` flag so the parent does not wait for the child process.
If child process ends, it just ends.

- Connection between client and server is keep being established. Keeping connection alive may have some benefit, however this is not intended, and don't know why connection is being alive.
-> problem solved.
connection is not being alive. connection ends when client recieves the response.

- child process takes over parent process, and listens port and establishes connection with client. There should be only one process who listens to the port.
-> problem solved,
child process does not take over the parent process. It just ends after working iwth single request is done.


# Bonus
use `http_client.c` to request http.
```
gcc -o http_client http_client.c
./http_client
```

The value of request is coded inside.
