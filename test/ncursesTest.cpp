// using two functions to create or delete ncurses windows 
// and try using up down key to move the windows


#include <ncurses.h>
#include <string>
WINDOW* create_newwin(int height, int width, int starty, int startx);
void destory_win(WINDOW *local_win);
int main()
{
    // //int ch;
    // initscr();
    // raw();
    // //keypad(stdscr, TRUE);
    // noecho();
    
    // std::string str;
    // str = "Just a string!aaaaaaaaaaaaaaaa";
    // const char* mesg = str.c_str();
    // int row,col;

    // getmaxyx(stdscr, row, col);
    // mvprintw(row/2, (col-strlen(mesg))/2, "%s", mesg);
    // mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
    // printw("Try resizing your window(if possible) and then run this program again" );
    // attron(A_REVERSE|A_BLINK);
    // mvaddstr(0,0,"test where it will be!");
    // attroff(A_REVERSE|A_BLINK);// flash show
    // refresh();
    // getch();
    // clear();
    // endwin();

    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    height = 6;
    width = 20;
    getmaxyx(stdscr, height, width);
    starty = (LINES - height)/2;
    starty = (COLS - width)/2;
    printw("Press F1 to exit");
    refresh();
    my_win = create_newwin(height, width, 0, 0);
    while((ch = getch()) != KEY_F(1))
    {
        switch(ch)
        {
            case KEY_LEFT:
                destory_win(my_win);
                my_win = create_newwin(height, width, starty, --startx);
                break;
            case KEY_RIGHT:
                destory_win(my_win);
                my_win = create_newwin(height,width,starty, ++startx);
                break;
            case KEY_UP:
                destory_win(my_win);
                my_win = create_newwin(height,width,--starty,startx);
                break;
            case KEY_DOWN:
                destory_win(my_win);
                my_win = create_newwin(height, width, ++starty, startx);
                break;
        }
    }
    endwin();



    
    

    return 0;
}
WINDOW* create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0); //default start position
    mvwprintw(local_win,1,1,"hello world");
    wrefresh(local_win);
    return local_win;
}

void destory_win(WINDOW *local_win)
{
    wborder(local_win, '|', '|', '-', '-','+', '+', '+', '+');
    wrefresh(local_win);
    delwin(local_win);
}