#include<iostream>
using namespace std;

//Structure Declaration
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

//Class Declaration
class DoublyCLL
{
    public:
    PNODE Head; 
    PNODE Tail;
    int Count;

    DoublyCLL();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int ,int);
    void Display();
   
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};
//Constructor
DoublyCLL::DoublyCLL()
{
    Head=NULL;
    Tail=NULL;
    Count=1;
}
////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to insert at first position of linked list
Parameter:Data of Node
Return Value:Void
*/
void DoublyCLL::InsertFirst(int iNo)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head=Tail=newn;
    }
    else
    {
        newn->next=Head;
        newn->prev=Head;
        Head=newn;
        (Tail)->next=Head;
        (Head)->prev=Tail;
        Count++;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Display All Node  of linked list
Parameter:No
Return Value:Void
*/
void DoublyCLL::Display()
{
   cout<<"Linked list elements are:"<<endl;

    do
    {
        printf("|%d|<=>",Head->data);
        Head=Head->next;
    }while(Head!=Tail->next);
    cout<<"\n";

}

/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to insert at Last position of linked list
Parameter:Data of Node
Return Value:Void
*/

void DoublyCLL::InsertLast(int iNo)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head=Tail=newn;
    }
    else
    {
        (Tail)->next=newn;
        newn->prev=Tail;
        Tail=newn;
        (Tail)->next=Head;
        (Head)->prev=Tail;
        Count++;

    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete at first position of linked list
Parameter:No
Return Value:Void
*/
void DoublyCLL::DeleteFirst()
{
    if((Head==NULL)&&(Tail==NULL))
    {
        return;
    }
    else if((Head)==(Tail))
    {
        delete(Head);
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        PNODE temp=Head;
        (Head)=(Head)->next;
        delete(temp);
        (Tail)->next=Head;
        (Head)->prev=Tail;
        Count--;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to Delete at Last position of linked list
Parameter:No
Return Value:Void
*/
void DoublyCLL::DeleteLast()
{
    if((Head==NULL)&&(Tail==NULL))
    {
        return;
    }
    else if((Head)==(Tail))
    {
        delete(Head);
        Head=NULL;
        Tail=NULL;
    }
    else
    {
       PNODE temp=Head;
       while(temp->next->next!=(Head))
       {
         temp=temp->next;
       }
       delete(temp->next);
       (Tail)=temp;
       (Tail)->next=Head;
       (Head)->prev=Tail;
       Count--;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPos
Description:Used to insert at Any position of linked list
Parameter:Data of Node And Position of linked list
Return Value:Void
*/
void DoublyCLL::InsertAtPos(int iNo,int ipos)
{
     int iNodeCnt=0;
     iNodeCnt=Count;

     if((ipos<1)||(ipos>iNodeCnt+1))  //filter
     {
        cout<<"linked list elements are:"<<endl;
        return;
     }

     if(ipos==1)
     {
        InsertFirst(iNo);
     }
     else if(ipos==iNodeCnt+1)
     {
        InsertLast(iNo);
     }
     else
     {
       int iCnt=0;
       PNODE temp=Head;
       PNODE newn=NULL;
       newn=new NODE;

       newn->data=iNo;
       newn->next=NULL;
       newn->prev=NULL;

       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
        temp=temp->next;
       }
       newn->next=temp->next;
       temp->next->prev=newn;
       temp->next=newn;
       newn->prev=temp;
       Count++;
     }
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPos
Description:Used to Delete At Any position of linked list
Parameter:Position of Node in  Linked list
Return Value:Void
*/
void DoublyCLL:: DeleteAtPos(int ipos)
{
     int iNodeCnt=0;
     iNodeCnt=Count;

     if((ipos<1)||(ipos>iNodeCnt))  //filter
     {
        cout<<"Invalid position"<<"\n";
        return;
     }

     if(ipos==1)
     {
        DeleteFirst();
     }
     else if(ipos==iNodeCnt)
     {
        DeleteLast();
     }
     else
     {
       int iCnt=0;
       PNODE temp1=Head;
       PNODE temp2=NULL;
       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
        temp1=temp1->next;
       }
       temp2=temp1->next;
       temp1->next=temp2->next;
       delete(temp2);
       Count--;
     }
}
/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    DoublyCLL obj;
 
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    cout<<"Count of Node in linked list:"<<obj.Count<<"\n";

    obj.InsertLast(151);
    obj.InsertLast(121);
    obj.InsertLast(111);

    obj.Display();
    cout<<"Count of Node in linked list:"<<obj.Count<<"\n";

  
    obj.InsertAtPos(105,5);
    obj.Display();
    cout<<"Count of Node in linked list:"<<obj.Count<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    cout<<"Count of Node in linked list:"<<obj.Count<<"\n";


    obj.DeleteFirst();
    obj.Display();
    cout<<"Count of Node in linked list:"<<obj.Count<<"\n";

    
    obj.DeleteLast();
    obj.Display();
    cout<<"Count of Node in linked list:"<<obj.Count<<"\n";

    return 0;

}