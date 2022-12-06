#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    node *Next;
};
typedef struct node NODE;
typedef struct node* PNODE;
/////////////////////////////////////////////////////////////////////////////////////////
//Class Declaration 
class Singly_linkedList   
{
    private:
    PNODE Head;

    public:
    Singly_linkedList();
    ~Singly_linkedList();
    BOOL InsertFirst(int);
    BOOL InsertLast(int);
    BOOL InsertAtPos(int ,int);
    inline void Display();
    inline int Count();
    BOOL DeleteFirst();
    BOOL DeleteLast();
    BOOL DeleteAtPos(int);
};

 //Defination
Singly_linkedList::Singly_linkedList()   //constructor  
{ 
    Head=NULL;
}
Singly_linkedList::~Singly_linkedList()   //Destructor
{
    PNODE Temp,Navigate;

    if(Head!=NULL)
    {
        Navigate=Head;
        while(Navigate!=NULL)
        {
            Temp=Navigate->Next;
            delete Navigate;
            Navigate=Temp;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to insert at first position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:BOOL
*/
BOOL Singly_linkedList::InsertFirst(int no)
{
   PNODE newn=NULL;

   newn=new NODE;   //DMA
   newn->Next=NULL;
   newn->Data=no;

   if(newn==NULL)
   {
      return FALSE;
   }

   if(Head==NULL)
   {
     Head=newn;
   }
   else
   {
     newn->Next=Head;
     Head=newn;
   }
   return TRUE;
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to insert at Last position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:BOOL
*/
 BOOL Singly_linkedList:: InsertLast(int no)
 {
     PNODE newn=NULL;
     PNODE temp=Head;

     newn=new NODE;
     newn->Next=NULL;
     newn->Data=no;
     
     if(newn==NULL)
     {
        return FALSE;
     }
    
     if(Head==NULL)
     {
        Head=newn;
     }
     else
     {
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newn;
     }
 }

///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete  first or second or other  position of linked list
Parameter:Address of First Pointer 
Return Value:BOOL
*/

BOOL Singly_linkedList::DeleteFirst()
{
    PNODE temp =Head;

    if(Head==NULL)
    {
        return FALSE;
    }
    else
    {
        Head=Head->Next;
        free(temp);
    }
    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Delete Last position element of linked list
Parameter:Address of First Pointer 
Return Value:BOOL
*/

BOOL Singly_linkedList::DeleteLast()
{
    PNODE temp=Head;

    if(Head==NULL)  //atleast zero
    {
        return FALSE;
    }
    else if(Head->Next==NULL)            //1
    {
        delete Head;
        Head=NULL;
    }
    else
    {
       while(temp->Next->Next!=NULL)
       {
         temp=temp->Next;
       }
       delete(temp->Next);
       temp->Next=NULL;
    }

}

///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPos
Description:Used to insert at  position of linked list
Parameter:Address of First Pointer,position of elements,Number of linked list
Return Value:BOOL
*/

BOOL Singly_linkedList::InsertAtPos(int ipos,int no)
{
    int iNode=0;
    iNode=Count();

    if((ipos<1)||(ipos>iNode+1))    //filter
    {
        printf("Invalid Position:\n");
        return FALSE;
    }

    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==iNode+1)
    {
       InsertLast(no);
    }
    else
    {
        PNODE newn=NULL;
        PNODE temp=Head;
        newn=new NODE;

        newn->Data=no;
        newn->Next=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->Next;
        }
        newn->Next=temp->Next;
        temp->Next=newn;
    }
    return TRUE;
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPos
Description:Used to delete at  position of linked list
Parameter:Address of First Pointer,and Position
Return Value:BOOL
*/
BOOL Singly_linkedList::DeleteAtPos(int pos)

{   
    PNODE temp=Head;
    if((Head==NULL)||(pos>Count())||(pos<=0))
    {
        return FALSE;
    }
    else if(pos==1)
    {
       DeleteFirst();
    }
    else if(pos==(Count()))
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1=NULL;
        PNODE temp2=NULL;
       
        for(int i;i<=(pos-2);i++)
        {
          temp1=temp1->Next;
        }
        temp2=temp1->Next;
        temp1->Next=temp2->Next;
        delete temp2;
    }
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////
 
/*
Function name:Display
Description:Used to Display function to Display elemnts of linked list
Parameter:Address of First Pointer 
Return Value:Void
*/

void Singly_linkedList::Display()
{
   PNODE Temp=Head;
   cout<<"Linked list Elements are:\n";

   while(Temp!=NULL)
   {
     cout<<Temp->Data<<"->";
     Temp=Temp->Next;
   }
   cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to Count function Count elements of linked list
Parameter:Address of First Pointer 
Return Value:int
*/
int Singly_linkedList::Count()
{
   PNODE Temp=Head;
   int iCnt=0;
  
   while(Temp!=NULL)
   {
     iCnt++;
     Temp=Temp->Next;
   }
  return iCnt;
}
////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Singly_linkedList obj1;   //Static object creation
    Singly_linkedList *obj2=new Singly_linkedList();   //Dynamic Object Creation
    
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    int iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<"\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
   
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<"\n";
    
    obj1.InsertAtPos(5,131);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

  
    obj1.DeleteFirst();
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<"\n";

    obj1.DeleteLast();
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<"\n";

    obj1.DeleteAtPos(1);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Count of elements in linked list:"<<iRet<<endl;

    obj2->InsertFirst(501);
    obj2->InsertFirst(511);
    obj2->InsertFirst(521);

    obj2->Display();

    return 0;

}
