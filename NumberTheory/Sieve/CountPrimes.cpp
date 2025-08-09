#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://leetcode.com/problems/count-primes
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


int countPrimes(int n) {
    vector<bool> prime(n + 1, true);
    int sqrtn = sqrt(n);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= sqrtn; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        count += prime[i];
    }

    return count;
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cout << countPrimes(10) << endl;
    cout << countPrimes(40) << endl;
    cout << countPrimes(0) << endl;
}
