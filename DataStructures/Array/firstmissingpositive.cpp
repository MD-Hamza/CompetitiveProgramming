#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
// https://leetcode.com/problems/first-missing-positive

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


int firstMissingPositive(vector<int>& nums) {
    int smallest = 1;
    for (int i = 0; i < nums.size(); i++) {
        int val = nums[i];
        while (val > 0 && val <= nums.size() && nums[i] != nums[val - 1]) {
            swap(nums[i], nums[val - 1]);
            val = nums[i];
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != (i + 1)) return i + 1;
    }

    return nums.size() + 1;
}

/* Main()  function */
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}
