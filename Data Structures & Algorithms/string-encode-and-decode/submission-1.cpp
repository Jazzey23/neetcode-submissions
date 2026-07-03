#include <iostream>
#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for(string s : strs){
            encoded_string +=  to_string(s.length()) + "#" + s;
        }

        cout << encoded_string << endl;

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;

        for(int i = 0; i < s.size(); i++){

            string length;
            while(s[i] != '#'){
                length += s[i];
                i++;
            }



            decoded_string.push_back(s.substr(i+1, stoi(length)));

            i += stoi(length);
        
        }


        return decoded_string;
    }
};
