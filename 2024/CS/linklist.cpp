#include<iostream>
using namespace std ; 

struct Node
{
    int val ;
    Node* pNext ; 
}; 
Node root ; 
void insert_x_after_k(int X , int K )
{
    Node* cur = &root ;
    while(cur)
    {
        if(cur->val == K)
        {
            Node* newNode = new Node() ; 
            newNode->val = X ; 
            newNode->pNext = cur->pNext ; 
            cur->pNext= newNode ; 
            return ; 
        }
        cur = cur->pNext ; 
    } 
}
signed main()
{

}