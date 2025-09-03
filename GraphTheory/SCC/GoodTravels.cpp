#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://www.spoj.com/problems/GOODA/

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

vector<int> visited;

void dfs(ll root, vector<vector<ll>> &adj, vector<ll> &output)
{
    visited[root] = true;
    for (auto v : adj[root]) {
        if (!visited[v])
            dfs(v, adj, output);
    }
    output.push_back(root);
}

void solve()
{
    ll N, M, S, E;
    cin >> N >> M >> S >> E;
    vector<ll> fun(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> fun[i];
    }

    vector<vll> adj(N + 1);
    ll a, b;
    for (ll i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    visited.assign(N + 1, false);
    vector<ll> order;

    for (ll i = 1; i <= N; i++)
        if (!visited[i])
            dfs(i, adj, order);

    vector<vector<ll>> adj_rev(N + 1);
    for (ll v = 1; v <= N; v++)
        for (ll u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(N + 1, false);
    reverse(order.begin(), order.end());
    
    for (auto v : order)
        if (!visited[v]) {
            std::vector<ll> component;
            dfs(v, adj_rev, component);
            ll out = 0;
            if (count(component.begin(), component.end(), S) > 0) {
                for (ll i = 0; i < component.size(); i++) {
                    out += fun[component[i]];
                }
            }

            cout << out << endl;
            return;
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
