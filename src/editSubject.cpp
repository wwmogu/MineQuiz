#include "Subject.h"

int editSubject(Subject *subject)
{
        int choice;
        while(true)
        {
                choice = subject->window();
                switch(choice)
                {
                        case 0: // practice
                                subject->practice();
                                break;
                        case 1: // add one question
                                subject->add_question();
                                break;
                        case 2: // remove one question from question list.
                                subject->rm_question();
                                break;
                        default:
                                break;
                }
                if(choice == 3)
                {
                        break;
                }
        }
        return choice;

}