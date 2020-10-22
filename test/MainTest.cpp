/*
___________              __      _____.__.__                      
\__    ___/___   _______/  |_  _/ ____\__|  |   ____              
  |    |_/ __ \ /  ___/\   __\ \   __\|  |  | _/ __ \             
  |    |\  ___/ \___ \  |  |    |  |  |  |  |_\  ___/             
  |____| \___  >____  > |__|    |__|  |__|____/\___  >            
             \/     \/                             \/             
________                                                          
\______ \   ____   ____    ____   __  _  _______    ____    ____  
 |    |  \ /  _ \ /    \  / ___\  \ \/ \/ /\__  \  /    \  / ___\ 
 |    `   (  <_> )   |  \/ /_/  >  \     /  / __ \|   |  \/ /_/  >
/_______  /\____/|___|  /\___  /    \/\_/  (____  /___|  /\___  / 
        \/            \//_____/                 \/     \//_____/  
*/
// this is a prototype does not have any function, just have the interface
#include "../src/Oop.h"
#include <ncurses.h>
extern WINDOW* create_newwin(int height, int width, int starty, int startx);
extern void destory_win(WINDOW *local_win);

int main()
{
        /* start ncurses window */
        initscr();
        //raw();
        cbreak();
        noecho(); // do not display the user input
        keypad(stdscr, true); // allow any key 
        
        int startx, starty, height, width;
        getmaxyx(stdscr,height, width);
        startx = 0;
        starty = 0;
        WINDOW  *win;
        WINDOW  *menu;
        int user = -1;
        while(user != KEY_F(1))
        {

                
                refresh();
                win = create_newwin(height, width, starty, startx);
                wattron(win,A_BOLD);
                mvwprintw(win,1,width/2-33,",--.   ,--.,--.                    ,-----.           ,--.");        
                mvwprintw(win,2,width/2-33,"|   `.'   |`--',--,--,  ,---.     '  .-.  '  ,--.,--.`--',-----."); 
                mvwprintw(win,3,width/2-33,"|  |'.'|  |,--.|      \\| .-. :    |  | |  |  |  ||  |,--.`-.  /");  
                mvwprintw(win,4,width/2-33,"|  |   |  ||  ||  ||  |\\   --.    '  '-'  '-.'  ''  '|  | /  `-."); 
                mvwprintw(win,5,width/2-33,"`--'   `--'`--'`--''--' `----'     `-----'--' `----' `--'`-----'"); 
                wattron(win,A_BOLD);
                mvwprintw(win,height/2-1,width/2-19,"Select One Subject to Start Learning!");
                
                wrefresh(win);
                
                menu = create_newwin(7,60,height-8,width/2-30); // height width, positionY, positionX
                wattron(menu,A_BOLD);
                mvwprintw(menu,1,1,"a: Object-Oriented-Program");
                mvwprintw(menu,2,1,"b: Language-For-Study");
                mvwprintw(menu,3,1,"c: Intro-Software-Engineering");
                wattroff(menu,A_BOLD);
                wrefresh(menu);
                

                 
                user = getch();
                switch(user)
                {
                        case 'a':
                        {
                                while(user != KEY_F(2))
                                {
                                //destory_win(menu);
                                //destory_win(win);
                                //refresh();
                                //win = create_newwin(height, width, starty, startx);
                                Oop *oop = new Oop("testfile.txt","testfile_ans.txt");
                                oop->window();
                                // menu = create_newwin(7,60,height-8,width/2-30);
                                // box(menu,0,0);
                                //wrefresh(win);
                                //user = -1;                                
                                
                                        user = getch();
                                        switch(user)
                                        {
                                                case 'a':
                                                        clear();
                                                        refresh();
                                                        oop -> practice();
                                                        refresh();
                                                        getch();
                                                        break;
                                                default:
                                                        break;
                                        }
                                        
                                }
                                
                                //getch();
                                break;
                        }
                        case 2:
                                break;
                        case 3:
                                break;
                        default:
                                break;
                }
        }
        delwin(win);
        delwin(menu);
        /*end ncurses window */
        endwin();
        return 0;
}