// https://codeforces.com/contest/2162/problem/D
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
    int l = 1;
    int r = n;
    ll x, y;

    while (l < r) {
        int mid = (l + r) / 2;
  
        cout << "1 1 " << mid << flush << endl;
        cin >> x;

        cout << "2 1 " << mid << flush << endl;
        cin >> y;

        if (x < y) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "1 1 " << n << flush << endl;
    cin >> x;

    cout << "2 1 " <<  n << flush << endl;
    cin >> y;

    r = y - x + l - 1;

    cout << "! " << l << " " << r << flush << endl;
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
