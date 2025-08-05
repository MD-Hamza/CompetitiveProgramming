#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-good-numbers
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


long long pow(long long base, long long x, int m) {
    int res = 1;
    
    while (x > 0) {
        if (x & 1) res = (res * base) % m;
        base = (base * base) % m;
        x >>= 1;
    }

    return res;
}

int countGoodNumbers(long long n) {
    long long x = n / 2;
    long long y = n % 2 == 0 ? n / 2 : n / 2 + 1;
    long long res = (pow(4, x, MOD) * pow(5, y, MOD)) % MOD;
    return res;
}

/* Main()  function */
int32_t main() {
    cout << countGoodNumbers(1) << endl;
    cout << countGoodNumbers(4) << endl;
    cout << countGoodNumbers(50) << endl;
}
