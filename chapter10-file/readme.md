# Usage

## Compile it
```
gcc -o ln ln.c
gcc -o symlink symlink.c
gcc -o mkdir mkdir.c
gcc -o ls ls.c
gcc -o mv mv.c
gcc -o rm rm.c
gcc -o rmdir rmdir.c
```


## ln
ln creates hard link.
```
./ln hello hello2
# makes hard link hello2 of hello.
# hello should not be an directory. It should be a file.
```

## symlink
symlink creates symbolic link.

```
./symlink hello hello2
# makes symbolic link hello2 of hello.
# hello can also be directory.
```

## mkdir
makes directory
```
./mkdir hello
# creates hello
./mkdir hello2 bye
# creates hello2 bye
./mkdir hello3/bye
# hello3 should be already created to create hello3/bye.
```

## ls
list files
```
./ls .
# argument is always required.(at least `.`)
```

## mv
renames(move) file
```
./mv hello hello2
# renames hello to hello2.
# works directory also
```

## rm
removes file
```
./rm hello
# hello should be a file, not a directory.
```

## rmdir
removes directory
```
./rmdir hello
# hello should be an empty directory.
```
