class Solution {

public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        int key;
        vector<int> hashed(size, -1);

        cout << "Loop" << endl;

        for(int i = 0; i < size; i++){
           key = ((nums[i] % size) + size) % size;

            cout << "Loop" << i << endl;
            
            if(hashed[key] == -1){
                hashed[key] = nums[i];
            }else{
                while(hashed[key] != -1){
                
                    if(hashed[key] == nums[i]){
                        return true;
                    }else{
                        key++;
                    }
                    if(key == size){
                        key = 0;
                    }

                }

                hashed[key] = nums[i];

            }
        

        }

        return false;

    }
};