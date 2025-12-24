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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll s = 0;
    for (int i = 0; i < n - 1; i++) s += (abs(a[i] - a[i + 1]));
    
    int maxDiff = abs(a[0] - a[1]);
    int prevDiff = abs(a[0] - a[1]);
    int j = 0;

    for (int i = 1; i < n - 1; i++) {
        int c = abs(a[i + 1] - a[i]) + prevDiff - abs(a[i + 1] - a[i - 1]);
        if (c > maxDiff) {
            j = i;
            maxDiff = c;
        }

        prevDiff = abs(a[i + 1] - a[i]);

    }

    if (maxDiff < abs(a[n - 1] - a[n - 2])) {
        s -= abs(a[n - 1] - a[n - 2]);
    } else if (j > 0) {
        s -= (abs(a[j] - a[j - 1]) + abs(a[j] - a[j + 1]));
        s += (abs(a[j - 1] - a[j + 1]));
    } else {
        s -= abs(a[0] - a[1]);
    }

    cout << s << endl;
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
