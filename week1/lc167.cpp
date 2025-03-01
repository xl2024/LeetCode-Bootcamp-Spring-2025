class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        int sum = numbers[low] + numbers[high];
        while(sum != target){
            if(sum < target)
                low = low + 1;
            else
                high = high - 1;
            sum = numbers[low] + numbers[high];
        }
        vector<int> v={low + 1, high + 1};
        return v;
    }
};