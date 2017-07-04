#include <stdio.h>
#include <stdlib.h>


typedef struct node
    {
        int numdata;
        struct node* nextnode;
    } node;
    
    node* insert(struct node* head,int pos, int value);
    void print(struct node* head);
    int find(struct node* head, int value);
    node* reverse(struct node* head);
    int u=0;
    
    int main()
    {
    struct node* head=NULL;
    head = insert(head,0, 10);
    head = insert(head,1,12);
    head = insert(head,2,32);
    head = insert(head,2,38);
    head = insert(head,1,1);
    print(head);
    if(find(head,5)==1)
    printf("value 5 found \n");
    else
    printf("value 5 not found \n");
    
    if(find(head,38)==1)
    printf("value 38 found \n");
    else
    printf("value 38 not found \n");
    head = reverse(head);
    print(head);
    head = reverse(head);
    print(head);
    }
    
    node* insert(struct node* head, int pos, int value)
    {
        struct node* ptr;
        ptr=head;
        
        if(head==NULL && pos==0)
        {
        ptr = malloc(sizeof(node));
        head = ptr;
        ptr->numdata=value;
        ptr->nextnode=NULL; 
        }
        else
        {
            for (int j = 0; j <pos; j++)
            {
                
                if(j==pos-1)
                {
                struct node* ptr2;
                ptr2 = malloc(sizeof(struct node));
                ptr2->nextnode = ptr->nextnode;
                ptr2->numdata=value;
                ptr->nextnode=ptr2;
                //break;
                }
                ptr=ptr->nextnode;
            }
        }
        
        
        return head;
    }
    
    void print(struct node* head)
    {
        struct node* ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%i \n",ptr->numdata);
            ptr=ptr->nextnode;
            u++;
        }
    }
    
    void duplicate(struct node* head)
    {
        struct node* ptr;
        struct node* ptr_next;
        ptr=head;
        ptr_next = ptr->nextnode;
        for (int j = 0; j <u; j++)
        {
            for (int k = 0; k <u; k++)
            {
        if(ptr->numdata > ptr_next->numdata)
         {
          insert(head,1,12);
         }
            }
            
        }
    }
    
    int find(struct node* head, int value)
    {
        struct node* ptr;
        ptr = head;
        
        if (head==NULL)
        return 0;
        else if(head->numdata==value)
        return 1;
        else
        return find(ptr->nextnode,value);
        
    }
    
    node* reverse(struct node* head)
    {
        struct node* ptr;
        struct node* temp;
        ptr = head;
        ptr=ptr->nextnode;
        if(ptr->nextnode==NULL)
        {
        temp=ptr;
        ptr->nextnode=head;
        head->nextnode=NULL;
        return temp;
        }
        else
        {
        temp = reverse(ptr);
        ptr->nextnode=head;
        head->nextnode=NULL;
        return temp;
        }
        
    }
    
    
    
