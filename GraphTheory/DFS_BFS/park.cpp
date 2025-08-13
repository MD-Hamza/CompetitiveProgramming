#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/problemset/problem/580/C

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

const int MAXN = 1e5 + 1;
vi adj[MAXN];
bool visited[MAXN];
bool cats[MAXN];

ll dfs(int root, int c, int m) {
    visited[root] = true;
    ll res = 0;
    if (adj[root].size() == 1 && visited[adj[root][0]] && c <= m) res += 1;

    for (int v : adj[root]) {
        if (!visited[v] && cats[v] + c <= m) {
            res += dfs(v, cats[v] ? c + 1 : 0, m);
        }
    }
    
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cats[i];
    
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout <<  dfs(1, cats[1], m) << endl;
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
