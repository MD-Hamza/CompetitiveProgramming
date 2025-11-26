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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (auto& entry : freq) {
        if (entry.second % k != 0) {
            cout << 0 << endl;
            return;
        }
        freq[entry.first] /= k;
    }

    unordered_map<int, int> window;

    int l = 0;
    ll subarrays = 0;
    for (int r = 0; r < n; r++) {
        window[a[r]]++;
        while (window[a[r]] > freq[a[r]]) {
            window[a[l]]--;
            l++;
        }

        subarrays += (r - l + 1);
    }

    cout << subarrays << endl;
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
