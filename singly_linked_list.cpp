/*
    Author : Vinit Patel.
    Aim : Implement Singly Linked List And its operations. [Not Final]
*/ 
#include<iostream>
#include<cstdlib>
using namespace std;
int i;
struct node
{
     int data;
     struct node * next;
};
struct node *head, *temp, *newnode, *nextnode;
    int ct = 0;
    void createlinkedlist()
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout<<"Insert an element : ";
        cin>>i;
        head = newnode ;
        newnode -> data = i;
        newnode -> next = NULL;
        temp = newnode;
    }
    void insert_beg()
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        // 
        cout<<"Enter element : ";
        cin>>newnode -> data;
        newnode -> next = head;
       head = newnode;
        ct ++;
    }
    void insert_end()
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout<<"Enter element : ";
        cin>> newnode -> data;
        temp = head;
        newnode -> next = 0;
        while(temp -> next !=0)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
        ct ++;
    }
    void insert_pos()
    {
        int pos, i=1;
        newnode = (struct node *)malloc(sizeof(struct node));
        cout<<"Enter the Element : ";
        cin>>newnode -> data;
        cout<<"Enter Position : ";
        cin>> pos;
        if(pos > ct)
        {
            cout<<"Invalid Position"<<endl;
        }
        else
        {
            temp = head;
            while (i < (pos-1))
            {
                temp = temp -> next;
                i++;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode; 
            ct ++;          
        }
        
    }
    void delete_beg()
    {
        if(head == 0)
        {
            cout<<"No Node";
        }
        else
        {
            temp = head;
            head = temp -> next;
            free(temp);
            ct --;
        }
        
    }
    void delete_end()
    {
        struct node *prev_node;
        temp =head;
        while(temp -> next !=0)
        {
            prev_node = temp;
            temp = temp -> next;
        }
        if(temp == head)
        {
            head = 0;
        }
        else
        {
            prev_node -> next = 0;
            free(temp);
            ct --;
        }
        
    }
    void delete_pos()
    {
        int pos, i=1;
        struct node *nextnode;
        
        temp = head;
        cout<<"Enter Position : ";
        cin>> pos;
        while(i < pos-1)
        {
            temp = temp -> next;
            i++;
        }
        nextnode = temp -> next;
        temp -> next = newnode -> next;
        free(nextnode);
        ct --;
    }
    void display()
    {
        struct node *ptr;
        // ptr = head;
        temp = head;
        while(temp != 0)
        {
            cout<<temp -> data<<endl;
            temp = temp -> next ;
        }
    }
    int main()
    {
        int op;
        cout<<"Operations : "<<endl;
        cout<<"1. Create a Linked List."<<endl;
        cout<<"2. Insert Element at the Beginning."<<endl;
        cout<<"3. Insert Element at the End."<<endl;
        cout<<"4. Insert Element at a particular position ."<<endl;
        cout<<"5. Delete Element at the Beginning."<<endl;
        cout<<"6. Delete Element at the end."<<endl;
        cout<<"7. Delete Element at a particular position."<<endl;
        cout<<"8. Display the Linked List."<<endl;
        cout<<"9. Exit."<<endl;
        do
        {
            cout<<"Select Operation : ";
            cin>>op;
            switch(op)
            {
                case 1 : createlinkedlist();
                break;
                case 2 : insert_beg();
                break;
                case 3 : insert_end();
                break;
                case 4 : insert_pos();
                break;
                case 5 : delete_beg();
                break;
                case 6 : delete_end();
                break;
                case 7 : delete_pos();
                break;
                case 8 : display();
                break;
                
            }

        }while(op != 9);
        return 0;
    }