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

#include "Iofile.h"

// constructor 
Iofile::Iofile(std::string filename)
{
    this->filename_ = filename;
}

// read a file line by line then store each line into a string vector
void Iofile::readfile()
{
    std::ifstream ifs;              // create ifstream object for read the file
    ifs.open(this->filename_);
    std::string line;
    while(getline(ifs,line))
    {
        this->info_.push_back(line);
    }
    ifs.close();
    return;
}

// add text into a file 
void Iofile::append(string line)
{                      
    std::ofstream ofsa;
    ofsa.open(this->filename_, std::ios::app);  // using ios::app to open a file and add at the end of file
    ofsa << line << std::endl;
    // add one question a time
    ofsa.close();


    return;
}

// rewrite a file
void Iofile::writefile(std::vector<std::string> lines)
{
    std::ofstream ofsw;
    ofsw.open(this->filename_, std::ios::out);  // using ios::out write a file, if the file is not empty, will empty the file
    for(int i=0; i<lines.size(); i++)
    {
        ofsw << lines[i] << std::endl;
    }

}

std::vector<std::string> Iofile::get_info()
{
    return this->info_;
}

Iofile::~Iofile()
{
    // nothing need to do
}