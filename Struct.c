// 12

#include <stdio.h>
#include <string.h>

struct person
{
    char title[8];
    char lastName[32];
    int age;
};

int main()
{
    struct person birch;

    strncpy(birch.title, "doctor", 7);
    strncpy(birch.lastName, "Birch", 31);
    birch.age = 38;

    printf("%s %s of the age %d\n",  birch.title, birch.lastName, birch.age);
    
    return 0;
}