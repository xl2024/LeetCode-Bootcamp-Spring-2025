class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.length() && s[i] == ' ')
            i++;
        int sign = 1;
        if(i < s.length()){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+')
                i++;
        }
        int num = 0;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            if(sign == 1 && (INT_MAX / 10 == num && INT_MAX % 10 < (s[i] - '0') || INT_MAX / 10 < num))
                num = INT_MAX;
            else if(sign == -1 && (INT_MIN / 10 == num && (- (INT_MIN % 10)) < (s[i] - '0') || INT_MIN / 10 > num)) 
                num = INT_MIN;
            else{
                if(sign == 1 || num > 0)
                    num = num * 10 + (s[i] - '0');
                else
                    num = num * 10 - (s[i] - '0');
                if(sign == -1 && num > 0)
                    num *= -1;
            }
            i++;
        }
        return num;
    }
};