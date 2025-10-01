#include<iostream>
using namespace std ; 

struct Node
{
    int val; 
    Node* next ; 
} ; 
void print(Node* pHead)
{
    if(pHead!=nullptr)
    {
        print(pHead->next) ; 
        cout<<pHead->val<<" ";
    }
}
signed main()
{
    reverse(head) ; 
}