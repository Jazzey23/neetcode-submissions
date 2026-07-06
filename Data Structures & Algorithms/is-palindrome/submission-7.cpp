class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        if(s == " "){
           return true;
        }
        if(s.length() == 1){
            return true;
        }

        for(int k = 0; k < s.length(); k++){
            if(isdigit(s[k]) || isalpha(s[k]) || s[k] == ' '){
                break;
            }
            
            if(k == s.length() - 1){
                return true;
            }
        }


        while(i <= j){
            cout << s[i] << " " << s[j] << endl;
            while(s[i] == ' '){
                i++;
            }
            while(s[j] == ' '){
                j--;
            }
            while(!isdigit(s[j]) && !isalpha(s[j])){
                j--;
            }
            while(!isdigit(s[i]) && !isalpha(s[i])){
                i++;
            }

            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};
