#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/2137/problem/E

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

void mex(vector<int> &a) {
    unordered_map<int, int> freq;
    int m = 0;
    for (auto as : a) {
        if (m == as) m++;
        freq[as]++;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] > m || freq[a[i]] > 1) a[i] = m;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    mex(a);

    if (k % 2 == 0) {
        mex(a);
    } else if (k > 1 && k % 2 == 1) {
        mex(a);
        mex(a);
    }

    long long s = accumulate(a.begin(), a.end(), 0LL);
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
