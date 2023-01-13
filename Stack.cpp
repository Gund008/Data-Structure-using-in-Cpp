#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Stack
{
    public:
    struct node *First;
    int iCount;

    Stack();

    bool IsStackEmpty();
    void push(int);   
    int Pop();
    void Display();
};

Stack::Stack()
{
    First=NULL;
    iCount=0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void Stack::push(int no)
{
    struct node  *newn=new node;

    newn->data=no;
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

    cout<<"gets pushed in the stack succesfully"<<"\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack::Pop()
{
  if(First==NULL)
  {
    cout<<"Unable to pop the elements as stack is empty:"<<"\n";
    return -1;
  }
  else
  {
    int value=First->data;
    struct node *temp=First;

    First=First->next;
    delete temp;

    iCount--;

    return value;
  }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////

void Stack:: Display()
{
    if(First==NULL)
    {
        cout<<"Stack is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of stack are:"<<"\n";

        struct node *temp=First;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////

int main()  //User interaction function
{
    Stack obj1;
    int iRet=0;
    int iChoice=0;
    int iNo=0;

    while(1)  //Infinite loop
    {
        cout<<"Welcome to Write Application on Marvellous Infosystem:"<<"\n";
        cout<<"1:Push new Elements of Linked list:"<<"\n";
        cout<<"2:Pop Elements from linked list:"<<"\n";
        cout<<"3:Display Linked list:"<<"\n";

        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Pushed Elements:"<<"\n";
                cin>>iNo;

                obj1.push(11);
                break;
            
             case 2:
                cout<<"Poped Elements:"<<"\n";
                cin>>iNo;

                iRet=obj1.Pop();
                cout<<iRet<<"\n";
                break;

              case 3:
                 cout<<"Display:"<<"\n";
                 obj1.Display();
                 break;

              case 4:
                 printf("Thank you for using the Application:\n");
                 return 0;

            default:
                 printf("Invalid Option:\n");                
        } 
        printf("-------------------------------------------------------\n");
    }
    return 0;

}