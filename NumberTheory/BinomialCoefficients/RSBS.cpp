#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/contest/785/problem/D

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

vll fact(200002);
vll invfact(200002);

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

void solve()
{
    string s;
    cin >> s;

    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= 200001; i++)
        fact[i] = i * fact[i - 1] % MOD;

    invfact[200001] = power(fact[200001], MOD - 2);

    for (ll i = 200000; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    vll lefts = {0};
    ll right = 0;
    ll res = 0;

    for (char c : s) {
        if (c == '(') lefts[lefts.size() - 1]++;
        if (c == ')') {
            right++;
            ll j = right;

            for (ll i = 0; i < lefts.size(); i++) {
                res = res + power(lefts[i], j) - 1 % MOD;
                j--;
            }

            lefts.push_back(0);
        }
    }

    cout << res;
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
