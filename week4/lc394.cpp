class Solution {
public:
    string decodeString(string s) {
        // https://leetcode.com/problems/decode-string/solutions/87543/0ms-simple-c-solution
        if(s[0] == '[' && s[s.size()-1] == ']')
            s = s.substr(1, s.size()-2);
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '[')
                cnt++;
        if(cnt == 0)
            return s;
        int l = 0; 
        cnt = 0;
        vector<int> muls = {0};
        bool hasnum = false;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                if(cnt == 0)
                    l = i;
                cnt++;
            }
            else if(s[i] == ']'){
                cnt--;
                if(cnt == 0){
                    string ans0 = decodeString(s.substr(l, i-l+1));
                    for(int j = 0; j < muls[muls.size()-1]; j++)
                        ans = ans + ans0;
                    muls.pop_back();
                    l = i + 1;
                    hasnum = false;
                }
            }
            else if(cnt == 0 && !hasnum && (s[i] >= '0' && s[i] <= '9' || i == s.size()-1) && l <= i){
                if(i == s.size()-1){
                    ans = ans + decodeString(s.substr(l, i-l+1));
                }
                else{
                    ans = ans + decodeString(s.substr(l, i-l));
                    hasnum = true;
                    muls.push_back(s[i] - '0');
                }
                l = i;
            }
            else if(cnt == 0 && s[i] >= '0' && s[i] <= '9'){
                if(hasnum)
                    muls[muls.size()-1] = muls[muls.size()-1] * 10 + s[i] - '0';
                else{
                    hasnum = true;
                    muls.push_back(s[i] - '0');
                }
            }
        }
        return ans;
    }
};