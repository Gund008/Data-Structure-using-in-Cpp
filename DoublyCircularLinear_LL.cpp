#include<iostream>
using namespace std;

#pragma pack(1)
//Structure declaration
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;

//class Declaration
class DoublyCL
{
    public:
       PNODE First;
       PNODE Last;

       DoublyCL();
       void InsertFirst(int);
       void InsertLast(int);
       void InsertAtPos(int,int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int);
       void Display();
       int Count();
};

DoublyCL::DoublyCL()
{
    First=NULL;
    Last=NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to Insert at first position of linked list
Parameter:Data of Node
Return Value:Void
*/
void DoublyCL::InsertFirst(int iNo)
{
    PNODE newn=NULL;
    newn=new NODE;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((First==NULL) && (Last==NULL))
    {
        First=Last=newn;
    }
    else
    {
        newn->next=First;
        (First)->prev=newn;
        First=newn;
    }
     (Last)->next=First;
     (First)->prev=Last;

}
////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to Insert at Last position of linked list
Parameter:Data of Node
Return Value:Void
*/
void DoublyCL:: InsertLast(int iNo)
{
    PNODE newn=NULL;
    newn=new NODE;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((First==NULL) && (Last==NULL))
    {
        First=Last=newn;
    }
    else
    {
        (Last)->next=newn;
        newn->prev=Last;
        (Last)=newn;
    }
     (Last)->next=First;
     (First)->prev=Last;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Display all Node of linked list
Parameter:No
Return Value:Void
*/
void DoublyCL:: Display()
{
    PNODE temp=First;

    if((First==NULL)&&(Last==NULL))
    {
        cout<<"Element of linked list are:"<<"\n";
        return;
    }
    printf("Linked list Elements are:\n");
    do
    {
        cout<<"|"<<First->data<<"|<=>";
        First=First->next;
    }while(First!=Last->next);
    cout<<"\n";

}
//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to Count all Node of  linked list
Parameter:No
Return Value:int
*/
int DoublyCL::Count()
{
    PNODE temp=First;
    int iCnt=0;
    if((First==NULL) &&(Last==NULL)) 
    int iCnt=0;
    do
    {
       iCnt++;
       temp=temp->next;
    }while(temp!=Last->next);
    return iCnt;

}
//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete at first position of linked list
Parameter:No
Return Value:Void
*/

void DoublyCL::DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if((First)==(Last))
    {
        free(First);
        First=NULL;
        Last=NULL;
    }
    else
    {
        (First)=(First)->next;
        delete(Last)->next;

        (Last)->next=First;
        (First)->prev=Last;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to Delete Last  position of linked list
Parameter:No
Return Value:Void
*/
void DoublyCL::DeleteLast()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if((First)==(Last))
    {
        free(First);
        First=NULL;
        Last=NULL;
    }
    else
    {
       Last=(Last)->prev;
       delete(First)->prev;
       (Last)->next=First;
       (First)->prev=Last;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPos
Description:Used to Insert at Any position of linked list
Parameter:Data of Node And position of node.
Return Value:Void
*/
void DoublyCL::InsertAtPos(int iNo,int ipos)
{
     int iNodeCnt=0;
     iNodeCnt=Count();

     if((ipos<1)||(ipos>iNodeCnt+1))  //filter
     {
        cout<<"Invalid position:\n";
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
       PNODE temp=First;
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
     }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPos
Description:Used to Delete at Any position of linked list
Parameter:Position of Node
Return Value:Void
*/
void DoublyCL::DeleteAtPos(int ipos)
{
     int iNodeCnt=0;
     iNodeCnt=Count();

     if((ipos<1)||(ipos>iNodeCnt))  //filter
     {
        cout<<"Invalid position:\n";
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
       PNODE temp1=First;
       PNODE temp2=NULL;
       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
        temp1=temp1->next;
       }
       temp2=temp1->next;
       temp1->next=temp2->next;
       free(temp2);

     }
}
////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    DoublyCL obj;
    int iRet=0;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet=obj.Count();
    cout<<"Count node of linked list:"<<iRet<<endl;

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet=obj.Count();
    cout<<"Count node of linked list:"<<iRet<<endl;
    
    obj.InsertAtPos(105,5);
    obj.Display();
    iRet=obj.Count();
    cout<<"Count node of linked list:"<<iRet<<endl;
     
    obj.DeleteAtPos(5);
    obj.Display();
    iRet=obj.Count();
    cout<<"Count node of linked list:"<<iRet<<endl;
     
    obj.DeleteFirst();
    obj.Display();
    iRet=obj.Count();
    cout<<"Count node of linked list:"<<iRet<<endl;

    obj.DeleteLast();
    obj.Display();
    iRet=obj.Count();
    cout<<"Count node of linked list:"<<iRet<<endl;

    return 0;
}
