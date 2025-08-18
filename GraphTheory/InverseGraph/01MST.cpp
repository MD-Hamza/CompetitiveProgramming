#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/problemset/problem/1242/B

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


void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<bool> visited(n + 1, false);
    set<int> ones[n + 1];

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        ones[u].insert(v);
        ones[v].insert(u);
    }

    int res = 0;

    set<int> unvisited;
    for (int i = 1; i <= n; i++) unvisited.insert(i);

    vector<int> removal;
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        res++;
        q.push(i);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int j : unvisited) {
                if (visited[j]) continue;
                if (ones[v].find(j) != ones[v].end()) continue;
                q.push(j);
                removal.push_back(j);
                visited[j] = true;
            }

            while(!removal.empty())
                unvisited.erase(removal.back()), removal.pop_back();
        }
    }

    cout << res - 1;
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
