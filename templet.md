
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ones(n) __builtin_popcount(x)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define ll long long
#define int long long
#define adee_ya_am_methoooo       \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define fx cout << fixed << setprecision(6);
#define test     \
    int test;    \
    cin >> test; \
    while (test--)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define pi 3.141592653
#define cin(vec)        \
    for (auto &i : vec) \
    cin >> i
#define cout(vec)       \
    for (auto &i : vec) \
    cout << i << ' '
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }



int dx[] = { 0, 1, 1, 1, 0,-1,-1,-1 };
int dy[] = {-1,-1, 0, 1, 1, 1, 0,-1 };
//
int dx[] = { 0, 1, 0,-1 };
int dy[] = {-1, 0, 1, 0 };

using namespace std;




struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(pair<uint64_t, uint64_t> x) const {
static const uint64_t FIXED_RANDOM =
chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second +
FIXED_RANDOM) >> 1);
}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM =
chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};

unordered_map<int, pair<int,int>> mp;

signed main()
{
    adee_ya_am_methoooo
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    // test
    solve();

    return 0;
}
