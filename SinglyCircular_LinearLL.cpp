#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class Circular
{
    public:
    PNODE Head;
    PNODE Tail;
    int Count;

    Circular();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int,int);
    void DeleteAtPos(int);
    void Display();
};

Circular::Circular()
{
    Head=NULL;
    Tail=NULL;
    Count=1;
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to insert at First position of linked list
Parameter: Data of Node
Return Value:Void
*/
void Circular::InsertFirst(int iNo)
{
   PNODE newn=NULL;
   newn=(PNODE)malloc(sizeof(NODE));
   newn->data=iNo;
   newn->next=NULL;

   if((Head==NULL) && (Tail==NULL))
   {
      Head=Tail=newn;
   }
   else
   {
      newn->next=Head;
      Head=newn;
      Tail->next=Head;
      Count++;
   }
}
////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Display linked list of all nodes
Parameter: -
Return Value:Void
*/
void Circular::Display()
{
    cout<<"linked list element is:"<<"\n";
    PNODE temp=Head;
    do
    {
        cout<<temp->data<<"|->";
        temp=temp->next;

    }while(temp!=Tail->next);

    printf("\n");

}

////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to insert at Last position of linked list
Parameter:Data of Node
Return Value:Void
*/
void Circular::InsertLast(int iNo)
{
    PNODE newn=NULL;
    PNODE temp=Head;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head=Tail=newn;
    }
    else
    {
        Tail->next=newn;
        Tail=newn;
        Tail->next=Head;
        Count++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete First Node of linked list
Parameter:  -
Return Value:Void
*/
void Circular:: DeleteFirst()
{
     PNODE temp=Head;
 
     if((Head==NULL)&&(Tail==NULL))
     {
        return;
     }
    else if(Head==Tail)
     {
        free(Head);
        Head=NULL;
        Tail=NULL;
     }
    else
     {
        (Head)=(Head)->next;
        free(temp);
        Tail->next=Head;
        Count--;
     }       
    
}
//////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to Delete last node of linked list
Parameter: -
Return Value:Void
*/
void Circular:: DeleteLast()
{
    PNODE temp=Head;
    if((Head==NULL)&&(Tail==NULL))
    {
        return;
    }
    else if(Head==Tail)
    {
        free(Head);
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        while(temp->next!=Tail)
        {
            temp=temp->next;
        }
        free (temp->next);
        Tail=temp;
        Tail->next=Head;
        
    }

       
}
///////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPos
Description:Used to insert at node in Any Position of linked list
Parameter: - data of nodes, position of node
Return Value:Void
*/
void Circular:: InsertAtPos(int iNo,int ipos)
{
    if((ipos<1)||(ipos>Count))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }
    if(ipos==1)
    {
        InsertFirst(iNo);
    }
    else if(ipos==Count+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn=NULL;
        PNODE temp=Head;
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=iNo;
        newn->next=NULL;

        for(int iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        Tail->next=Head;
        Count++;
    }    
}
///////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPos
Description:Used to Delete at node in Any Position of linked list
Parameter:Data of node
Return Value:Void
*/

void Circular:: DeleteAtPos(int ipos)
{
    if((ipos<1)||(ipos>Count))  //Filter 
    {
       cout<<"Invalid Position:"<<"\n";
       return;
    }
     
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==Count)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1=Head;
        PNODE temp2=NULL;
        for(int iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
        Count--;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Circular obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    cout<<"Count of linked list element:"<<obj.Count<<"\n";

    obj.InsertLast(151);
    obj.InsertLast(121);
    obj.InsertLast(111);

    obj.Display();
    cout<<"Count of linked list element:"<<obj.Count<<"\n";

    obj.InsertAtPos(105,5);

    obj.Display();
    cout<<"Count of linked list element:"<<obj.Count<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();
    cout<<"Count of linked list element:"<<obj.Count<<"\n";

    obj.DeleteFirst();
    
    obj.Display();
    cout<<"Count of linked list element:"<<obj.Count<<"\n";

    obj.DeleteLast();
    
    obj.Display();
    cout<<"Count of linked list element:"<<obj.Count<<"\n";

    return 0;
}