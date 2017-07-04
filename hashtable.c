#include <stdio.h>
#include <stdlib.h>               //Hash tables
#include <string.h>

typedef struct node
{
int value;
struct node* next_node;
}
node;

int hash(int i);
void insert_node(node* hashtable[], int key);
void initialize_hash(node* hashtable[],int size);
void search_node(node* hashtable[], int key);
void delete_node(node* hashtable[], int key);

int main()
{
node* hashtable[17];
initialize_hash(hashtable, 17);

insert_node(hashtable, 23);
insert_node(hashtable, 40);
search_node(hashtable, 9);
search_node(hashtable, 23);
delete_node(hashtable, 23);
search_node(hashtable, 23);
search_node(hashtable, 40);
}

void insert_node(node* hashtable[], int key) // insertinf key values in hash table
{
int pos=hash(key); // fetching hashvalue for key element
node* ptr= malloc(sizeof(node)); // Allocating new node for new key element
ptr->value=key;

if(hashtable[pos]==NULL)// for first key value at a particular position 
{
hashtable[pos]=ptr;
ptr->next_node=NULL;
}
else
{
ptr->next_node=hashtable[pos];
hashtable[pos]=ptr;
}

}

void initialize_hash(node* hashtable[], int size)// initialize hash table values
{
for(int i=0; i<size; i++)
hashtable[i]=NULL;
}

int hash(int i)// hash function
{
 return(i%17);
}

void search_node(node* hashtable[], int key)// Search key value
{
  int pos=hash(key);  
 node*  ptr=hashtable[pos];
  if(ptr==NULL)
  printf("No value found \n");
  else
  {
      while(ptr!=NULL)
      {
     if(ptr->value==key)
     {
      printf("value: %d found at hash value:%d \n",key,pos);
      return;
     }
     else
      ptr=ptr->next_node;
      }
      printf("No value found\n");
  }
    
}

void delete_node(node* hashtable[], int key)// to delete a hash value
{
    int pos=hash(key);
    node*  ptr=hashtable[pos];
  if(ptr==NULL)
  printf("No value found to delete\n");
  else
  {
      while(ptr!=NULL)
      {
     if(hashtable[pos]->value==key) //to delete first key value
     {
      node* temp=hashtable[pos]->next_node;
      free(hashtable[pos]);
      hashtable[pos]=temp;
      return;
     }
     else if(ptr->next_node!=NULL) //checking pointer of 2nd node for NULL value
     {
      if(ptr->next_node->value==key)
      {
       node* temp=ptr->next_node->next_node;// deleting node after the 1st node 
       free(ptr->next_node);
       ptr->next_node=temp;
       return;
      }
     }
      ptr=ptr->next_node;
      }
      printf("No value found to delete\n");
  }
}
