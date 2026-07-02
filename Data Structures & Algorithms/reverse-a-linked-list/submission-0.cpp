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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }


        ListNode* curr = head;
        //holds current node
        ListNode* temp;
        ListNode* prev = nullptr;
        while (curr){
            //maintain access to current;
            temp = curr;
            //move current for the next iteration;
            curr = curr->next;
            //change current's next to point at prev
            temp->next = prev;
            //set prev to be curr
            prev = temp;
        }
     
        head = prev;
        

        return head;


    }
};
