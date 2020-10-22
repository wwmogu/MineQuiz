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
#include <iostream>
#include "../src/Oop.h"

int main()
{
        initscr();
        string describ_filename = "testfile.txt";
        string ans_filename = "testfile_ans.txt";
        Subject *oop = new Oop(describ_filename, ans_filename);
        //oop->window();
        oop->practice();
        getch();
        endwin();
        return 0;
}