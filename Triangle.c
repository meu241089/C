// 7

#include <stdio.h>

int AreaTriangle(int base, int height)
{
    int area;

    area = (base * height) / 2;

    return area;
}

int main()
{
    int b, h, area;

    printf("Base: ");
    fflush(stdout);
    scanf("%d", &b);

    printf("Height: ");
    fflush(stdout);
    scanf("%d", &h);

    area = AreaTriangle(b, h);
    printf("The area is: %d\n", area);

    return 0;
}

/*

For output streams, fflush() forces a write of all user-space buffered data for the given output or update stream via the stream's underlying write function.

 For input streams associated with seekable files (e.g., disk  files, but not pipes or terminals), fflush() discards any buffered  data that has been fetched from the underlying file, but has not been consumed by the application.

 The open status of the stream is unaffected.

If the stream argument is NULL, fflush() flushes all open output streams.

*/