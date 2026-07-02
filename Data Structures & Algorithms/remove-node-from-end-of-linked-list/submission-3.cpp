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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = 0;
        ListNode* curr = head;
        while(curr){
            index++;
            curr = curr->next;
        }
        index -= n;

        

        if(index < 0){
            return head;
        }else{
            curr = head;
            ListNode* prev;
            for(int i = 0; i < index; i++){
                prev = curr;
                curr = curr->next;
            }

            if(curr == head){
                prev = head->next;
                delete head;
                return prev;
            }


            prev->next = curr->next;
            delete curr;
            return head;

        }

    }
};
