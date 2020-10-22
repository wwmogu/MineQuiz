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
#include "Subject.h"

// static variable
int Subject::num_subjects_ = 0;

// default constructor
Subject::Subject()
{
    Subject::num_subjects_++;
    add_questionwin = NULL;
    rm_questionwin = NULL;
    practicewin = NULL;
    win = NULL;
}

// constructor
Subject::Subject(string describ_filename, string ans_filename)
{
    this->describ_filename_ = describ_filename;
    this->ans_filename_ = ans_filename;
    add_questionwin = NULL;
    rm_questionwin = NULL;
    practicewin = NULL;
    win = NULL;
    Subject::num_subjects_++;
}

// add one question into question list for a subject all of subjects will have the same function
void Subject::add_question()
{
    start_color();
    init_pair(1, COLOR_BLACK,COLOR_RED);

    // prevent memory leck
    if(add_questionwin != NULL)
    {
        delete add_questionwin;
    }
    // create a new windows for addquestion function
    add_questionwin = new Windows;

    echo();
    string describtion_prompt = "Enter the question description you want to add: ";
    string ans_prompt = "Enter the corresponding answer: ";
    string exit_prompt = "type 'exit it' to exit this window";

    // creat two "string" for question
    string describtion_str, ans_str;
    mvwprintw(add_questionwin->getwin(), LINES/2-2, (COLS-describtion_prompt.size())/2, describtion_prompt.c_str()); // show the user prompt
    wattron(add_questionwin->getwin(), COLOR_PAIR(1));
    mvwprintw(add_questionwin->getwin(), LINES/2-1, (COLS-exit_prompt.size())/2, exit_prompt.c_str()); // show the user prompt   
    wattroff(add_questionwin->getwin(), COLOR_PAIR(1)); 
    wrefresh(add_questionwin->getwin());

    // create a input window get the user input of question describtion
    describtion_str = add_questionwin->inputwin();
    
    // exit the add_question
    if(describtion_str == "exit it")
    {
        return;
    }

    // delete add_question window, then create a new window for user input of question answer
    delete add_questionwin;
    add_questionwin = new Windows;
    mvwprintw(add_questionwin->getwin(), LINES/2-2, (COLS-ans_prompt.size())/2, ans_prompt.c_str());
    wattron(add_questionwin->getwin(), COLOR_PAIR(1));
    mvwprintw(add_questionwin->getwin(), LINES/2-1, (COLS-exit_prompt.size())/2, exit_prompt.c_str()); // show the user prompt   
    wattroff(add_questionwin->getwin(), COLOR_PAIR(1)); 
    wrefresh(add_questionwin->getwin());

    ans_str = add_questionwin->inputwin();      //get user input

    // exit the add_question
    if(ans_str == "exit it")
    {
        return;
    }

    // store the user input into question vector
    Question question(describtion_str, ans_str);
    this->question_.push_back(question);

    // update the cossponding file by appding new questions
    Iofile describtion(this->describ_filename_);
    Iofile ans(this->ans_filename_);
    describtion.append(question.get_description());
    ans.append(question.get_ans());
}

// remove one question from question list for a specific subject
void Subject::rm_question()
{
    start_color();
    init_pair(1, COLOR_BLACK,COLOR_RED);

    //prevent memory leck
    if(rm_questionwin != NULL)
    {
        delete rm_questionwin;
    }
    // 1. list all questions with ID which is the index of the vector
    // create a window to show questions
    rm_questionwin = new Windows;

    // print all question on the screen
    for(int i=0; i<this->question_.size(); i++)
    {
        mvwprintw(rm_questionwin->getwin(), i+1, 1, "%d:",i+1);
        mvwprintw(rm_questionwin->getwin(), i+1, 5, this->question_[i].get_description().c_str());
    }
    string exit_prompt = "type 'exit it' to exit this window";
    wattron(rm_questionwin->getwin(), COLOR_PAIR(1));
    mvwprintw(rm_questionwin->getwin(), LINES-9, (COLS-exit_prompt.size())/2, exit_prompt.c_str()); // show the exit prompt 
    wattroff(rm_questionwin->getwin(), COLOR_PAIR(1)); 
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
    // not a number 1-10
    if (!(atoi(str_input.c_str()) >=1 && atoi(str_input.c_str())<=10)){
        string fault_prompt = "please type correct ID";
        wattron(rm_questionwin->getwin(), COLOR_PAIR(1));
        mvwprintw(rm_questionwin->getwin(), LINES-10, (COLS-fault_prompt.size())/2, fault_prompt.c_str()); // show the fault prompt 
        wattroff(rm_questionwin->getwin(), COLOR_PAIR(1)); 
        wrefresh(rm_questionwin->getwin());
        getch();
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

// destructor
Subject::~Subject()
{
    if(add_questionwin != NULL)
    {
        delete add_questionwin;
    }
    if(rm_questionwin != NULL)
    {
        delete rm_questionwin;
    }
    if(win != NULL)
    {
        delete win;
    }
    if(practicewin != NULL)
    {
        delete practicewin;
    }
    delete[] this->title_;
    delete[] this->menu_; 
}