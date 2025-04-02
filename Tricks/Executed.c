// 6

#include <stdio.h>
__attribute__((constructor))
void myFunc()
{
    printf("Executed first\n");
}

int main()
{
    printf("Executed second\n");

    return 0;
}