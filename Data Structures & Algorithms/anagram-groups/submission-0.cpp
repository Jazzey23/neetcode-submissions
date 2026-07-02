class Solution {
    bool checkAnagram(string s, string t){
        unordered_map<char, int> setA;




        for(char c : s){
            setA[c]++;
        }

       
        for(char c : t){
            setA[c]--;
        }



        for (const auto& [key, value] : setA) {
            if(value != 0){
                cout << "false" ;
                return false;
            }
        }
        return true;

    }



public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> a;

        
        
        for(string s : strs){
            if(a.empty()){
                a.insert(a.begin(), vector<string>{s});
                continue;
            }

            
            for(int i = 0; i < a.size(); i++){
                if(checkAnagram(s, a[i][0])){
                    a[i].insert(a[i].begin(), s);
                    break;
                }else if(i == a.size()-1){
                    a.insert(a.begin(), vector<string>{s});
                    break;
                }
            }
        
        }
        
        


        return a;

    }
};
