#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://leetcode.com/problems/super-pow/

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


long long power (long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % 1337;
        a = a * a % 1337;
        b >>= 1;
    }

    return res;
}

int superPow(int a, vector<int>& b) {
    int n = 1337;
    int phin = n;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            phin -= phin / i;
        }
    }
    phin -= phin / n;
    
    int res = 0;
    for (int d : b) {
        res = (10 * res + d) % phin;
    }

    return power(a, res);
}

/* Main()  function */
int32_t main() {
    superPow(1, { 0 });
}
