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

struct Mat
{   
    int n, m;
    vector< vector<int> > a;

    Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
    Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }

    inline Mat operator * (const Mat &b) {
        assert(m == b.n);
        Mat ans = Mat(n, b.m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < b.m; j++) {
                for(int k = 0; k < m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }
};

void solve()
{

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
