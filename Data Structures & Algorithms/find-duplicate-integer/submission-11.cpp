class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int index;


        for(int i = 0; i < nums.size(); i++){
            index = abs(nums[i]) - 1;

            if(nums[index] <= -1){
                return abs(nums[i]);
            }else{
                nums[index] *= -1;
            }


        }

        

        return -1;
        
    }
};
