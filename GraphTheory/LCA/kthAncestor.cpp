#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

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
int l;

TreeAncestor(int n, vector<int>& parent) {
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1, -1));

    for (int v = 0; v < n; v++)
        up[v][0] = parent[v];

    for (int j = 1; j <= l; j++) {
        for (int v = 0; v < n; v++) {
            int p = up[v][j-1];
            if (p != -1)
                up[v][j] = up[p][j-1];
        }
    }
}

int getKthAncestor(int node, int k) {
    for (int j = 0; j <= l; j++) {
        if (k & (1 << j)) {
            node = up[node][j];
            if (node == -1) return -1;
        }
    }
    return node;
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}
