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
        return helper(l1,l2,0);
    }

    ListNode* helper(ListNode *l1 , ListNode *l2,int carry){
        if( !l1 && !l2 ){
            if( carry ){
                return new ListNode(carry);
            }
            return nullptr;
        }
        if( !l1 ){
            int total = l2->val + carry;
            int cur = total % 10;
            carry = total / 10;

            l2->val = cur;
            l2->next = helper(l1,l2->next,carry);
            return l2;
        }
        if( !l2){
            int total = l1->val + carry;
            int cur = total % 10;
            carry = total / 10;

            l1->val = cur;
            l1->next = helper(l1->next,l2,carry);
            return l1;
        }
        int total = l1->val + l2->val + carry;
        int cur = total % 10;
        carry = total / 10;

        l1->val = cur;
        l1->next = helper(l1->next,l2->next,carry);

        return l1;
    }
};