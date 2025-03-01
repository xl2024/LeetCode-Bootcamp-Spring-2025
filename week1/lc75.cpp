class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i0=0, i1=0, i2=nums.size()-1;
        while(i1 <= i2){
            if(nums[i1] == 0){
                swap(nums[i0++], nums[i1++]);
            }
            else if(nums[i1] == 1){
                i1++;
            }
            else{
                swap(nums[i1], nums[i2--]);
            }
        }
    }
};