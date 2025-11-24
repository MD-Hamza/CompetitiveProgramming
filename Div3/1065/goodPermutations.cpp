#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

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
    int n;
    cin >> n;

    vector<bool> used(n + 1, false);
    vector<int> out(n, -1);

    int i = 1;
    int val = 2;

    while (val <= n) {
        out[i] = val;
        used[val] = true;

        if (val + 2 <= n) {
            out[i + 1] = val + 2;
            used[val + 2] = true;
        }

        i += 3;
        val += 4;
    } 

    val = 3;
    while (i < n && val <= n) {
        out[i] = val;
        used[val] = true;

        if (i + 1 < n && val + 6 <= n) {
            out[i + 1] = val + 6;
            used[val + 6] = true;
        }
        
        i += 3;
        val += 12;
    } 

    val = 1;
    for (int j = 0; j < n; j++) {
        if (out[j] != -1) continue;
        out[j] = val;

        do val++;
        while (used[val]);
    } 

    for (auto num : out) cout << num << " ";
    cout << "\n";
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int _tc = 1;
    cin >> _tc;

    for (int i = 1; i <= _tc; ++i)
    {
        solve();
    }
}
