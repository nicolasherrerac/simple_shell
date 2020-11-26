# SIMPLE SHELL
Repository for Simple Shell project

![holberton logo](https://www.holbertonschool.com/holberton-logo.png)

# Description

UNIX command line interpreter. Execute commands read from the standard input.
No handle special characters, history and help built-in, file as input, comments, alias, && and ||.

# Requirements

All our files are compiled on Ubuntu 14.04 LTS
The C program and functions are compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

# Files

+ AUTHORS
+ README.md
+ builst.c
+ built_ins.c
+ enviroment.c
+ err.c
+ helpers.c
+ main.c
+ memory.c
+ path.c
+ man_1_simple_shell
+ shell.h
+ token_line.c

# Compilation

 - `$gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`


Execute the file hsh

 - `vagrant@vagrant-ubuntu-trusty-64:~$./hsh`



# Running the tests

The shell works like this in interactive mode:

 - `$ ./hsh`
 - `($) /bin/ls`
 - `hsh main.c shell.c`
 - `($)`
 - `($) exit`
 - `$`

Also in non-interactive mode:

 - `$ echo "/bin/ls" | ./hsh`
 - `hsh main.c shell.c test_ls_2`
 - `$`
 - `/bin/ls`
 - `/bin/ls`
 - `$`
 - `$ cat test_ls_2 | ./hsh`
 - `hsh main.c shell.c test_ls_2`
 - `hsh main.c shell.c test_ls_2`
 - `$`

# Usage

All the files are to be compiled on Ubuntu 14.04 LTS Compile your code with

 - `$gcc -Wall -Werror -Wextra -pedantic *.c`
 - `$ ./hsh`

type the command in interactive or non-interactive mode

# Libraries
- #include <stdio.h>
- #include <stdlib.h>
- #include <unistd.h>
- #include <string.h>
- #include <sys/types.h>
- #include <sys/stat.h>
- #include <sys/wait.h>
- #include <limits.h>
- #include <signal.h>

# List of allowed functions and system calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

# Examples

**Interactive Mode** 

    simple_shell git:(master) ✗ ./hsh
    $ ls
    _atoi.c  execute.c   helpers.c  memory.c  shell.c  token_line.c
    _env.c   funtions.c  hsh        prompt.c  shell.h
    $ ls -l 
    total 56
    -rw-rw-r-- 1 vagrant vagrant   415 Nov 23 20:26 _atoi.c
    -rw-rw-r-- 1 vagrant vagrant  1194 Nov 23 20:03 _env.c
    -rw-rw-r-- 1 vagrant vagrant   894 Nov 23 20:18 execute.c
    -rw-rw-r-- 1 vagrant vagrant  2143 Nov 23 20:17 funtions.c
    -rw-rw-r-- 1 vagrant vagrant  1277 Nov 23 20:06 helpers.c
    -rwxrwxr-x 1 vagrant vagrant 14650 Nov 23 20:23 hsh
    -rw-rw-r-- 1 vagrant vagrant   372 Nov 23 20:11 memory.c
    -rw-rw-r-- 1 vagrant vagrant   277 Nov 23 20:23 prompt.c
    -rw-rw-r-- 1 vagrant vagrant   664 Nov 23 20:00 shell.c
    -rw-rw-r-- 1 vagrant vagrant  1137 Nov 23 19:54 shell.h
    -rw-rw-r-- 1 vagrant vagrant   555 Nov 23 20:07 token_line.c
    $  echo Hello
    Hello
    $ qwerty
    Error: No such file or directory
    $ env
    USER=ubuntu
    LANGUAGE=en_US
    SESSION=ubuntu
    COMPIZ_CONFIG_PROFILE=ubuntu
    SHLVL=1
    HOME=/home/vagrant
    DESKTOP_SESSION=ubuntu
    LOGNAME=vagrant
    TERM=xterm-256color
    PATH=/home/vagrant/bin:/home/vagrant/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin
    DISPLAY=:0
    $ exit
    simple_shell git:(master) ✗


 **Non-interactive Mode**
    
    simple_shell git:(master) ✗ echo "ls" | ./hsh
    _atoi.c  execute.c   helpers.c  memory.c  shell.c  token_line.c
    _env.c   funtions.c  hsh        prompt.c  shell.h
    simple_shell git:(master) ✗ echo "ls -l" | ./hsh
    $ total 56
    -rw-rw-r-- 1 vagrant vagrant   415 Nov 23 20:26 _atoi.c
    -rw-rw-r-- 1 vagrant vagrant  1194 Nov 23 20:03 _env.c
    -rw-rw-r-- 1 vagrant vagrant   894 Nov 23 20:18 execute.c
    -rw-rw-r-- 1 vagrant vagrant  2143 Nov 23 20:17 funtions.c
    -rw-rw-r-- 1 vagrant vagrant  1277 Nov 23 20:06 helpers.c
    -rwxrwxr-x 1 vagrant vagrant 14650 Nov 23 20:23 hsh
    -rw-rw-r-- 1 vagrant vagrant   372 Nov 23 20:11 memory.c
    -rw-rw-r-- 1 vagrant vagrant   277 Nov 23 20:23 prompt.c
    -rw-rw-r-- 1 vagrant vagrant   664 Nov 23 20:00 shell.c
    -rw-rw-r-- 1 vagrant vagrant  1137 Nov 23 19:54 shell.h
    -rw-rw-r-- 1 vagrant vagrant   555 Nov 23 20:07 token_line.c
    simple_shell git:(master) ✗ echo  "qwerty" | ./hsh
    ./hsh: 1: qwerty: not found
    simple_shell git:(master) ✗


# Authors

- Nicolar Herrera Castro - https://github.com/nicolasherrerac
- Victor Manuel Plaza - https://github.com/vic-1998

