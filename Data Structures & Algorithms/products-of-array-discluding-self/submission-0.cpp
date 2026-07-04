class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        vector<int> prefix;
        vector<int> output;

        for(int i = 0; i < nums.size(); i++){
            if(i != 0){
                prefix.push_back(nums[i] * prefix[i-1]);
               
            }else{
                prefix.push_back(nums[i]);
            }
        }
        for(int i = nums.size()-2; i >= 0; i--){
           nums[i] *= nums[i+1];
        }

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                output.push_back(nums[i+1]);
            }else if(i == nums.size() - 1){
                output.push_back(prefix[i-1]);
            }else{
                output.push_back( prefix[i-1] * nums[i+1]);
            }
        }
      



        return output;
    }
};
