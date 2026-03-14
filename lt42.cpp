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

//proposed solution 
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
        ListNode* temp = head;
        for(int i=0 ; i<k ; i++){
            if(!temp) return head;
            temp = temp->next;    
        }

        ListNode* prev=nullptr, *curr=head, *next=nullptr;
        for(int i=0 ; i<k ; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //here the problem of first node is solved 
        head->next = reverseKGroup(temp, k);
        //also the last node problwm too
        return prev;
    }
};
