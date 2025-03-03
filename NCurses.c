// 18

/*

Si suppone che MinGW sia già stato correttamente installato nel sistema.
1. Aprire il programma “MinGW Installation Manager” (può essere cercato nel menù start scrivendo MinGW).
2. Cercare i seguenti pacchetti e cliccare sulle checkbox per selezionarli:
    a. mingw32-libncurses (dll)
    b. mingw32-libcurses (dev)
    c. mingw32-libpdcurses (dll)
    d. mingw32-libpdcurses (dev)
3. Cliccare sul menu contestuale in alto, sulla voce Installation → Apply Changes.

Per compilare con ncurses --> gcc NCurses.c -o NCurses -lncurses

Per eseguire --> & ".\NCurses"

*/

#include <ncurses/ncurses.h>

int main()
{
    char letter;

    initscr(); // initialize the screen
    printw("Press any key: ");
    refresh(); // refresh the screen after every upgrade

    letter = getch(); // you can read characters, numbers, left arrow, escape, ecc
    clear();

    printw("You pushed: '%c'", letter);
    refresh();

    getch();
    endwin();

    return 0;
}