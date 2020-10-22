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

/*
 * This test is for rm_question() function
 * 
 */

#include "../src/Subject.h"
#include "../src/Oop.h"

using namespace std;

int main()
{
    // start ncurses win
    initscr();

    // 1. test list all question with ID functionilty
    Subject *oop = new Oop("testfile.txt","testfile_ans.txt"); // need to free memory
    oop->rm_question();
    getch();
    //end ncurses win
    endwin();
    return 0;
}