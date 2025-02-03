/*Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
 Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
 a task on the day specified.
 Remove a task. Accepts the date and month as a parameter to remove the task from.
 Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list.*/


#include <iostream>
#include <string>
using namespace std;

class Calendar{

    string month[12];
    int year;
    string task;
    int day;

    public:

        void addTask(const string &detail,int date, string mnth){
            task=detail;
            day=date;
            for(int i=0;i<12;i++){
                if (month[i]==mnth)
            }

        }

};
