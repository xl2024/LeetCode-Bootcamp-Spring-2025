class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/92007/sliding-window-algorithm-template-to-solve-all-the-leetcode-substring-search-problem
        vector<int> ans;
        map<char,int> ins, dict;
        set<char> outs;
        for(int i = 0; i < p.size(); i++){
            dict[p[i]] = 0;
            if(!ins.contains(p[i]))
                ins[p[i]] = 1;
            else
                ins[p[i]]++;
        }
        for(int i = 0; i < p.size(); i++)
            if(dict.contains(s[i])){
                dict[s[i]] += 1;
            }
        for(int i = 0; i < p.size(); i++)
            if(dict[p[i]] != ins[p[i]] && !outs.contains(p[i]))
                outs.insert(p[i]);
        if(outs.size() == 0)
            ans.push_back(0);
        for(int i = p.size(); i < s.size(); i++){
            if(dict.contains(s[i-p.size()]))
                dict[s[i-p.size()]]--;
            if(dict.contains(s[i])){
                dict[s[i]]++;
            }
            if(dict.contains(s[i-p.size()])){
                if(dict[s[i-p.size()]] == ins[s[i-p.size()]] && outs.contains(s[i-p.size()]))
                    outs.erase(s[i-p.size()]);
                else if(dict[s[i-p.size()]] != ins[s[i-p.size()]] && !outs.contains(s[i-p.size()]))
                    outs.insert(s[i-p.size()]);
                }
            if(dict.contains(s[i])){
                if(dict[s[i]] == ins[s[i]] && outs.contains(s[i]))
                    outs.erase(s[i]);
                else if(dict[s[i]] != ins[s[i]] && !outs.contains(s[i]))
                    outs.insert(s[i]);
            }
            if(outs.size() == 0)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};