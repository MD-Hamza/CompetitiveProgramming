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
    int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        a.push_back(-1e9);
        a.push_back(1e9);
        n += 2;
        sort(a.begin(), a.end());
        int l = 0, r = x + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1, f = 0;
            a[0] = - m, a[n - 1] = x + m;
            for (int i = 1; i < n; ++i) f += max(0, (a[i] - m) - (a[i - 1] + m) + 1);
            if (f >= k) l = m;
            else r = m;
        }
        a[0] = - l, a[n - 1] = x + l;
        int j = 0;
        for (int i = 1; i < n; i++)
    		for (j = max(j, a[i - 1] + l); j <= min((a[i] - l), x) && k; j++)
    			cout << j << ' ', k--;
    	cout << '\n';
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
