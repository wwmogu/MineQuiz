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
#include "Oop.h"
#include <iostream> // for test output

// implement Oop constructor
Oop::Oop(string describ_filename, string ans_filename) : Subject(describ_filename, ans_filename)
{
    // get info from each file
    Iofile describtion(this->describ_filename_);
    describtion.readfile();
    Iofile answer(this->ans_filename_);
    answer.readfile();
    // store the describtion and answer into the Question vector
    vector<string> tempD = describtion.get_info();
    vector<string> tempA = answer.get_info();
    for(int i=0; i<tempD.size(); i++)
    {
        Question tempQ(tempD[i],tempA[i]);
        this->question_.push_back(tempQ);
    }

    // OOP title, menu, prompt 
    string temp[7] = {
        " ::::::::   ::::::::  :::::::::",
        ":+:    :+: :+:    :+: :+:    :+:",
        "+:+    +:+ +:+    +:+ +:+    +:+",
        "+#+    +:+ +#+    +:+ +#++:++#+",
        "+#+    +#+ +#+    +#+ +#+",
        "#+#    #+# #+#    #+# #+#",
        " ########   ########  ###"
    };
    string menu[4] = {
        "Practice",
        "Add one question",
        "Delete one quesiton",
        "back to main window"
    };
    
    this->title_ = new string[7];
    for(int i=0; i<7; i++)
    {
        this->title_[i] = temp[i];
    }
    this->menu_ = new string[4];
    for(int i=0; i<4; i++)
    {
        this->menu_[i] = menu[i];
    } 
}

int Oop::window()
{
    // prevent memory lack
    if(win != NULL)
    {
        delete win;
    }
    win = new Windows; 
    //refresh();
    win->drawmainwin(this->title_, 7, this->title_[2].size()); // the maxium length is third line,
    
    //OOP introduction
    string intro1 = "For Object oriented programming.";
    string intro2 = "The practice session is a flashcard game.";
    mvwprintw(win->getwin(), LINES/2-1, (COLS-intro1.size())/2, "%s", intro1.c_str());
    mvwprintw(win->getwin(), LINES/2, (COLS-intro2.size())/2, "%s", intro2.c_str());
    
    // user prompt
    string prompt = "ARROW KEYS: move the cursor    ENTER KEY: confirm your selection.";
    wattron(win->getwin(),A_REVERSE|A_BOLD);
    mvwprintw(win->getwin(), LINES-2, (COLS-prompt.size())/2, "%s", prompt.c_str());
    wattroff(win->getwin(),A_REVERSE|A_BOLD);
    wrefresh(win->getwin());

    // get the user choice which is mode in menu window
    int mode = win->menuwin(this->menu_, 4, this->menu_[3].size()); // the maxium length is 4th line
    return mode;
}

// flash card 
void Oop::practice()
{
    // prevent memory lack
    if(practicewin != NULL)
    {
        delete practicewin;
    }
    // create new windows for practice
    practicewin = new Windows;

    for(int i=0; i<this->question_.size(); i++)
    {
        // color pair
        start_color();
        init_pair(1, COLOR_YELLOW,COLOR_BLACK);
        init_pair(2, COLOR_BLACK,COLOR_YELLOW);

        // user help and tips
        string keyhelp = "J:describtion    K:next    B:back    N:answer    Q:exit"; 
        string welcome = "Here's the Object oriented programming course flashcard!";
        string tip1 = "Quick look at all the questions.";
        string tip2 = "And if you really can't remember, check out the answers.";
        string tip3 = "You are checking answer now !";

        int c;     // store the user keychoice
        noecho(); // do not show the user input

        // every time the user see a new question, will rebuild the window with prompt
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

        wrefresh(practicewin->getwin());
        while(true)
        {
            c = getch();
            if(c == (int)'j')   // press j to see question describtion
            {
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
            else if(c == (int)'n') // press n to see the answer
            {
                delete practicewin;
                practicewin = new Windows;
                
                wattron(practicewin->getwin(), COLOR_PAIR(2));
                mvwprintw(practicewin->getwin(),LINES/2,(COLS-question_[i].get_ans().size())/2, this->question_[i].get_ans().c_str());
                wattroff(practicewin->getwin(), COLOR_PAIR(2));

                // user help
                wattron(practicewin->getwin(),A_REVERSE);
                mvwprintw(practicewin->getwin(),LINES-2,(COLS-keyhelp.size())/2,keyhelp.c_str());
                wattroff(practicewin->getwin(),A_REVERSE);
                mvwprintw(practicewin->getwin(),4,(COLS-tip3.size())/2,tip3.c_str());
            }
            else if(c == (int)'b')  
            {
                if(i==0) // when user at the first question, press b will back to the last one
                {
                    i = question_.size()-2; // now i is equal to length-1 but next loop will add 1, so need length - 2
                }
                else
                {
                    i=i-2;    
                }
                break;
            }
            else if((c == (int)'k') || (c == (int)'q')) // press k to next question
            {
                break;
            }
            wrefresh(practicewin->getwin());
        }
        // exit practice
        if(c == (int)'q')
        {
            break;
        }
        // make sure when user goto the last question, back to the first one
        if(i == question_.size()-1)
        {
            i = -1; // since the next loop i will ++ so,-1+1 = 0;
        }
    }
    
    
}

// destructor
Oop::~Oop()
{
    // moved to subject class  
}