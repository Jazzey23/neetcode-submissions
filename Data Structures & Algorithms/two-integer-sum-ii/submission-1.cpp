class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> answer;
        int sum;
        while(true){
            sum = numbers[l] + numbers[r];
            if(sum == target){
                answer.push_back(l + 1);
                answer.push_back(r + 1);
                return answer;
            }

            if(sum > target){
                r--;
            }else{
                l++;
            }
        }

    }
};
