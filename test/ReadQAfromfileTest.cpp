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
#include "../src/Iofile.h"
#include "../src/Question.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <string> concept, ans;
    vector <Question> question;
    
    string filename_concept = "testfile.txt";
    string filename_ans = "testfile_ans.txt";
    Iofile IO_concept(filename_concept);
    IO_concept.readfile();
    concept = IO_concept.get_info();

    Iofile IO_ans(filename_ans);
    IO_ans.readfile();
    ans = IO_ans.get_info();

    for(int i=0; i<concept.size(); i++)
    {
        Question temp(concept[i], ans[i]);
        question.push_back(temp);
    }

    // output all questions from file
    for(int i=0; i<question.size(); i++)
    {
        cout << "Concept: " << question[i].get_description() << endl;
        cout << "Answer: " << question[i].get_ans() << endl;
    }
    
}