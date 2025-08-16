#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int minCost(vector<vector<int>>& grid) {
    vector<vector<int>> d(grid.size(), vector<int>(grid[0].size(), 1e9));
    deque<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    q.push_back({0, 0});
    d[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int c = grid[x][y] != (i + 1);

            if (0 <= nx && nx < n && 0 <= ny && ny < m && d[nx][ny] > d[x][y] + c) {
                d[nx][ny] = d[x][y] + c;
                c ? q.push_back({nx, ny}) :q.push_front({nx, ny});
            }
        }
    }

    return d[n - 1][m - 1];
    }

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout << minCost(grid) << endl;
}
