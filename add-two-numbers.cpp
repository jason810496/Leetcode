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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans1 = l1;
        ListNode *ans2 = l2;
        ListNode *pre = NULL;
        int carry = 0;
        while( l1 && l2 ){
            int cur = l1->val + l2->val + carry;
            l1->val = cur%10;
            l2->val = cur%10;
            carry = cur/10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if( l1 ){
            while( l1 ){
                int cur = l1->val+ carry;
                l1->val = cur%10;
                carry = cur/10;
                pre = l1;
                l1 = l1->next;
            }
            if( carry > 0 ) pre->next = new ListNode(carry);
            return ans1;
        }
        if( l2 ){
            while( l2 ){
                int cur = l2->val+ carry;
                l2->val = cur%10;
                carry = cur/10;
                pre = l2;
                l2 = l2->next;
            }
            if( carry > 0 ) pre->next = new ListNode(carry);
            return ans2;
        }


        if( carry > 0 ){
            pre->next = new ListNode(carry);
        }
        return ans1;
    }
};