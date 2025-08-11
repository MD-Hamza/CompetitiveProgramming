#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://codeforces.com/problemset/problem/154/B

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

vector<ll> factorization(ll x, vector<ll>& smallestPrime) {
    vector<ll> factors;

    while (x > 1) {
        ll p = smallestPrime[x];
        factors.push_back(p);
        x /= p;
    }

    return factors;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    
    vector<ll> smallestPrime(n + 1, 0);
    vector<bool> active(n + 1, 0);
    vector<ll> factors(n + 1, 0);
    
    for (ll i = 2; i <= n; i++) {
        if (!smallestPrime[i]) {
            smallestPrime[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                smallestPrime[j] = i;
            }
        }
    }

    char add;
    ll num;

    for (ll i = 0; i < m; i++) {
        cin >> add >> num;
        if (add == '+' && active[num]) cout << "Already on" << endl;
        if (add == '-' && !active[num]) cout << "Already off" << endl;
        else if (add == '-') {
            vector<ll> fc = factorization(num, smallestPrime);
            for (ll f : fc)
                factors[f] = 0;
            active[num] = false;
            cout << "Success" << endl;
        }

        if (add == '+' && !active[num]) {
            vector<ll> fc = factorization(num, smallestPrime);
            bool conflict = false;

            for (ll f : fc) {
                if (factors[f]) {
                    cout << "Conflict with " << factors[f] << endl;
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                for (ll f : fc) {
                    factors[f] = num;
                }
                active[num] = true;
                cout << "Success" << endl;
            }
        }
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
