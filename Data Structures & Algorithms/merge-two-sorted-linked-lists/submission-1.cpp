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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }else if(list2 == nullptr){
            return list1;
        }
        ListNode* curr = list1->val < list2->val ? list1 : list2;

        ListNode* sentinel = curr;

        //2nd head
        ListNode* curr2 = curr == list1 ? list2 : list1;
        ListNode* temp = nullptr;
        

        
        while(curr){
            if(curr2 == nullptr){
                break;
            }

            if(curr->next == nullptr){
                temp = curr2->next;
                curr2->next = curr->next;
                curr->next = curr2;
                curr2 = temp;
                continue;
            }

            if(curr->next->val >= curr2->val){
                //save curr2's next;
                temp = curr2->next;
                curr2->next = curr->next;
                curr->next = curr2;
                curr2 = temp;
            }
            curr = curr->next;
    }
           
         
        return sentinel;


    }
};
