#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/208/problem/E

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

vector<vector<int>> up;
vector<int> parents;
vector<vector<int>> children;

int n, l;

void preprocess()
{
    for (int i = 1; i <= n; i++)
        up[i][0] = parents[i - 1];
    
    for (int j = 1; j <= l; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int ancestors(int u, int p) {
    queue<int> q;
    q.push(u);
    int depth = 0;
    while (!q.empty()) {
        for (int i = q.size(); i >= 0; i--) {
            depth++;
            int v = q.front(); q.pop();
            for (int m : children[v]) {
                q.push(m);
            }
        }
        cout << depth << endl;
        if (depth == p)
            return q.size();
    }
    return 0;
}

void solve()
{
    int m, p, v;
    cin >> n;

    l = ceil(log2(n + 1));
    up.assign(n + 1, vector<int>(l + 1));
    children.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> p;
        parents.push_back(p);
        children[p].push_back(i + 1);
    }
    
    preprocess();
    cin >> m;

    for (int j = 0; j < m; j++) {
        cin >> v >> p;
        for (int j = l; j >= 0; j--) {
            if (p & (1 << j)) {
                v = up[v][j];
            }
        }
        if (v == 0) cout << 0 << " ";
        else cout << ancestors(v, p) << " ";
    }
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
