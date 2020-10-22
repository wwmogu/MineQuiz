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
#include "Lfs.h"

Lfs::Lfs(string describ_filename, string ans_filename) : Subject(describ_filename, ans_filename)
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

    // the LFS's title and menu
    string title[7] = {
        ":::        :::::::::: :::::::: ",                                                                   
        ":+:        :+:       :+:    :+:",                                                                   
        "+:+        +:+       +:+       ",                                                                   
        "+#+        :#::+::#  +#++:++#++",                                                                   
        "+#+        +#+              +#+",                                                                   
        "#+#        #+#       #+#    #+#",                                                                   
        "########## ###        ######## "                                                                 
    };
    string menu[4] = {
        "Practice",
        "Add one Word",
        "Delete one Word",
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

int Lfs::window()
{
    // prevent memory lack
    if(win != NULL)
    {
        delete win;
    }
    // create a new window for LFS
    win = new Windows;

    // set the title
    win->drawmainwin(this->title_, 7, this->title_[1].size());

    // LFS introduction
    string intro1 = "For Language for study.";
    string intro2 = "The practice session is a vacabulray test.";
    mvwprintw(win->getwin(), LINES/2-1, (COLS-intro1.size())/2, "%s", intro1.c_str());
    mvwprintw(win->getwin(), LINES/2, (COLS-intro2.size())/2, "%s", intro2.c_str());

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

void Lfs::practice()
{
    string word;        // store the user input;
    int check=0, cnt=0; // check for two times try, cnt for number of fault
    
    // prevent memory lack
    if(practicewin != NULL)
    {
        delete practicewin;
    }
    // create a new window for practice function
    practicewin = new Windows;
    refresh();
    // loop all of LFS questions
    for(int i=0; i<this->question_.size(); i++)
    {
        // color pair
        start_color();
        init_pair(1, COLOR_BLACK,COLOR_YELLOW);
        init_pair(2,COLOR_BLACK,COLOR_RED);

        // user tips and welcome
        string welcome = "Here's the Language for study course flashcard!";
        string tip1 = "There is the defination of the word !";
        string tip2 = "Type in the word, that you memorized.";
        string tip3 = "If correct, will jump to next word.";
        string tip4 = "If incorrect, you have 2 times to try, then jump to next word.";    

        // implement practice function
        int c;                          // a variable store the user choice;
        echo();                       // show the user input on the screen
        delete practicewin;             // each time delete the old window
        practicewin = new Windows;      // and rebuilt it
        refresh();

        // user help and tips
        mvwprintw(practicewin->getwin(),1,(COLS-welcome.size())/2,welcome.c_str());
        mvwprintw(practicewin->getwin(),2,(COLS-tip1.size())/2,tip1.c_str());
        mvwprintw(practicewin->getwin(),3,(COLS-tip2.size())/2,tip2.c_str());
        mvwprintw(practicewin->getwin(),4,(COLS-tip3.size())/2,tip3.c_str());
        mvwprintw(practicewin->getwin(),5,(COLS-tip4.size())/2,tip4.c_str());
        wrefresh(practicewin->getwin());

        check = 1;
        while(true)
        {
            // show the word defination
            wattron(practicewin->getwin(),COLOR_PAIR(1));
            mvwprintw(practicewin->getwin(),LINES/2,(COLS-question_[i].get_description().size())/2, this->question_[i].get_description().c_str());
            wattroff(practicewin->getwin(),COLOR_PAIR(1));
            wrefresh(practicewin->getwin());
            
            // get the user input
            word = practicewin->inputwin();
            wrefresh(practicewin->getwin());

            // the word test logic
            if(word == "exit it") // type "exit it" to exit the program
            {
                break;
            }
            else if(word == question_[i].get_ans() && check < 2) // correct
            {
                break;
            }
            else if(check == 2) // when the user type wrong 2 times
            {
                wattron(practicewin->getwin(),COLOR_PAIR(2));
                mvwprintw(practicewin->getwin(), LINES/2+1,(COLS-question_[i].get_ans().size())/2, this->question_[i].get_ans().c_str());
                wattroff(practicewin->getwin(),COLOR_PAIR(2));
                wrefresh(practicewin->getwin());
                getch();
                break;
            }
            else    // count the wrong times.
            {
                cnt++;
                check++;
            }
            
        }
        if(word == "exit it")
        {
            break;
        }

    }
}

// remove one word from word list this one will show the word which is answer
void Lfs::rm_question()
{
    start_color();
    init_pair(1, COLOR_BLACK,COLOR_RED);
    
    //prevent memory lack
    if(rm_questionwin != NULL)
    {
        delete rm_questionwin;
    }
    // 1. list all answers with ID which is the index of the vector
    // create a window to show questions
    rm_questionwin = new Windows;
    // print all question on the screen
    for(int i=0; i<this->question_.size(); i++)
    {
        mvwprintw(rm_questionwin->getwin(), i+1, 1, "%d:",i+1);
        mvwprintw(rm_questionwin->getwin(), i+1, 5, this->question_[i].get_ans().c_str());
    }
    string exit_prompt = "type 'exit it' to exit this window";
    wattron(rm_questionwin->getwin(), COLOR_PAIR(1));
    mvwprintw(rm_questionwin->getwin(), LINES-9, (COLS-exit_prompt.size())/2, exit_prompt.c_str()); // show the exit prompt 
    wattroff(rm_questionwin->getwin(), COLOR_PAIR(1)); 
    // mvwpritw((7,60,maxy_-8,maxx_/2-30);
    wrefresh(rm_questionwin->getwin());
    
    // 2. choose the ID that user want to remove
    // create a input win for user input
    string str_input = rm_questionwin->inputwin();
    wrefresh(rm_questionwin->getwin());

    // new features, exit the re_question
    if(str_input == "exit it")
    {
        return;
    }
    
    // cast the string input to integer;
    int input = stoi(str_input)-1; // minus one for real index
    // delete the corrdinate question in the question vector
    if(input == question_.size()-1)// remove the last element 
    {
        question_.pop_back(); // O(1)
    }
    else// remove other element
    {    
        question_.erase(question_.begin() + input); // O(n)
    }

    // 3. update the corrdinate file by rewriting the whole file
    // read the removed question vector into two seprate vector
    vector <string> describtions, ans;
    for(int i=0; i<question_.size(); i++)
    {
        describtions.push_back(question_[i].get_description());
        ans.push_back(question_[i].get_ans()); // mistake here//
    }
    // rewriting describtion file
    Iofile rewriting_describtion(this->describ_filename_);
    rewriting_describtion.writefile(describtions);  
    // rewriting answer file
    Iofile rewriting_ans(this->ans_filename_);
    rewriting_ans.writefile(ans);
}

Lfs::~Lfs()
{
    // moved to subject class  
}
