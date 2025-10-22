// https://leetcode.com/problems/meeting-rooms-iii/description/
class Solution {
public:
    int getMinIndex(vector<long>& v) {
        int maxI = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[maxI] < v[i]) maxI = i;
        }

        return maxI;
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long> num(n, 0);

        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> isUsed;
        priority_queue<long, vector<long>, greater<long>> free;

        for (int i = 0; i < n; i++) free.push(i);

        for (auto& m : meetings) {
            while (!isUsed.empty() && isUsed.top().first <= m[0]) {
                free.push(isUsed.top().second);
                isUsed.pop();
            }

            if (!free.empty()) {
                long room = free.top();
                isUsed.push({m[1], room});

                num[room]++;
                free.pop();
            } else {
                auto [time, room] = isUsed.top(); isUsed.pop();
                long delay = time - m[0];

                isUsed.push({m[1] + delay, room});
                num[room]++;
            }
        }
        return getMinIndex(num);
    }
};