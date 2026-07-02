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
        ListNode* sentinel = l1;
        int temp = 0;
        int sum = 0;
        while(l1 && l2){
            l1->val += l2->val + temp;
            sum = l1->val;
            if(l1->val >= 10){
                
                temp = l1->val;
                l1->val %= 10;
                temp  /= 10;
                
            }else{
                temp = 0;
            }

            

            if(l1->next == nullptr && sum >= 10 || (l1->next == nullptr && l2->next != nullptr)){
                ListNode* newNode = new ListNode();
                newNode->next = nullptr;
                l1->next = newNode;
            }
            
            l1 = l1->next;
            l2 = l2->next;

            if(!l1 || !l2){
                cout << "STOPPED AT: " << temp << " " << " With a sum of:" << sum;
            }

        }


        while(sum >= 10 || l2){
             l1->val +=  temp;
             sum = l1->val;

            if(l1->val >= 10){
                
                temp = l1->val;
                l1->val %= 10;
                temp  /= 10;
                
            }

             if(l1->next == nullptr && sum >= 10){
                ListNode* newNode = new ListNode();
                newNode->next = nullptr;
                l1->next = newNode;
            }
            
            l1 = l1->next;
        }



        
        

       

        
       


        return sentinel;
    }
};
