#include<iostream>
using namespace std;

//Structure Declaration
struct node
{
    int data;
    struct node *next;
};

//Class Declaration
class Stack
{
    public:
         struct node *First;
         int iCount;

         Stack();
         bool IsStackEmpty();
         void Push(int iNo);
         int Pop();  
         void Display();     
};
/////////////////////////////////////////////////////////////////////////////////////////////////

//Class Defination
Stack::Stack()
{
    First=NULL;
    iCount=0;
}

bool Stack::IsStackEmpty()
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
void Stack:: Push(int iNo)
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
int Stack::Pop()
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
void Stack::Display()
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
    Stack sobj;
    sobj.Push(11);
    sobj.Push(21);
    sobj.Push(51);
    sobj.Push(101);

    sobj.Display();

    int iRet=sobj.Pop();
    cout<<"Poped Elements is:"<<iRet<<"\n";
    
    iRet=sobj.Pop();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    sobj.Display();

    return 0;

}