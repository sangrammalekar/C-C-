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
    void insert_loop(node* head);
    node* detectCycle(node* head);//to detect a loop in linked list
    
    int u=0;
    
    int main()
    {
    struct node* head=NULL;
    head = insert(head,0, 10);
    head = insert(head,1,12);
    head = insert(head,2,32);
    head = insert(head,3,38);
    head = insert(head,4,1);
    insert_loop(head);
   node* temp=detectCycle(head);
   printf("Loop exists at: %d",temp->numdata);
    }
    
    void insert_loop(node* head) //  create linked list loop
    {
        node* temp=head->nextnode->nextnode;
        node* ptr=head;
        while(ptr->nextnode!=NULL)
        {
            ptr=ptr->nextnode;
        }
        ptr->nextnode=temp;
    }
    
    node* detectCycle(node* head)  //to detect a loop in linked list
    {
    node* ptr=head;
    node** temp=malloc(sizeof(node*));//pointer to a pointer of node in linked list
    int size=0;
    while(ptr!=NULL)
    {
        
        for(int i=0; i<size; i++)
        {
            if(ptr==temp[size])
            return ptr;
        }
        temp[size]=ptr;
        ++size;
        temp=realloc(temp,(sizeof(node*)*(size+1)));
        ptr=ptr->nextnode;
    }
 return NULL;   
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
    
    
    
