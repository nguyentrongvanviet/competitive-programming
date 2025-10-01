#include<iostream>
using namespace std ; 

struct Node
{	
	int val ; 
	Node(){} 
	Node(int val):val(val){}
	Node* leftchild , rightchild ; 
} ; 
void insert2BST(Node* &pRoot , int x)
{
	if(pRoot==nullptr)
	{
		pRoot= new Node(x) ; 	
		return ; 
	}
	if(pRoot->val>x)
	{
		insert2BST(pRoot->leftchild,x) ; 
	}
	else if(pRoot->val<x)
	{
		insert2BST(pRoot->leftcihld,x) ; 
	}
}
Node* search BST(Node* pRoot, int x)
{
	if(pRoot==nullptr||pRoot->val==x)return pRoot;
	if(pRoot->val>x)
	{
		return search(pRoot->leftchild,x) ; 
	}	
	return search(pRoot->rightchild,x) ;
}
void deleteWholeBST(Node*& pRoot)
{	
	if(pRoot==nullptr)return ; 
	deleteWholeBST(pRoot->leftchild) ; 
	deleteWholeBST(pRoot->rightchild) ; 
	delete pRoot ; 
}
void printLNR(Node* pRoot)
{
	if(pRoot==nullptr)return ; 
	printLNR(pRoot->leftchild) ; 
	cout<<pRoot->val<<" "; 
	printLNR(pRoot->rightchild) ;
}
Node* findClosest(Node* pRoot,int x)
{
	// lon nhat be hon x 
	int res = 1e9 ; 
	Node* tmp = pRoot ;
	Node* ans = nullptr ; 
	while(tmp->val>x)
	{
		tmp=tmp->leftchild ; 
	}
	while(tmp->val<=x)
	{
		if(mini(res,abs(x-tmp->val)))ans=tmp;
		tmp=tmp->rightchild ; 
	}
	tmp = pRoot ; 
	while(tmp->val<x)
	{
		tmp=tmp->rightchild ; 
	}
	while(tmp->val>=x)
	{
		if(mini(res,abs(x-tmp->val)))ans=tmp ; 
		tmp=tmp->leftchild ; 
	}
	return ans ; 
}
signed main()
{
	int a[] = {74,s} ; 

	for(int i=0;i<n;i++)
	{
		insert2BST()
	}
}