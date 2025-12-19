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
    vector<int> odd, even;
    int c;

    for (int i =0; i < n; i++) {
        cin >> c;
        if (c % 2) odd.push_back(c);
        else even.push_back(c);
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    
    int s = 0;

    for (int i = 0; i < n; i++) {
        if (odd.size() == 0) {
            cout << 0 << " ";
            continue;
        }

        if (i == 0) s = odd[0];
        else if (i <= even.size()) s += even[i - 1];
        else {
            if (odd.size() < (i - even.size()))
        }

        cout << s << " ";
    }
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
