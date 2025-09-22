// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> out;

        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);

            if (i - k + 1 >= 0) {
                out.push_back(q.front());
                if (q.front() == nums[i-k+1]) q.pop_front();
            }
        }

        return out;
    }
};
