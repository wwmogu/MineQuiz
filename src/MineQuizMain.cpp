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
#include <iostream> 
#include <ncurses.h>
#include <string>
#include "Subject.h"
#include "Windows.h"
#include "Oop.h"
#include "Ise.h"
#include "Lfs.h"
using namespace std;
extern int editSubject(Subject *subject); // declaration of editSubject

int main()
{
        initscr();
        start_color();
        
        // this one will store three different subjects
        Subject *subject[3];

        // the main windows title
        std::string content[5] ={
                ",--.   ,--.,--.                    ,-----.           ,--.",
                "|   `.'   |`--',--,--,  ,---.     '  .-.  '  ,--.,--.`--',-----.",
                "|  |'.'|  |,--.|      \\| .-. :    |  | |  |  |  ||  |,--.`-.  /",
                "|  |   |  ||  ||  ||  |\\   --.    '  '-'  '-.'  ''  '|  | /  `-.",
                "`--'   `--'`--'`--''--' `----'     `-----'--' `----' `--'`-----'"
        };
        // the menu windows choice
        std::string choices[4] = {
                "Object-oriented-prog",
                "Intro to Software-Eng",
                "Language for study",
                "Exit the Program"
        };
        // user prompt or welcome
        std::string welcome = "It's time to challenge yourself !"; // 34
        std::string prompt = "ARROW KEYS: move the cursor    ENTER KEY: confirm your selection.";

        // strings for subjects filename
        std::string oopFile_D = "../txt/Oop_D.txt";
        std::string oopFile_A = "../txt/Oop_A.txt";
        std::string iseFile_D = "../txt/Ise_D.txt";
        std::string iseFile_A = "../txt/Ise_A.txt";
        std::string lfsFile_D = "../txt/Lfs_D.txt";
        std::string lfsFile_A = "../txt/Lfs_A.txt";

        // initialize three subjects
        subject[0] = new Oop(oopFile_D,oopFile_A);
        subject[1] = new Ise(iseFile_D,iseFile_A);
        subject[2] = new Lfs(lfsFile_D,lfsFile_A);
        
        while(true)
        {
                Windows * win;
                win = new Windows;
                /* test main window */
                win->drawmainwin(content, 5, content[1].size());

                // main window welcome
                mvwprintw(win->getwin(), LINES/2-2, (COLS-9)/2, "Welcome !");
                wattron(win->getwin(),A_BLINK);
                mvwprintw(win->getwin(), LINES/2-1, (COLS-welcome.size())/2, "%s", welcome.c_str());
                wattroff(win->getwin(),A_BLINK);
                
                // main window help prompt
                wattron(win->getwin(),A_STANDOUT|A_BOLD);
                mvwprintw(win->getwin(), LINES-2, (COLS-prompt.size())/2, "%s", prompt.c_str());
                wattroff(win->getwin(),A_STANDOUT|A_BOLD);
                
                //  refresh win output the buffer
                wrefresh(win->getwin());

                /* menu window */
                int choice = win->menuwin(choices, 4, choices[1].size());
                
                

                switch (choice)
                {
                        case 0: // OOP
                        {        
                                choice = editSubject(subject[0]); // OOP subject
                                break;
                        }
                        case 1: // ISE
                        {
                                choice = editSubject(subject[1]); // Ise subject    
                                break;
                        }
                        case 2: // LFS
                        {
                                choice = editSubject(subject[2]); // LFS subject
                                break;
                        }
                        case 3: // exit the program
                        {   

                                endwin();
                                for(int i=0; i<3; i++)
                                {
                                        delete subject[i];
                                }
                                exit(0);
                        }
                        default:
                                break;
                }
        }
        return 0;
}

