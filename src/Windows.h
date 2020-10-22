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
#ifndef WINDOWS_H
#define WINDOWS_H
#include <ncurses.h>
#include <string>
class Windows
{
public:
    /* create a window */
    Windows();

    WINDOW * getwin();

    /* draw main window */
    void drawmainwin(std::string *, int num_content, int maxlen);

    /* menu window */
    int menuwin(std::string *, int num_content, int maxlen);
    
    /* input window */
    std::string inputwin();

    ~Windows();
    
private:
    WINDOW * win_;
    WINDOW * menu_;
    WINDOW * input_;
    int maxy_;
    int maxx_;

};

#endif
