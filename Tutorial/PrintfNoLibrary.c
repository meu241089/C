// 27

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    /*
        0 - stdin (keyboard)
        1 - stdout (screen)
        2 - stderr (screen)
    */

    write(1, "Hello world\n", 12);

    return 0;
}