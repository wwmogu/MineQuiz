/*                                                                               
 ,-----.  ,-----. ,------.                           ,--.               ,--.   
'  .-.  ''  .-.  '|  .--. '     ,---. ,--.--. ,---.  `--' ,---.  ,---.,-'  '-. 
|  | |  ||  | |  ||  '--' |    | .-. ||  .--'| .-. | ,--.| .-. :| .--''-.  .-' 
'  '-'  ''  '-'  '|  | --'     | '-' '|  |   ' '-' ' |  |\   --.\ `--.  |  |   
 `-----'  `-----' `--'         |  |-' `--'    `---'.-'  / `----' `---'  `--'   
,------.                       `--'                '---'                       
|  .-.  \  ,---. ,--,--,  ,---.     ,--.   ,--. ,--,--.,--,--,  ,---.          
|  |  \  :| .-. ||      \| .-. |    |  |.'.|  |' ,-.  ||      \| .-. |         
|  '--'  /' '-' '|  ||  |' '-' '    |   .'.   |\ '-'  ||  ||  |' '-' '         
`-------'  `---' `--''--'.`-  /     '--'   '--' `--`--'`--''--'.`-  /          
                         `---'                                 `---'           
*/

#include "Windows.h"

/* create a window */
Windows::Windows()
{  
    this->input_ = NULL;
    this->menu_ = NULL;

    int height, width, starty, startx;
    getmaxyx(stdscr,maxy_,maxx_);
    height = maxy_;
    width = maxx_;
    starty = startx = 0;
    refresh();
    this->win_ = newwin(height, width, starty, startx);
    box(win_, 0, 0);
    wrefresh(win_);
}

WINDOW * Windows::getwin()
{
    return win_;
}

/* draw main window */
void Windows::drawmainwin(std::string *content, int num_content, int maxlen)
{
    wattron(win_, A_BOLD);
    for (int i=0; i<num_content; i++)
    {
        mvwprintw(win_, i+1, COLS/2-maxlen/2,"%s",content[i].c_str());
    }
    wattroff(win_, A_BOLD);
    wrefresh(win_);
}

/*  menu window */
// a window inside the main window that support user using up and down key to move "curses"
int Windows::menuwin(std::string *choices, int num_content, int maxlen)
{
    // hide cursor
    curs_set(0);
    // hide user type
    noecho();
    refresh();
    // customize the menu size
    this->menu_ = newwin(6,40,maxy_-8,maxx_/2-20);
    keypad(this->menu_, true);
    box(this->menu_, 0, 0);
    wrefresh(this->menu_);

    // using up and down key to move curses
    int choice;
    int highlight = 0;
    while(true)
    {
        for(int i=0; i<num_content; i++)
        {
            if(i==highlight)
            {
                wattron(this->menu_, A_REVERSE);
            }
            mvwprintw(this->menu_, i+1, 1, choices[i].c_str());
            wattroff(this->menu_, A_REVERSE);
        }
        choice = wgetch(this->menu_);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == num_content)
                {
                    highlight = num_content-1;
                }
                break;
            default:
                break;
        }
        if(choice == 10)        // 10 -> ascii -> enter key
        {
            break;
        }   
    }
    return highlight;
}

std::string Windows::inputwin()
{
    echo();
    curs_set(1);
    refresh();
    // customize the input window size
    this->input_ = newwin(7,60,maxy_-8,maxx_/2-30);
    box(this->input_, 0, 0);
    wrefresh(this->input_);
    std::string str; 
    int r=1;    // row that current character print in this win
    int c=1;    // column position that current character print in this win
    int ch = -99; 

    while(ch != '\n')
    {
        box(this->input_, 0, 0);
        wrefresh(this->input_);
        ch = mvwgetch(this->input_,r,c);
        // this part is for user enter delete key
        while(ch == 127) // 127 - delete key 
        {
            box(this->input_, 0, 0);
            wrefresh(this->input_);
            if(c==1 && r==1) // current curses positon is at the beginning of first line
            {
                mvwprintw(this->input_,r,c," "); // make current character shown become white space
                wrefresh(this->input_);
            }
            // 
            else if((r!=1) && (c==1)) // current curses position is at the beginning of other line
            {
                mvwprintw(this->input_,r,c+1," ");
                r--;
                mvwprintw(this->input_,r+1,1," ");
                c=59;
                wrefresh(this->input_);
                c--;
                ch = mvwgetch(this->input_,r,c);
                mvwprintw(this->input_,r,c," ");
                mvwprintw(this->input_,r,c+1," ");
                mvwprintw(this->input_,r,c+2," ");
                wrefresh(this->input_);
                str.pop_back();
                str.pop_back();
                c--;
                break;      
            }
            else
            {
                // make current character and previous character shown becom white space
                mvwprintw(this->input_,r,c," "); 
                mvwprintw(this->input_,r,c-1," ");
                box(this->input_, 0, 0);
                wrefresh(this->input_);
                str.pop_back();
                c--;
            }
            mvwprintw(this->input_,r,c+1," "); // remove '^'
            mvwprintw(this->input_,r,c+2," "); // remove '?'
            box(this->input_, 0, 0);
            wrefresh(this->input_);

            ch = mvwgetch(this->input_,r,c);
        }
        c++;    // increment current column positon

        // add current character to the string
        str.push_back(ch);

        // this part is for bound, prevent the user input not out that input window
        if(c==59)
        {
            r++;
            c=1;
        }

    }
    str.pop_back(); // remove the last "\n" from the str
    return str;
}

/* delete a window */
Windows::~Windows()
{
    delwin(this->win_);
    if(this->menu_ != NULL)
    {
        delwin(this->menu_);
    }
    if(this->input_ != NULL)
    {
        delwin(this->input_);
    }
    
}
