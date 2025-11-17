
\\ Author: yassjd199
\\ https://codeforces.com/contest/607/problem/A
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#include"debugTemplate.h"
#define debug(...)                                           \
    std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
        __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...)                                        \
    std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
        __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace __gnu_pbds;
using namespace std;
typedef pair<int , int> pii;
typedef pair<long long , long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon();
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll long long int
#define ull unsigned long long int
const int dx[4] = { 0, 0, -1, 1 } , dy[4] = { -1, 1, 0, 0 };
// const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1e9 + 7;
const int N = 1e6 + 1 , M = 30;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
using Set = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template <typename K , typename V>
using Map = tree<K , V , less<K> , rb_tree_tag , tree_order_statistics_node_update>;

int n;
int nxt[N];
int dp[N][2];

int Solve(int i , int ok) {
    if (i < 0) return 0;

    int& ret = dp[i][ok];
    if (~ret) return ret;

    ret = 0;

    if (ok == 0) {
        // skip
        ret = max(ret , Solve(i - 1 , 0));
        // take
        ret = max(ret , 1 + Solve(nxt[i] , 1));
    }
    else {
        // must take
        ret = max(ret , 1 + Solve(nxt[i] , 1));
    }

    return ret;
}

void testcase() {
    cin >> n;
    vector<pii> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i].f >> X[i].s;
        dp[i][0] = dp[i][1] = -1;
    }

    // debug(X);
    sort(all(X));

    for (int i = 0; i < n; i++) {
        nxt[i] = (lower_bound(all(X) , make_pair(X[i].f - X[i].s , 0)) - X.begin()) - 1;
    }

    cout << n - Solve(n - 1 , 0) << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int _ = 1;
    // int __ = 1;
    clock_t z = clock();
    // cin >> _;

    while (_--) {
        // cout << "Case #" << __++ << ": ";
        testcase();
    }

    cerr << endl << "Run Time: " << ((double) (clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
