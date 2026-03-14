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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;


        int count = 1;
        ListNode* kk = head;
        ListNode* firstnode = nullptr;
        ListNode* lastnode = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;


        while(k){
            if(count == k){
                lastNode = kk->next;
                while(count > 0){
                    ListNode* temp = curr;
                    curr->next = prev;
                    prev = curr;
                    curr = temp->next;
                    count--;
                }
                count = 1;
            }else{
                count++;
            }
            kk = kk->next;
        }

    }
};
