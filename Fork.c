// QUI NON COMPILA, DA PROVARE IN LINUX

// 17

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    FILE *fileDescriptor;
    int number;

    // number = 5;
    number = fork();

    while (1)
    {
        fileDescriptor = fopen("test.txt", "a");
        fprintf(fileDescriptor, "%d\n", number);
        fclose(fileDescriptor);

        sleep(1);
    }

    return 0;
}
