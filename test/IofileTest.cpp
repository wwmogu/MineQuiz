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

//unit test for Iofile class

#include "../src/Iofile.h"
#include <iostream>
int main()
{
        std::cout << "--------Iofile class test--------" << std::endl;
        bool flag1 = false, flag2 = false, flag3 = false;
        Iofile *iofile;
        iofile = new Iofile("IofileTest.txt");
        /* test writefile function */
        std::vector<std::string> temp;          // create a vector for test
        temp.push_back("test test test111");
        temp.push_back("test test test222");
        temp.push_back("test test test333");
        

        {// writefile function test
                std::cout << "----writefile function test----" << std::endl;
                iofile->writefile(temp);
                if(system("diff IofileTest.txt IofileTestInput1.txt") == 0) // two files are same
                {
                        std::cout << "** writefile function test pass **" << std::endl;
                        flag1 = true;
                }
                else
                {
                        std::cout << "** writefile function test fail **" << std::endl;
                        flag1 = false;
                }
                std::cout << "--------------------" << endl << endl;
        }
        if(flag1)
        {// readfile and getfile function test
                std::cout << "----readfile function test----" << std::endl;
                iofile->readfile();
                std::vector<std::string> file_info = iofile->get_info();
                bool same = true;
                for(int i=0; i<file_info.size(); i++)
                {
                        if(temp[i] != file_info[i])
                        {
                                same = false;
                        }
                }
                if(same == true)
                {
                        std::cout << "** readfile and getfile function test pass **" << std::endl;
                        flag2 = true;
                }
                else
                {
                        std::cout << "** readfile and getfile function test fail **" << std::endl;
                        flag2 = false;
                }
                std::cout << "--------------------" << endl << endl;
        }
        if(flag1 && flag2)
        {//append function test
                std::cout << "----append function test----" << std::endl;
                std::string line4 = "test test test444";
                iofile->append(line4);
                if(system("diff IofileTest.txt IofileTestInput2.txt") == 0) // two files are same
                {
                        std::cout << "** append function test pass **" << std::endl;
                        flag3 = true;
                }
                else
                {
                        std::cout << "** append function test fail **" << std::endl;
                        flag3 = false;
                }
                std::cout << "--------------------" << endl << endl;
        }
        if(flag1 && flag2 && flag3)
        {
                std::cout << "** Iofile class test pass **"
                          << endl << endl;
        }

        return 0;
}