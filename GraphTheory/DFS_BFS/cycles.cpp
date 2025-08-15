#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/769/problem/C

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

int n, m, k;
const int MAXN = 1000;
char board[MAXN][MAXN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string dirChar = "DLRU";

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '*';
}

void solve()
{
    cin >> n >> m >> k;
    int steps[n][m];

    int sx, sy;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            steps[i][j] = -1;
            if (board[i][j] == 'X') {
                sx = i;
                sy = j;
                steps[i][j] = 0;
            }
        }
    }

    queue<pii> q;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();


        if (i + 1 < n && board[i + 1][j] != '*' && steps[i + 1][j] == -1) {
            steps[i + 1][j] = steps[i][j] + 1;
            q.push({i + 1, j});
        }

        if (j - 1 >= 0 && board[i][j - 1] != '*' && steps[i][j - 1] == -1) {
            steps[i][j - 1] = steps[i][j] + 1;
            q.push({i, j - 1});
        }

        if (j + 1 < m && board[i][j + 1] != '*' && steps[i][j + 1] == -1) {
            steps[i][j + 1] = steps[i][j] + 1;
            q.push({i, j + 1});
        }

        if (i - 1 >= 0 && board[i - 1][j] != '*' && steps[i - 1][j] == -1) {
            steps[i - 1][j] = steps[i][j] + 1;
            q.push({i - 1, j});
        }
    }

    string res;
    int cx = sx, cy = sy;
    for (int step = 0; step < k; step++) {
        bool moved = false;
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (!valid(nx, ny)) continue;
            int rem = k - step - 1;
            if (steps[nx][ny] != -1 && steps[nx][ny] <= rem && (rem - steps[nx][ny]) % 2 == 0) {
                res += dirChar[d];
                cx = nx; cy = ny;
                moved = true;
                break;
            }
        }
        if (!moved) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << res << "\n";
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int _tc = 1;
    // cin >> _tc;

    for (int i = 1; i <= _tc; ++i)
    {
        solve();
    }
}
