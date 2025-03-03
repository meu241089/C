// 19

#include <ncurses/ncurses.h>

int main()
{
    int x, y;

    initscr();
    clear();

    getyx(stdscr, y, x);

    printw("x=%d\n"
           "y=%d\n",
           x, y);

    refresh();

    y = 5;  // 5 lines down
    x = 10; // 10 characters to right

    move(y, x);
    printw("Over here!");
    refresh();

    getch();
    endwin();

    return 0;
}