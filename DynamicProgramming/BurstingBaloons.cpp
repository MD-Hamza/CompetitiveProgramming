// https://leetcode.com/problems/burst-balloons/
class Solution {
private:
    int n;
    int memo[501][501];
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for(int x: nums) 
			arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
        return dfs(arr, 1, arr.size() - 2);
    }

    // dfs returning max prod in range i, j
    int dfs(vector<int>& nums, int i, int j) {
        if (memo[i][j] != 0) return memo[i][j];
        int prod = nums[i];
        // Base case
        if (i > j) return 0;
        if (i == j) {
            if (i > 0) prod *= nums[i - 1];
            if (i < n) prod *= nums[i + 1];
            return prod;
        }

        int maxProd = 0;
        for (int k = i; k <= j; k++) {
            prod = nums[k];
            if (i > 0) prod *= nums[i - 1];
            if (j < n - 1) prod *= nums[j + 1];

            prod += dfs(nums, i, k - 1);
            prod += dfs(nums, k + 1, j);

            maxProd = max(maxProd, prod);
        }
        memo[i][j] = maxProd;
        return maxProd;
    }
};