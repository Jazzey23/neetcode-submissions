/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

    Node* createNode(Node* nextptr, int valp){
        Node* newNode = new Node(valp);
        newNode->next = nextptr;
    
        


      

        return newNode;
    }



public:
    Node* copyRandomList(Node* head) {
        Node* temp;
        Node* sentinel = nullptr;
        Node* curr = head;
        Node* prev = nullptr; 
        

        unordered_map<Node* , Node*> hmap;
     

        //creates the new list

        while(curr){
            temp = createNode(curr->next, curr->val);
           
            hmap[curr] = temp;
            

            if(sentinel == nullptr){
                sentinel = temp;
            }
            if(prev != nullptr){
                prev->next = temp;
            }

            prev = temp;
            curr = curr->next;
        }


        curr = sentinel;


        while(head){
            if(head->random != nullptr){
                hmap[head]->random = hmap[head->random];
            }else{
                hmap[head]->random = nullptr;
            }

            head = head->next;
        }
       
 
        return sentinel;
    }
};
