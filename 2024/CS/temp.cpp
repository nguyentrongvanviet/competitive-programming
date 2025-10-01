#include<iostream>

using namespace std ;

struct Node
{
	int val; 
	Node*next ; 
	Node(int val=0):val(val),next(nullptr){} 
} ;
void remove(Node*&pHead ,int val)
{
	Node* cur= new Node() ; 
	Node* res = cur ; 
	while(pHead)
	{
		if(pHead->val!=val)
		{
			cur->next = pHead ;
			cur=cur->next ; 
		}
		pHead=pHead->next ;
	}
	cur->next = nullptr ; 
	pHead = res->next ; 
}
void remove2sumX(Node*&pHead ,  int x )
{
	while(1)
	{
		bool ok = 0 ; 
		Node* cur1  = pHead ; 
		while(cur1)
		{
			Node*cur2 = pHead ; 
			while(cur2)
			{
				if(cur1->val+cur2->val==x)
				{
					ok =1 ; 
					// cout<<cur1->val<<" "<<cur2->val<<endl; 
					remove(pHead,cur1->val) ; 
					remove(pHead,cur2->val) ;
					break; 
				}
				cur2=cur2->next ; 
			}
			if(ok)break; 
			cur1=cur1->next ; 
		}
		if(ok==0)break; 
	}
}
signed main()
{
	Node* A= new Node(5) ; 
	Node* B=new Node(4) ; 
	Node* C=new Node(3) ; 
	Node* D=new Node(3) ;
	Node* E = new Node(1) ; 
	A->next = B ; 
	B->next = C ; 
	C->next = D ; 
	D->next = E ; 
	remove2sumX(A,6) ; 
	while(A)
	{
		cout<<A->val<<" "; 
		A=A->next ; 
	}
}