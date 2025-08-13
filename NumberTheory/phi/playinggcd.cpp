#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://www.spoj.com/problems/NAJPWG/

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

const int MAXN = 100001;
ll phi[MAXN];
ll prefix[MAXN];

void init() {
    for (int i = 1; i < MAXN; i++) phi[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        prefix[i] = prefix[i - 1] + i - phi[i];
    }
}

void solve(int c)
{
    cout << "Case " << c << ": ";
    ll N;
    cin >> N;

    cout << prefix[N] << '\n';
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int _tc = 1;
    cin >> _tc;

    init();

    for (int i = 1; i <= _tc; ++i)
    {
        solve(i);
    }
}
