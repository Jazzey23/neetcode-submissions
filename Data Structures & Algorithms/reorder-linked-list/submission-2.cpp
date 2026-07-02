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
   ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* temp;

        while(curr){
            temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
            
        }   


        return prev;

   }

public:
    void reorderList(ListNode* head) {
        if(head->next == nullptr || head == nullptr){
            return; 
        }

        int n = 0;
        ListNode* curr = head;
        ListNode* splitList;

        while(curr){
            n++;
            curr = curr->next;
        }

        curr = head;
         
        for(int i = 1; i < n/2; i++){
            curr = curr->next;
        }

        splitList = curr->next;
       
        curr->next = nullptr;
        cout << splitList->val << " ";
        splitList = reverseList(splitList);

        curr = head;
        ListNode* temp;
        ListNode* prev;
        
        
        while(curr){
            temp = splitList->next;
            splitList->next = curr->next;
            curr->next = splitList;
            splitList = temp;

            prev = curr->next;
            curr = curr->next->next;
            
           
        }
        


        if(splitList != nullptr){
            prev->next = splitList;
            splitList->next = nullptr;
        }    

      
       


        



    }




};
