#include <iostream>
using namespace std;
class list
{
    string task_name;
    string status;
public:
    //setting data 
    void settask_name()
    {
        cin. ignore();
        getline(cin,task_name);
    }
    //marking task as complete 
    void settask_complete()
    {
        status="complete";
    }
    //marking task as incomplete 
    void settask_incomplete()
    {
        status="incomplete";
    }
    //returning task name
    string gettask_name()
    {
        return task_name;
    }
    //returning task status
    string gettask_status()
    {
        return status;
    }
};


class task
{
    int no_of_tasks;
    //creating object for class list
    list l[10];
public:
    //function for inputing task
    void input()
    {

        cout<<"enter the no of tasks to be added initially : ";
        cin>> no_of_tasks;
        cout<<"------------------\n";

        for(int k=0; k< no_of_tasks; k++)
        {
            cout<<"enter the name of the task "<< k+1 <<" : ";
            l[k].settask_name();
            l[k].settask_incomplete();

        }
         cout<<"------------------\n";
    }
    //function for adding additional task
    void add()
    {
        int no_of_additional_tasks;
        cout<<"enter the no of tasks to be added additionally :  ";
        cin>>no_of_additional_tasks;
         cout<<"------------------\n";
        for(int p=no_of_tasks; p< no_of_tasks+no_of_additional_tasks; p++)
        {

            cout<<"enter the name of the task : ";
            l[p].settask_name();
            l[p].settask_incomplete();

        }
         cout<<"------------------\n";
        no_of_tasks+= no_of_additional_tasks;
    }
    //function for marking task status 
    void task_status()
    {
        int chance;
        do
        {
            int will;
            string check_taskname;
            cout<<"enter the task : ";
            cin. ignore();
            getline(cin,check_taskname);
            cout<<"------------------\n";
            cout<<"press 1 to mark as completed\n";
            cout<<"press 2 to mark as incomplete\n";
            cin>>will;
            cout<<"------------------\n";
            for(int i=0; i< no_of_tasks; i++)
            {
                if(check_taskname==l[i].gettask_name())
                {
                    if(will==1)
                    {
                        l[i].settask_complete();
                        cout<<"task marked as completed\n";
                        cout<<"------------------\n";
                        break;
                    }
                    else if(will==2)
                    {
                        l[i].settask_incomplete();
                        cout<<"task marked as incompleted\n";
                        cout<<"------------------\n";
                        break;
                    }
                }
                else
                {
                    if(i==no_of_tasks-1)
                        cout<<"not found! \n";
                        cout<<"------------------\n";
                }
            }
            
            cout<<"press 0 to continue the task status process :  ";
            cin>>chance;
             cout<<"------------------\n";

        } while(chance==0);

    }
    //function for displaying 
    void display()
    {
        for(int z=0; z<no_of_tasks; z++)
        {
             cout<<"------------------\n";
            cout<<"task name = "<<l[z].gettask_name()<<endl;
            cout<<"status = "<<l[z].gettask_status()<<endl;
             cout<<"------------------\n";
        }
    }




};
int main()
{
    task t;
    int get;
    cout<<"---TO--DO--LIST---"<<endl<<endl;
    cout<<"HOME PAGE : \n";
    cout<<"1 . input tasks \n";
    cout<<"2 . add additional tasks \n";
    cout<<"3 . mark task status \n";
    cout<<"4 . display the tasks \n\n";
    cout<<"------------------\n";

    do
    {
        int user;
        
        cout<<"enter your choice :  ";
        cin>>user;
        cout<<"------------------\n";
        switch(user)
        {
        case 1:
            t.input();
            break;
        case 2:
            t.add();
            break;
        case 3:
            t.task_status();
            break;
        case 4:
            t.display();
            break;
        default:
            cout<<"error!\n";
            break;
        }
        cout<<"press 0 to go to homepage  :  ";
        cin>>get;
        cout<<"------------------\n";

    } while(get==0);


    return 0;
}