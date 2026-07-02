class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int> twoIndices;
        
        int key;

        for(int i = 0; i < nums.size(); i++){
            key = target - nums[i];

            cout << key << endl;
            
            auto it = mymap.find(key);
              
            if(it != mymap.end() && it->second != i){
                 cout << "Check" << endl;
                twoIndices = {it->second, i};
                return twoIndices;   
            }else{
                mymap.insert({nums[i], i});
            }


        }

          

        return twoIndices;

    
    }
};
