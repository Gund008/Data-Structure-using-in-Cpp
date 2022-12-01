#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;

////////////////////////////////////////////////////////////////////////////////////////////

//Class declaration
class Doubly_Linked_List
{
    private:
    PNODE Head;

    public:
    Doubly_Linked_List();
   ~Doubly_Linked_List();
    BOOL InsertFirst(int);
    BOOL InsertLast(int);
    BOOL InsertAtPos(int,int);
    inline void Display();
    inline int Count();
    BOOL DeleteFirst();
    BOOL DeleteLast();
    BOOL DeleteAtPos(int);
};

//Class Defination
Doubly_Linked_List::Doubly_Linked_List()
{
    Head=NULL;
}

Doubly_Linked_List::~Doubly_Linked_List()
{
    PNODE Temp=Head;
    if(Head!=NULL)
    {
       while(Head!=NULL)
       {
          Temp=Temp->next;
          delete Temp;
          Temp=Head;
       }
    }
   
}
//////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to insert at First position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:BOOL
*/
BOOL Doubly_Linked_List:: InsertFirst(int no)
{
   PNODE newn=NULL;

   newn=new NODE;
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;

   if(Head==NULL)
   {
     Head=newn;
   }
   else
   {
     newn->next=Head;
     Head->prev=newn;
     Head=newn;
   }
   return TRUE;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to insert at Last position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:BOOL
*/
BOOL Doubly_Linked_List:: InsertLast(int no)
{
   PNODE newn=NULL;

   newn=new NODE;
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;

   if(Head==NULL)
   {
     Head=newn;
   }
   else
   {
     PNODE temp=Head;
     while(temp->next!=NULL)
     {
        temp=temp->next;
     }
     temp->next=newn;
     newn->prev=temp; 
     temp=newn;
   }
   return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to delete at First position of linked list
Parameter:Address of First Pointer 
Return Value:BOOL
*/
BOOL Doubly_Linked_List:: DeleteFirst()
{
    PNODE temp=Head;
    if(temp==NULL)
    {
        return FALSE;
    }
   
    else
    {
       Head= Head->next;
       Head->prev=NULL;

       delete  temp;
    }
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to insert at Last position of linked list
Parameter:Address of First Pointer 
Return Value:BOOL
*/
BOOL Doubly_Linked_List:: DeleteLast()
{
    PNODE temp=Head;
    if(temp==NULL)
    {
        return FALSE;
    }
   
    else
    {
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
     temp->prev->next=NULL;
     delete temp;
    }
    return TRUE;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPosition
Description:Used to Insert at position of linked list
Parameter:Address of First Pointer and Data of Node and elements Position
Return Value:BOOL
*/
BOOL Doubly_Linked_List::InsertAtPos(int ipos,int no)
{
 int iCnt=0;
 int inode=0;
 inode=Count();
 
 if((ipos<1)||(ipos>inode+1))
 {
    printf("Invalid Position:\n");
    return FALSE;
 }

 if(ipos==1)
 {
    InsertFirst(no);
 }
 else if(ipos==inode+1)
 {
    InsertLast(no);
 }
 else
 {
    PNODE newn=NULL;
    newn=new NODE;
    PNODE temp=Head;
   
    newn->data=no;
    newn->next=NULL;

    for(int i=1;i<ipos-1;i++)
    {
        temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev=newn;
    temp->next=newn;
    newn->prev=temp;
 }
 return TRUE;

}
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPosition
Description:Used to Delete at position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:BOOL
*/
BOOL Doubly_Linked_List::DeleteAtPos(int ipos)
{
 
 if((Head==NULL)||(ipos>Count())||(ipos<=0))
 {
    printf("Invalid Position:\n");
    return FALSE;
 }

 if(ipos==1)
 {
    DeleteFirst();
 }
 else if(ipos==Count())
 {
    DeleteLast();
 }
 else
 {
    PNODE temp=Head;

    for(int i=1;i<=(ipos-2);i++)
    {
        temp=temp->next;
    }
   temp->next=temp->next->next;
   delete temp->next->prev;
   temp->next->prev=temp;
 }
 return TRUE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to display element of linked list
Parameter:Address of First Pointer 
Return Value:void
*/
void Doubly_Linked_List:: Display()
{
     PNODE temp=Head;
     cout<<"Elements of linked list:\n";
     while(temp!=NULL)
     {
        cout<<temp->data<<"<=>";
        temp=temp->next;
     }
     cout<<"NULL\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Count element of linked list
Parameter:Address of First Pointer 
Return Value:int
*/

int Doubly_Linked_List:: Count()
{
     PNODE temp=Head;
     int iCnt=0;
     while(temp!=NULL)
     {
        iCnt++;
        temp=temp->next;
     }
     return iCnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Doubly_Linked_List obj1;
    Doubly_Linked_List *obj2=new Doubly_Linked_List();   //Runtime Object Creation
    int iRet=0;
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj1.InsertLast(11);
    obj1.InsertLast(121);
  
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj1.InsertAtPos(5,131);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj1.DeleteAtPos(5);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;
    
    obj1.DeleteFirst();
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj1.DeleteLast();
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    cout<<"Second Linked list:\n";

    obj2->InsertFirst(151);
    obj2->InsertFirst(121);
    obj2->InsertFirst(111);

    obj2->Display();
    iRet=obj2->Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj2->InsertLast(132);
    obj2->InsertLast(123);
  
    obj2->Display();
    iRet=obj2->Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj2->InsertAtPos(5,131);
    obj2->Display();
    iRet=obj2->Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj2->DeleteAtPos(5);
    obj2->Display();
    iRet=obj2->Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    
    obj2->DeleteFirst();
    obj2->Display();
    iRet=obj2->Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj2->DeleteLast();
    obj2->Display();
    iRet=obj2->Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    return 0;

}