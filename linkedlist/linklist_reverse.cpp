#include <list>
#include <iostream>
using namespace std;
void reverse_list(list<int>& link);
void print_list(list<int>& link);
int main()
{

list<int> link={1,2,3,4,5};
//cout<<link;
print_list(link);
reverse_list(link);
print_list(link);
}
void reverse_list(list<int>& link)
{
    list<int>::const_iterator i=link.begin();
    if(i==link.end())            // base case reaching last element
    return;
    
     int temp=link.front();
      link.erase(link.begin());
      
    reverse_list(link);// recursion
    
    link.push_back(temp); // pushing or inserting back element to reverse the list
}

void print_list(list<int>& link)
{
    list<int>::const_iterator it=link.begin();;
while(it!=link.end())
{
cout<<*it<<" ";
it++;
}
cout<<"\n";
}
