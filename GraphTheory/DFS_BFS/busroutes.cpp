// https://leetcode.com/problems/bus-routes/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = 0;
        for (int route : routes)
            for (int stop : route)
                n = max(n, route);

        vector<vector<int>> adj(n + 1);

        for (int route : routes)
            for (int i = 0; i < route.size() - 1; i++) {
                adj[route[i]].push_back(route[i + 1]);
            }

        queue<pair<int, int>> q;
        q.push({source, 0});

        while (!q.empty()) {
            int s = q.pop();
            for (int children : adj[s]) {
                q.push(children);
            }
        }
    }
};