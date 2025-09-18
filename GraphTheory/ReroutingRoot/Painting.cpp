#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/1187/problem/E

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

vector<vector<int>> adj;

ll dfs(int root, int p, vector<ll> &sub) {
    ll s = 0;
    for (auto v : adj[root]) {
        if (v == p) continue;
        s += dfs(v, root, sub);
        sub[root] += sub[v];
    }

    sub[root]++;
    return s + sub[root];
}

ll maxSum(int root, int p, vector<ll> &sub, ll s) {
    ll maxS = s;
    for (auto v : adj[root]) {
        if (v == p) continue;
        ll tempRoot = sub[root];
        ll tempV = sub[v];

        sub[v] = sub[root];
        sub[root] -= tempV;

        maxS = max(maxS, maxSum(v, root, sub, s - 2 * tempV + tempRoot));

        sub[root] = tempRoot;
        sub[v] = tempV;
    }

    return maxS;
}

void solve()
{
    int n, u, v;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<ll> sub(n);
    ll s = dfs(0, 0, sub);

    cout << maxSum(0, 0, sub, s) << endl; 
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
