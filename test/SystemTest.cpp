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
// this one is a system test file
// will test all compoent bonded together 

#include "../src/Windows.h"
#include "../src/Oop.h"
#include "../src/Ise.h"
#include "../src/Lfs.h"
int main()
{
        initscr();
        
        std::string content[5] ={
                ",--.   ,--.,--.                    ,-----.           ,--.",
                "|   `.'   |`--',--,--,  ,---.     '  .-.  '  ,--.,--.`--',-----.",
                "|  |'.'|  |,--.|      \\| .-. :    |  | |  |  |  ||  |,--.`-.  /",
                "|  |   |  ||  ||  ||  |\\   --.    '  '-'  '-.'  ''  '|  | /  `-.",
                "`--'   `--'`--'`--''--' `----'     `-----'--' `----' `--'`-----'"
        };
        std::string choices[4] = {
                "1. OOP",
                "2. ISE",
                "3. ENGLISH",
                "4. Exit"
        };
        
        while(true)
        {
                Windows * win;
                win = new Windows;
                /* test main window */
                win->drawmainwin(content, 5, content[1].size());

                /* test menu window */
                int choice = win->menuwin(choices, 4, choices[2].size());
                //int choice = win->get_userchoice();

                switch (choice)
                {
                        case 0: // OOP
                        {        
                                while(true)
                                {
                                        Subject * oop = new Oop("testfile.txt","testfile_ans.txt");
                                        choice = oop->window();
                                
                                        switch(choice)
                                        {
                                                case 0: // practice
                                                        oop->practice();
                                                        //printw("hello world");
                                                        //getch();
                                                        break;
                                                case 1: // add one question
                                                        oop->add_question();
                                                        break;
                                                case 2: // remove one question from question list.
                                                        oop->rm_question();
                                                        break;
                                                default:
                                                        break;
                                        }
                                        if(choice == 3)
                                        {
                                                //delete oop; // when quit the oop delete the oop
                                                break;
                                        }
                                }
                                break;
                        }
                        case 1: // ISE
                        {
                                while(true)
                                {
                                        //create the ISE subject
                                        Subject * ise = new Ise("testfile.txt","testfile_ans.txt");

                                        // get the user input from ISE window
                                        choice = ise->window();
                                
                                        switch(choice)
                                        {
                                                case 0: // practice
                                                        ise->practice();
                                                        break;
                                                case 1: // add one question
                                                        ise->add_question();
                                                        break;
                                                case 2: // remove one question from question list.
                                                        ise->rm_question();
                                                        break;
                                                default:
                                                        break;
                                        }
                                        if(choice == 3)
                                        {
                                                //endwin();
                                                //delete ise; // when quit delete ise
                                                break;
                                        }
                                }    
                                break;
                        }
                        case 2: // LFS
                        {
                                while(true)
                                {
                                        //create the ISE subject
                                        Subject * lfs = new Lfs("testfile.txt","testfile_ans.txt");

                                        // get the user input from ISE window
                                        choice = lfs->window();
                                
                                        switch(choice)
                                        {
                                                case 0: // practice
                                                        lfs->practice();
                                                        break;
                                                case 1: // add one question
                                                        lfs->add_question();
                                                        break;
                                                case 2: // remove one question from question list.
                                                        lfs->rm_question();
                                                        break;
                                                default:
                                                        break;
                                        }
                                        if(choice == 3)
                                        {
                                                //endwin();
                                                //delete ise; // when quit delete ise
                                                break;
                                        }
                                }    
                                break;
                        }                               
                        case 3:
                                endwin();
                                //system("clear");
                                exit(0);
                        default:
                                break;
                }
        }

        endwin();
        return 0;
}