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
#include "../src/Question.h"
#include <iostream>
using namespace std;

int main()
{
        std::cout << "----------Question class test----------" << endl;
        string concept1 = "this is question 1";
        string ans1 = "this is answer for question 1";
        string concept2 = "this is question 2";
        string ans2 = "this is answer for question 2";
        string concept3 = "this is modified quesiton";
        string ans3 = "this is answer for modified question";
        bool test1 = false;
        bool test2 = false;

        {// Question getter test
                std::cout << "-getter test-" << endl;
                Question q1(concept1, ans1);
                if(q1.get_description() == concept1)
                {
                        std::cout << "get description is same" << endl;
                        test1 = true;
                }
                else
                {
                        std::cout << "get description is different" << endl;
                        test1 = false;
                }
                if(q1.get_ans() == ans1)
                {
                        std::cout << "get answer is same" << endl;
                        test1 = true;
                }
                else
                {
                        std::cout << "get answer is different" << endl;
                        test1 = false;
                }
                if(test1)
                {
                        std::cout << "getter test pass" << endl;
                }
                else
                {
                        std::cout << "getter test fail" << endl;
                }
                
                std::cout << "--------------------" << endl;

        }
        if(test1)
        {// Question setter test
                std::cout << "-setter test-" << endl;

                Question q2(concept2, ans2);
                q2.set_description(concept3);
                q2.set_ans(ans3);
                if(q2.get_description() == concept3)
                {
                        std::cout << "description is same" << endl;
                        test2 = true;
                }
                else
                {
                        std::cout << "description is different" << endl;
                        test2 = false;
                }
                if(q2.get_ans() == ans3)
                {
                        std::cout << "answer is same" << endl;
                        test2 = true;
                }
                else
                {
                        std::cout << "answer is different" << endl;
                        test2 = false;
                }
                if(test2)
                {
                        std::cout << "setter test pass" << endl;
                }
                else
                {
                        std::cout << "setter test failed" << endl;
                }
                
                std::cout << "--------------------" << endl;
        }
        if(test1&&test2)
        {
                std::cout << "** Qeustion class test pass **"
                          << endl << endl;
        }
        return 0;
}