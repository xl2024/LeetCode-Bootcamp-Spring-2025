class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v[n-1] = 1;
        for(int i = 0; i < n-1; i++){
            v[n-2-i] = v[n-1-i] * nums[n-1-i];
        }
        int pre = nums[0];
        for(int i = 1; i < n; i++){
            v[i] = pre * v[i];
            pre = pre * nums[i];
        }
        return v;
    }
};