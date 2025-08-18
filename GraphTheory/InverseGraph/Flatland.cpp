#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/190/problem/E

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

    set<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> cities;
    queue<int> q;
    set<int> unvisited;

    for (int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        res++;
        cities.push_back(vector<int>());
        q.push(i);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            auto it = unvisited.begin();
            while (it != unvisited.end()) {
                int j = *it;
                if (visited[j]) { ++it; continue; }
                if (adj[v].find(j) != adj[v].end()) { ++it; continue; }
                q.push(j);
                cities.back().push_back(j);
                it = unvisited.erase(it);
                visited[j] = true;
            }
        }
    }

    cout << res << endl;
    for (int i = 0; i < res; i++) {
        cout << cities[i].size() << " ";
        for (int j = 0; j < cities[i].size(); j++) {
            cout << cities[i][j] << " ";
        }
        cout << "\n";
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
