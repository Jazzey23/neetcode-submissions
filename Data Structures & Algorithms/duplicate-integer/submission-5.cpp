class Solution {

public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        int key;
        unordered_set<int> hashed;

        for(int i = 0; i < size; i++){
           if(hashed.count(nums[i]) == 0){
                hashed.insert(nums[i]);
           }else{
                return true;
           }
        }

       

        return false;

    }
};