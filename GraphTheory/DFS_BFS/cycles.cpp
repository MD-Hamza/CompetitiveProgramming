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

const int MAXN = 1000000;
vector<int> adj[MAXN];

ll m, n;

char dir(int v, int u) {
    if (v % m > u % m) return 'L';
    if (v % m < u % m) return 'R';
    if (v / m > u / m) return 'U';
    if (v / m < u / m) return 'D';
    return ' ';
}

string bfs(int root, int start, int k, string seq) {
    if (k == 0 && root == start) return seq;
    if (k == 0) return "";

    for (int u : adj[root]) {
        string res = bfs(u, start, k - 1, seq + dir(root, u));
        if (res != "") return res;
    }
    return "";
}

void solve()
{
    ll k;
    cin >> n >> m >> k;
    char board[n][m];
    int start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'X')
                start = i * m + j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && board[i + 1][j] != '*') adj[i * m + j].push_back(i * m + m + j);
            if (j - 1 >= 0 && board[i][j - 1] != '*') adj[i * m + j].push_back(i * m + j - 1);
            if (j + 1 < m && board[i][j + 1] != '*') adj[i * m + j].push_back(i * m + j + 1);
            if (i - 1 >= 0 && board[i - 1][j] != '*') adj[i * m + j].push_back(i * m - m + j);
        }
    }

    string res = bfs(start, start, k, "");
    res = res == "" ? "IMPOSSIBLE" : res;
    cout << res;
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
