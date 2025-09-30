// https://leetcode.com/problems/split-array-with-minimum-difference/
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long left = 0;
        long long right = 0;

        bool inc = true;
        long long s = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (inc && nums[i] >= nums[i + 1]) {
                s = nums[i];
                inc = false;
            }
            else if (inc == false && nums[i] <= nums[i + 1]) return -1;

            if (inc) left += nums[i];
            else right += nums[i];
        }

        right += nums[nums.size() - 1];
        
        return min(abs(right - left), abs(right - left - 2 * s));
    }
};