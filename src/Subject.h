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
#ifndef SUBJECT_H
#define SUBJECT_H

#include <ncurses.h>    // using ncurses library
#include "Question.h"   // using question vector
#include <vector>       // using vector
#include "Windows.h"    // for user interface
#include "Iofile.h"     // file read and write

using namespace std;

class Subject
{
public:
    // number of subjects 
    static int num_subjects_;

    // default constructor
    Subject();
    // constructor
    Subject(string describ_filename, string ans_filename);

    // ncurses windows of subject
    // set it to be a pure virtual function, 
    // because for different subject title and menu, 
    // they will have different size need to be custimized.
    virtual int window() = 0;   
    
    // practice question can see answer immidiately
    // set it to be a pure virtual function, 
    // because of all practice window will have different tips and one of them will have different function
    virtual void practice() = 0;

    // add one question into question list for a subject all of subjects will have the same function
    void add_question();

    // remove one question from question list for a specific subject
    // set it to be a virtual function
    // because some of rm_question is different
    // for LFS, user will via answer to delete one word not the describtion
    virtual void rm_question();

    //destructor
    virtual ~Subject(); // make it virtual because this is an abstruct class

protected:
    // question list store all question concepts and answers
    vector <Question> question_;
    
    // store cossponding file name.
    string fileneme_;            // this is only for test 
    string ans_filename_;        // for answers filename
    string describ_filename_;    // for question describtion filename

    // heap
    string *title_;              // store the subject title into an array
    string *menu_;               // store the subject menu into an array
    
    // put all windows into the subject, easy to control memory allocation
    Windows * add_questionwin;
    Windows * rm_questionwin;
    Windows * practicewin;
    Windows * win;
};

#endif
