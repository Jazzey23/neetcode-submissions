class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> returnable;
        unordered_map<int, int> frq;
        unordered_map<int, vector<int>> kmap;

        for(int i = 1; i <= nums.size(); i++){
            kmap[i];
        }
        
        for(int num : nums){
            frq[num]++;
        }


        for(const auto& [key, value] : frq){
            kmap[value].push_back(key);
        }

        for(int i = nums.size(); i > 0; i--){
            for(int num : kmap[i]){
                
                returnable.push_back(num);
                k--;

            }

            if(k == 0){
                    break;
            }


        }

        



        return returnable;

    }
};
