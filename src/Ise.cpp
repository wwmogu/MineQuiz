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
#include "Ise.h"

Ise::Ise(string describ_filename, string ans_filename) : Subject(describ_filename, ans_filename)
{
    // read in the question
    Iofile describtion(this->describ_filename_);
    describtion.readfile();
    Iofile answer(this->ans_filename_);
    answer.readfile();
    // store them into two vectors
    vector<string> tempD = describtion.get_info();
    vector<string> tempA = answer.get_info();
    // make questions
    for(int i=0; i<tempD.size(); i++)
    {
        Question tempQ(tempD[i], tempA[i]);
        this->question_.push_back(tempQ);
    }

    // the Ise's title and menu
    string title[7] = {
        "::::::::::: ::::::::  ::::::::::",                                                                  
        "    :+:    :+:    :+: :+:       ",                                                                  
        "    +:+    +:+        +:+       ",                                                                  
        "    +#+    +#++:++#++ +#++:++#  ",                                                                  
        "    +#+           +#+ +#+       ",                                                                  
        "    #+#    #+#    #+# #+#       ",                                                                  
        "########### ########  ##########"                                                                  
    };
    string menu[4] = {
        "Practice",
        "Add one question",
        "Delete one quesiton",
        "back to main window"
    };
    // assign the title to this class's own title and menu
    this->title_ = new string[7];
    for(int i=0; i<7; i++)
    {
        this->title_[i] = title[i];
    }
    this->menu_ = new string[4];
    for(int i=0; i<4; i++)
    {
        this->menu_[i] = menu[i];
    } 
}

int Ise::window()
{
    // prevent memory lack
    if(win != NULL)
    {
        delete win;
    }
    // create a new window for ISE
    win = new Windows;

    // ISE introduction
    string intro1 = "For Introduction to software engineering.";
    string intro2 = "The practice session is a flashcard game.";
    mvwprintw(win->getwin(), LINES/2-1, (COLS-intro1.size())/2, "%s", intro1.c_str());
    mvwprintw(win->getwin(), LINES/2, (COLS-intro2.size())/2, "%s", intro2.c_str());

    // set the title
    win->drawmainwin(this->title_, 7, this->title_[0].size());

    // user prompt
    string prompt = "ARROW KEYS: move the cursor    ENTER KEY: confirm your selection.";
    wattron(win->getwin(),A_REVERSE|A_BOLD);
    mvwprintw(win->getwin(), LINES-2, (COLS-prompt.size())/2, "%s", prompt.c_str());
    wattroff(win->getwin(),A_REVERSE|A_BOLD);
    wrefresh(win->getwin());

    // get the user choice form menu
    int mode = win->menuwin(this->menu_, 4, this->menu_[3].size());
    return mode;

}

void Ise::practice()
{
    // prevent memory lack
    if(practicewin != NULL)
    {
        delete practicewin;
    }
    // create a new window for practice function
    practicewin = new Windows;
    // loop all of ISE questions
    for(int i=0; i<this->question_.size(); i++)
    {
        // color pair
        start_color();
        init_pair(1, COLOR_YELLOW,COLOR_BLACK);
        init_pair(2, COLOR_BLACK,COLOR_YELLOW);

        // user help and tips
        string keyhelp = "J:describtion    K:next    B:back    N:answer    Q:exit"; 
        string welcome = "Here's the Intro to software engineer course flashcard!";
        string tip1 = "Quick look at all the questions.";
        string tip2 = "And if you really can't remember, check out the answers.";
        string tip3 = "You are checking answer now !";
        
        // implement practice function
        int c;                          // a variable store the user choice;
        noecho();                       // do not show the user input on the screen
        delete practicewin;             // each time delete the old window
        practicewin = new Windows;      // and rebuilt it

        // store the ith question in the buffer screen
        wattron(practicewin->getwin(),COLOR_PAIR(1));
        mvwprintw(practicewin->getwin(),LINES/2,(COLS-question_[i].get_description().size())/2, this->question_[i].get_description().c_str());
        wattroff(practicewin->getwin(),COLOR_PAIR(1));

        // store the user help and tips in the buffer screen
        // the user help with the color which is reverse the initial color
        wattron(practicewin->getwin(),A_REVERSE);
        mvwprintw(practicewin->getwin(),LINES-2,(COLS-keyhelp.size())/2,keyhelp.c_str());
        wattroff(practicewin->getwin(),A_REVERSE);
        mvwprintw(practicewin->getwin(),1,(COLS-welcome.size())/2,welcome.c_str());
        mvwprintw(practicewin->getwin(),3,(COLS-tip1.size())/2,tip1.c_str());
        mvwprintw(practicewin->getwin(),4,(COLS-tip2.size())/2,tip2.c_str());

        // refresh the practice window, let the buffer print on the screen
        wrefresh(practicewin->getwin());

        // waiting the user input
        while(true)
        {
            c = getch();                // gech() return an integer value
            if(c == (int)'j')           // press j for question describtion
            {
                // delete old windows and rebuilt it with new questions
                delete practicewin;
                practicewin = new Windows;
                wattron(practicewin->getwin(),COLOR_PAIR(1));
                mvwprintw(practicewin->getwin(),LINES/2,(COLS-question_[i].get_description().size())/2, this->question_[i].get_description().c_str());
                wattroff(practicewin->getwin(),COLOR_PAIR(1));

                // user help and tips
                wattron(practicewin->getwin(),A_REVERSE);
                mvwprintw(practicewin->getwin(),LINES-2,(COLS-keyhelp.size())/2,keyhelp.c_str());
                wattroff(practicewin->getwin(),A_REVERSE);
                mvwprintw(practicewin->getwin(),1,(COLS-welcome.size())/2,welcome.c_str());
                mvwprintw(practicewin->getwin(),3,(COLS-tip1.size())/2,tip1.c_str());
                mvwprintw(practicewin->getwin(),4,(COLS-tip2.size())/2,tip2.c_str());
            }
            else if(c == (int)'n')      // press n to see the question answer
            {
                // repet the steps in the previous if statement
                delete practicewin;
                practicewin = new Windows;
                
                // but this time the answer will show with in bold.
                wattron(practicewin->getwin(), COLOR_PAIR(2));
                mvwprintw(practicewin->getwin(),LINES/2,(COLS-question_[i].get_ans().size())/2, this->question_[i].get_ans().c_str());
                wattroff(practicewin->getwin(), COLOR_PAIR(2));

                // user help and tips
                wattron(practicewin->getwin(),A_REVERSE);
                mvwprintw(practicewin->getwin(),LINES-2,(COLS-keyhelp.size())/2,keyhelp.c_str());
                wattroff(practicewin->getwin(),A_REVERSE);
                mvwprintw(practicewin->getwin(),4,(COLS-tip3.size())/2,tip3.c_str());
            }
            else if(c == (int)'b')      // press b back to the privious question describtion
            {
                if(i==0)                // when user at the first question, press b will back to the last one
                {
                    i = question_.size()-2; // now i is equal to length-1 but next loop will add 1, so need length - 2
                }
                else
                {
                    i=i-2;              // descrease index by 2, since the index is added one when it go into the for loop
                }
                break;
            }
            else if((c == (int)'k') || (c == (int)'q')) // press k to next question describtion
            {
                break;
            }

            // after if statements refresh the windows print the buffer on the screen
            wrefresh(practicewin->getwin());
        }

        // if the user input is q, exit the practice function
        if(c == (int)'q')
        {
            break;
        }
        // make sure when user goto the last question, back to the first one
        if(i == question_.size()-1)
        {
            i = -1;             // since the next loop i will ++ so,-1+1 = 0;
        }
    }
}

Ise::~Ise()
{
    // moved to subject class   
}
