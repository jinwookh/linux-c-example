
# Usage
1. compile it
```
gcc -o cat cat.c
```

2. run it
```
cat example.file
```


# Explanation
cat uses raw read/write system call.   
`cat_with_stdio` uses standard I/O library.

Using raw read/write system call has several disadvantages.
1. system call can only be read/written as byte. It would be better if we can handle string as more convenient way, such as processing with new line.

2. you have to manage your own buffer with raw read/write system call. However, managing buffer is not easy. Performance issue can happen if buffer is small.

stdio library uses own buffer, and you can read/write without handling buffer directly.
