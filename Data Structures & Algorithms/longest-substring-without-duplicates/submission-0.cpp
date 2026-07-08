class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0; 
        int j = 0;
        int maxA = 0;
        int curr = 0;

        unordered_set<char> sub;

        while(j < s.length()){
            if(sub.count(s[j]) == 0){
                sub.insert(s[j]);
                j++;
                curr++;
            }else{
                while(sub.count(s[j]) > 0){
                    sub.erase(s[i]);
                    i++;
                    curr--;
                }
            }

            maxA = max(curr, maxA);
        }


        return maxA;
    }
};
