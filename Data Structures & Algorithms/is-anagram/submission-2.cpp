class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> hmap;

        for(int i = 0; i < s.length(); i++){
            hmap.insert({s[i], 0});
            hmap[s[i]]++;
        }

        for(int i = 0; i < t.length(); i++){
            hmap[t[i]]--;
        }

         for (const auto& [key, value] : hmap) {
            if(value != 0){
                return false;
            }
        }
        
        return true;
    }
};
