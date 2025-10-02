// https://leetcode.com/problems/cherry-pickup/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        pair<int, int> START = {0, 0};
        int maxCherries = 0;

        pickup(grid, START.first, START.second, 0, maxCherries, true);
        return maxCherries; 
    }

    void pickup(vector<vector<int>>& grid, int i, int j, int cherries, int& maxCherries, bool down) {
        int N = grid.size();
        int prev = grid[i][j];

        if (grid[i][j] != -1) {
            cherries += grid[i][j];
            grid[i][j] = 0;
        }

        if (down) {
            if (i + 1 < N && grid[i + 1][j] != -1)
                pickup(grid, i + 1, j, cherries, maxCherries, down);
            
            if (j + 1 < N && grid[i][j + 1] != -1)
                pickup(grid, i, j + 1, cherries, maxCherries, down);
            
            if (i + 1 == N && j + 1 == N) {
                pickup(grid, i, j, cherries, maxCherries, !down);
            }
        } else {
            if (i - 1 >= 0 && grid[i - 1][j] != -1)
                pickup(grid, i - 1, j, cherries, maxCherries, down);
            
            if (j - 1 >= 0 && grid[i][j - 1] != -1) {
                pickup(grid, i, j - 1, cherries, maxCherries, down);
            }

            if (i == 0 && j == 0) maxCherries = max(maxCherries, cherries);
        }

        grid[i][j] = prev;
    }
};