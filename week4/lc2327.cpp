class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int M = 1000000007, offset = 0;
        long dp[forget], s = 0;
        for(int i = 0; i < forget; i++)
            if(i == delay - 1)
                dp[i] = 1;
            else
                dp[i] = 0;
        for(int j = delay; j < n; j++){
            s = (s + dp[(offset+delay-1)%forget] - dp[(offset+forget-1)%forget] + M) % M;
            offset = (offset + forget - 1) % forget;
            dp[offset] = s;
        }
        for(int i = 1; i < forget; i++)
            dp[offset] = (dp[offset] + dp[(offset+i)%forget]) % M;
        return int(dp[offset]);
    }
};