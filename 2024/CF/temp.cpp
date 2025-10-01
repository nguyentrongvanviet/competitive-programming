/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head ;
        ListNode* ans = nullptr ; 
        ListNode* res  ; 
        int pre = head->val; 
        head=head->next ; 
        bool ok = 1 ; 
        while(head)
        {
			if(head->val!=pre)
            {
            	if(ok)
            	{
	                if(!ans)
	                {
	                    ans = new ListNode(); 
	                    res = ans ;
	                    ans->val = pre ;
	                }
	                else
	                {
	                    ans->next = new ListNode() ; 
	                    ans->next->val = pre ;
	                    ans=ans->next ;  
	                }
            	}
            	ok = 1; 
            }
            else
            {
            	ok = 0 ; 
            }
            pre = head->val; 
            head=head->next ; 
        }
        return res ; 
    }
};