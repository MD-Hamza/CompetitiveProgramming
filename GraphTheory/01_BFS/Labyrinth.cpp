#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/1063/problem/B

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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

void solve()
{
    int n, m, r, c, x, y;
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;

    r--;c--;

    char l[n][m];
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            l[i][j] = s[j];
        }
    }

    vector<vector<int>> d(n, vector<int>(m, 1e9));
    queue<tuple<int, int, int, int>> q;

    d[r][c] = 0;
    q.push({r, c, x, y});
    int res = 1;

    while (!q.empty()) {
        auto [sx, sy, lx, ly] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            if (ly == 0 && i == 2) continue;
            if (lx == 0 && i == 1) continue;

            int nx = sx + dx[i];
            int ny = sy + dy[i];
            int tlr = (x - lx) + (y - ly) + (i == 1) + (i == 2);


            if (nx >= 0 && nx < n && ny >= 0 && ny < m && l[nx][ny] != '*' && d[nx][ny] > tlr) {
                res += (d[nx][ny] == 1e9);
                d[nx][ny] = tlr;
                q.push({nx, ny, i == 1 ? lx - 1 : lx, i == 2 ? ly - 1 : ly});
            }
        }
    }

    cout << res;
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int _tc = 1;
    //cin >> _tc;

    for (int i = 1; i <= _tc; ++i)
    {
        solve();
    }
}
