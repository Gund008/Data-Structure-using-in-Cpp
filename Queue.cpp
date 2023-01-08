#include<iostream>
using namespace std;

//Structure Declaration
struct node
{
    int data;
    struct node *next;
};

//Class Declaration
class Queue
{
    public:
         struct node *First;
         int iCount;

         Queue();
         bool IsQueueEmpty();
         void EnQueue(int iNo);
         int DeQueue();  
         void Display();     
};
/////////////////////////////////////////////////////////////////////////////////////////////////

//Class Defination
 Queue:: Queue()
{
    First=NULL;
    iCount=0;
}

bool  Queue::IsQueueEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void Queue::EnQueue(int iNo)
{
    struct node *newn=new  node;

    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    iCount++;

    cout<<"gets pushed in the stack Succesfully"<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////
int Queue::DeQueue()
{
    struct node *temp=First;
    if(First==NULL)
    {
        cout<<"Unable to Pop the elements as Stack is empty"<<"\n";
        return -1;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        int ivalue=First->data;

        First=First->next;
        delete(temp);

        iCount--;

        return ivalue;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void Queue::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is Empty"<<"\n";
    }
    else
    {
        cout<<"Elements of Stack are:"<<"\n";

        struct node* temp=First;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Queue obj;
    obj.EnQueue(11);
    obj.EnQueue(21);
    obj.EnQueue(51);
    obj.EnQueue(101);

    obj.Display();

    int iRet=obj.DeQueue();
    cout<<"Poped Elements is:"<<iRet<<"\n";
    
    iRet=obj.DeQueue();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    obj.Display();

    return 0;

}