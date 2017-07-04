#include <stdio.h>
#include <stdlib.h>


typedef struct node
    {
        int numdata;
        struct node* l_node;
        struct node* r_node;
    } node;
    
    node* insert(struct node* head, int value);
      int find_min(struct node* head);
       int find_max(struct node* head);
       void print_ascending(struct node* head);
       void node_delete(struct node* head, int value) ;
    
    int main()
    {
    struct node* head=NULL;
    head = insert(head,10);
    head = insert(head,7);
    head = insert(head,15);
    head = insert(head,5);
    head = insert(head,9);
    head = insert(head,6);
    head = insert(head,13);
    head = insert(head,20);
    head = insert(head,1);
    print_ascending(head);
    node_delete(head, 15); 
     
    printf("smallest number in the tree: %i \n",find_min(head));
     printf("Largest number in the tree: %i \n",find_max(head));
     print_ascending(head);
     
    }
    
    node* insert(struct node* head, int value)
    {
        struct node* ptr;
        ptr=head;
        
        if(head==NULL)
        {
        ptr = malloc(sizeof(node));
        head = ptr;
        ptr->numdata=value;
        ptr->l_node=NULL; 
        ptr->r_node=NULL;
        return head;
        }
        else if (value>=ptr->numdata)
        {
            ptr->r_node= insert(ptr->r_node, value);
            return ptr;
        }
        else if (value<ptr->numdata)
        {
            ptr->l_node= insert(ptr->l_node, value);
            return ptr;
        }
        return ptr;
    }
    
    int find_min(struct node* head)
    {
        struct node* ptr;
        ptr=head;
        int x;
        if(ptr->l_node == NULL)
        {
        return ptr->numdata;
        }
        else
        {
        x = find_min(ptr->l_node);
        return x;
        }
        
    }
     
     
     int find_max(struct node* head)
    {
        struct node* ptr;
        ptr=head;
        int x;
        if(ptr->r_node == NULL)
        {
        return ptr->numdata;
        }
        else
        {
        x = find_max(ptr->r_node);
        return x;
        }
        
    }   
    
    void print_ascending(struct node* head)
    {
    struct node* ptr;
        ptr=head;
        
        if(ptr == NULL)
        {
            return;
        }
        print_ascending(ptr->l_node);
        printf("%i ",ptr->numdata);
        print_ascending(ptr->r_node);
     return;
    }
    
    void node_delete(struct node* head, int value) 
    {
     struct node* ptr;
        ptr=head;
        if(ptr == NULL)
        {
            printf("Value not found");
            return;
        }
        else if(value == ptr->numdata)
        {
           ptr=head->r_node;
           while(ptr->l_node!=NULL) 
           {
           ptr=ptr->l_node;
           }
           
           ptr->l_node = head->l_node;
           
           ptr = head->r_node;
            head->l_node = ptr->l_node;
            head->numdata = ptr->numdata;
            struct node* temp;
            temp = head->r_node;
            head->r_node=ptr->r_node;
            free(temp);
             return;
        }
        else if(value < ptr->numdata)
        {
        node_delete(ptr->l_node, value);
        return;
        }
        else
        {
        node_delete(ptr->r_node, value);
        return;
        }
        
    }
  
