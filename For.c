// 15

#include <stdio.h>
#include <assert.h>
#define F fflush(stdout)

void multi(int t, int v)
{
    int result;
    result = t * v;
    printf("%d x %d = %d\n", t, v, result);

    return;
}

int main()
{
    int x, table;

    printf("Select multiplication table: ");
    F;
    scanf("%d", &table);

    assert((table < 13) && (table > 0));

    /* assert, abort the program if assertion is false. if expression is false assert() prints an error message to standard error and terminates the program by calling abort*/

    for (x = 0; x < 13; x++)
    {
        multi(table, x);
    }

    return 0;
}