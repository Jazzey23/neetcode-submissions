class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> hash;
        for(int i = 0; i < nums.size(); i++){
            hash.insert(nums[i]);
        }
        int temp;
        int length = 1;
        int maxlength = -99;
        for(int i = 0; i < nums.size(); i++){
            temp = nums[i] + 1;
            length = 1;
            while(hash.count(temp) != 0){
                temp += 1;
                length++;
            }
            maxlength = max(length, maxlength);

           
        }

        return maxlength;
        
    }
};
