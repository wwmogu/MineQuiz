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
#ifndef IOFILE_H
#define IOFILE_H
#include <string>
#include <fstream>
#include <vector>
#include "Question.h"
class Iofile
{
public:
    Iofile(std::string filename);
    void readfile();
    void append(string line); // add one line at the end
    void writefile(std::vector<std::string> lines); // rewrite a file with new info, this will remove all old text
    std::vector<std::string> get_info();    // get the file infomation
    ~Iofile();
private:
    std::string filename_;
    std::vector<std::string> info_;
};

#endif
