#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://www.spoj.com/problems/INVESORT/
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


void solve(string C, string D) {
    if (C == D) {
        cout << 0 << "\n";
        return;
    }
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    visited.insert(C);
    q.push({C, 0});
    string temp;
    
    while (!q.empty()) {
        auto [seq, steps] = q.front(); q.pop();
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                temp = seq;
                reverse(temp.begin() + i, temp.begin() + j + 1);
                if (temp == D) {
                    cout << steps + 1 << "\n";
                    return;
                }
                if (!visited.count(temp)) {
                    visited.insert(temp);
                    q.push({temp, steps + 1});
                }
            }
        }
    }
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string C, D;
    // cin >> _tc;
    cin >> C >> D;
    while (C != "*")
    {
        solve(C, D);
        cin >> C >> D;
    }
}
