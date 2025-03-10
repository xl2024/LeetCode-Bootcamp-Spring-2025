class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        bool in_word = false;
        for(int i = 0; i < s.length(); i++){
            if(!in_word && s[i] != ' '){
                start = i;
                in_word = true;
            }
            else if(in_word && (s[i] == ' ' || i == s.length()-1)){
                int end = i;
                if(end == s.length()-1)
                    end++;
                for(int j = 0; j < (end-start)/2; j++){
                    swap(s[start+j], s[end-1-j]);
                }
                in_word = false;
            }
        }
        for(int i = 0; i < s.length()/2; i++)
            swap(s[i], s[s.length()-1-i]);
        int start_index = 0;
        while(start_index < s.length() && s[start_index] == ' ') 
            start_index++;
        start = 0;
        bool spaced = false;
        for(int i = start_index; i < s.length(); i++){
            if(s[i] != ' '){
                s[start++] = s[i];
                spaced = false;
            }
            else if(!spaced){
                s[start++] = ' ';
                spaced = true;
            }
        }
        if(s[start-1] == ' ')
            start--;
        return s.substr(0, start);
    }
};