// test how ncurses windows works

#include <ncurses.h>

WINDOW* create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0); //default start position
    wrefresh(local_win);
    return local_win;
}

void destory_win(WINDOW *local_win)
{
    wborder(local_win, '*', '*', '*', '*','*', '*', '*', '*');
    wrefresh(local_win);
    delwin(local_win);
}