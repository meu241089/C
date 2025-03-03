// QUI NON COMPILA, DA PROVARE IN LINUX

// 24

// trl - timed read line

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

struct timeVal
{
    time_t tv_sec; // seconds
    long tv_usec;  // microseconds
};

char *timedReadLine(int timeout)
{
    static char buffer[512];
    /*
    static
    Means that this data will be saved in the memory even after the function returns, in our case returns a string
     */

    fd_set rfds;
    /*
    fd_set
    A structure type that can represent a set of file descriptors.  According to POSIX, the maximum number of file descriptors in an fd_set structure is the value of the macro FD_SETSIZE.
    */

    struct timeval tv;
    int ret;

    FD_ZERO(&rfds);
    /*
    FD_ZERO()
    This macro clears (removes all file descriptors from) set. It should be employed as the first step in initializing a file descriptor set.
    */

    FD_SET(0, &rfds);
    /*
    FD_SET()
    This macro adds the file descriptor fd to set.  Adding a file descriptor that is already present in the set is a no-op, and does not produce an error.
    */

    tv.tv_sec = timeout; // seconds
    tv.tv_usec = 0;      // milliseconds

    ret = select(1, &rfds, 0, 0, &tv);

    if (ret && FD_ISSET(0, &rfds))
    {
        memset(buffer, 0, 512);
        ret = read(0, buffer, 511);

        if (ret < 1)
            return 0;
        ret--;
        buffer[ret] == 0;

        return buffer;
    }
    else
    {
        return 0;
    }

    /*
    FD_ISSET()
    select() modifies the contents of the sets according to the rules described below.  After calling select(), the FD_ISSET() macro can be used to test if a file descriptor is still present in a set.  FD_ISSET() returns nonzero if the file descriptor fd is present in set, and zero if it is not.
    */
}

int main()
{
    char *name;

    printf("What is your name? Think fast!\n");
    name = timedReadLine(3);

    if (name)
        printf("Hello %s\n", name);
    else
        printf("Too slow! \n");

    return 0;
}