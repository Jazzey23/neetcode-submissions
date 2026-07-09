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
        ListNode* curr = head;
        ListNode* nextn = nullptr;
        ListNode* prevn = nullptr;

        ListNode* minitail = head;
        ListNode* prevminitail = nullptr;
        ListNode* newHead = nullptr;
        
        //Rotate
        //Save tail pointer
        //Rotate
        //connect 


        while(curr){


             minitail = curr;
             prevn = nullptr;
            
           

            for(int i = 0; i < k; i++){
                if(!newHead && i == k-1){
                    newHead = curr;
                }
                if(curr == nullptr){

                    curr = prevn;
                    nextn = nullptr;
                    prevn = nullptr;
                    while(curr){
                        nextn = curr->next;
                        curr->next = prevn;
                        prevn = curr;
                        curr = nextn;
                    } 

                 
            
                    prevminitail->next = prevn;
                    return newHead;

                }
                
                nextn = curr->next;
                curr->next = prevn;
                prevn = curr;
                curr = nextn;
            }
           

            if(prevminitail != nullptr){
                cout<<prevminitail->val<< endl;
                prevminitail->next = prevn;
            }            



            prevminitail = minitail;

        }
      

        return newHead;
    }
};
