// 8

#include <stdio.h>
#include <stdlib.h> // per la funzione rand()
#include <sys/types.h>
#include <unistd.h> // queste due per la funzione getpid()

int OurRandomFunction(int max)
{
    int x;
    x = rand() % max + 1;
    return x;
}

/*
rand() % max --> 0123456789
rand() % max + 1 --> 12345678910
*/

int main()
{
    int random;

    srand(getpid());

    /*getpid(), get process identification, returns the process ID of the calling process (this is often used by routines that generate unique temporary filenames)*/

    random = OurRandomFunction(10);
    printf("%d\n", random);

    random = OurRandomFunction(100);
    printf("%d\n", random);

    return 0;
}