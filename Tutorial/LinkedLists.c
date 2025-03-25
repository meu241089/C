// 22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structBook
{
    char title[64];          // 64 bytes
    int pages;               // 4 bytes
    struct structBook *next; // 4 bytes
};

typedef struct structBook Book;

Book *first;
int numBooks;

void addBook(char *title, int pages)
{
    Book *bookPointer, *newPointer;

    if (!first)
    {
        bookPointer = malloc(sizeof(Book)); // 64+4+4

        memset(bookPointer, 0, sizeof(Book));

        numBooks++;

        strncpy(bookPointer->title, title, 63);
        bookPointer->pages = pages;
        bookPointer->next = 0;
        first = bookPointer;

        return;
    }

    for (bookPointer = first; bookPointer->next; bookPointer = bookPointer->next)
        ;

    newPointer = malloc(sizeof(Book)); // 64+4+4

    memset(newPointer, 0, sizeof(Book));

    numBooks++;

    strncpy(newPointer->title, title, 63);
    newPointer->pages = pages;
    newPointer->next = 0;

    bookPointer->next = newPointer;

    return;
}

void listBooks(char *searchStr)
{
    Book *bookPointer;

    for (bookPointer = first; bookPointer; bookPointer = bookPointer->next)
        if (!searchStr || !strcmp(searchStr, bookPointer->title))
            printf("Pages: %d\tTitle: '%s' \n", bookPointer->pages, bookPointer->title);

    return;
}

int removeBook(char *searchStr)
{
    Book *bookPointer, *penUltimateItem;

    for (bookPointer = first; bookPointer; penUltimateItem = bookPointer, bookPointer = bookPointer->next)
        if (!searchStr || !strcmp(searchStr, bookPointer->title))
        {
            if (first == bookPointer)
            {
                first = bookPointer->next;
            }
            else
            {
                penUltimateItem->next = (bookPointer->next) ? bookPointer->next : 0;
            }

            free(bookPointer);

            return 1;
        }

    return 0;
}

int main()
{
    int ret;

    first = 0;
    numBooks = 0;

    addBook("The Bible", 3500);

    // printf("%s\n", first->title);

    addBook("Dice Man", 340);
    addBook("Pippi Longstockings", 120);
    addBook("Tintin", 350);
    addBook("Around the world in 80 days", 290);

    // ret = removeBook("Pippi Longstockings");
    // printf("%d\n", ret);

    // ret = removeBook("Around the world in 80 days");
    // printf("%d\n", ret);

    // ret = removeBook("Pippi Longstockings");
    // printf("%d\n", ret);

    ret = removeBook("The Bible");
    printf("%d\n", ret);

    // listBooks("Dice Man");
    // printf("%s\n", first->next->title);
    // printf("%s\n", first->next->next->title);
    listBooks(0);

    return 0;
}