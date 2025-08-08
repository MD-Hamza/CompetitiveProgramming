#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/problemset/problem/300/C
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

const int MAXN = 1e6 + 1;
vll fact(MAXN);
vll invFact(MAXN);

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = (a * a % MOD);
        b >>= 1;
    }
    return res;
}

ll nCr(int n, int r) {
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;

    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[n] = power(fact[n], MOD - 2);
    
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    ll res = 0;

    for (int i = 0; i <= n; i++) {
        int digitSum = i * a + (n - i) * b;
        bool good = true;

        while (digitSum > 0) {
            if (digitSum % 10 != a && digitSum % 10 != b) {
                good = false;
                break;
            }
            digitSum /= 10;
        }
        if (good) {
            res = (res + nCr(n, i)) % MOD;
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
