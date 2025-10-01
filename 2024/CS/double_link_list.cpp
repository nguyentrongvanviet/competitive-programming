#include<iostream> 
using namespace std ;

struct DNode
{
	int data ; 
	DNode* pNext , pPrev ; 
}; 
void insert_x_before_k(DNode* head, int x ,int k)
{
	if(head->data==k)
	{
		DNode* A = new DNode ; 
		A->data = x ;   
		head->pPrev = A;
		A->pNext = head ;  
	}
	else
	{
		while(head)
		{
			if(head->data==k)
			{
				DNode* A = new DNode ; 
				A->data = x ; 
				A->pPrev = head->pPrev ; 
				A->pNext = head ; 
				head->pPrev = A ; 
				break;
			}
		}
	}
}
int main()
{
	
}