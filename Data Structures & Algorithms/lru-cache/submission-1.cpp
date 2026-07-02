struct node{
    int val;
    int key;
    node* next = nullptr;
    node* prev = nullptr;
};

class LRUCache {

    node* head;
    node* tail;
    int size;
    int cap;
    unordered_map<int,node*> mymap;

    void moveRight(node* curr){
        


        if(curr == tail || !curr){
            return;
        }

        if(curr == head){
            head = head->next;
            if(head){
                head->prev = nullptr;
            }
        }else if(curr->next != nullptr && curr->prev != nullptr){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        
        curr->next = nullptr;
        curr->prev = nullptr;

        //MOVE NEXT TO TAIL

        if(tail){
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
         
        }

        if (head == nullptr) {
            head = tail;
        }


    }

    void moveLeft(node* curr){  
         if(curr == head || !curr){
            return;
        }

        if(curr == head){
            tail = tail->prev;
            if(tail){
                tail->next = nullptr;
            }
        }else if(curr->next != nullptr && curr->prev != nullptr){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        

        //MOVE NEXT TO TAIL

        if(head){
            head->prev = curr;
            curr->next = head;
            head = curr;
            head->prev = curr;
        }

        if (tail == nullptr) {
            tail = head;
        }


            
    }

    node* addNode(int key, int value){
        node* newNode = new node;
            newNode->key = key;
            newNode->val = value;
           
            if(!head || !tail){
                head = tail = newNode;
            }else{
                if(tail){
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                
            }
        return newNode;

    }

public:
    
    
    LRUCache(int capacity) {
       head = nullptr;
       tail = nullptr;
       size = 0;
       cap = capacity;
       mymap.reserve(capacity); 
    }
    
    int get(int key) {
        auto it = mymap.find(key);
        if(it == mymap.end()){
            return -1;
        }


        node* curr = it->second;

        moveRight(curr);

        return curr->val; 
        
        
    }
    
    void put(int key, int value) {
        //check first if the node exist;;
        auto it = mymap.find(key);

        if(it != mymap.end()){
            //replace value key already exists
            node* curr = it->second;
            curr->val = value;
            moveRight(curr);
            return;
        }

        if(size == cap){

            int replaceKey = head->key;


            auto node = mymap.extract(replaceKey);
           
                node.key() = key;
                mymap.insert(std::move(node));

         

            
           mymap[key] = head; 
            mymap[key]->key = key;
            mymap[key]->val = value;

            moveRight(mymap[key]);


        }else{// not full
            node* newNode = addNode(key, value);
        
            mymap[key] = newNode;

            size++;

            return;
        }

       

    }
};
