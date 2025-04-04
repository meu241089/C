// 20

#include <ncurses/ncurses.h>

int main()
{
    int key, x, y;

    initscr();
    keypad(stdscr, TRUE); // function to enable the numpad (the right part of keyboard)
    noecho();
    x = y = 5;

    clear();
    move(0, 0);
    printw("Press left or right arrow - exit by pressing: q");

    move(y, x);
    printw("O");
    refresh();

    key = getch();

    if (key == KEY_LEFT)
    {
        x--;
        if (x < 0)
            x = 0;
    }
    else if (key == KEY_RIGHT)
    {
        x++;
        if (x > 30)
            x = 30;
    }

    endwin();

    return 0;
}