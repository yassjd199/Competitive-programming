/**
 * Author: yassjd199
 * https://codeforces.com/contest/1520/problem/E
 *
 * (the median will give a correct answer, no need to try for every point)
 *
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 // namespace __DEBUG_UTIL__
#ifndef ONLINE_JUDGE
#include "debugTemplate.h"
#define dbg(...)                                            \
        std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
            __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgArr(...)                                         \
        std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
            __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define dbgArr(...)
#endif
using namespace __gnu_pbds;
using namespace std;
typedef pair<int , int> pii; typedef pair<long long , long long> pll; typedef vector<int> vii; typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon();
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll long long int
#define ull unsigned long long int
const int dx[4] = { 0, 0, -1, 1 } , dy[4] = { -1, 1, 0, 0 };
// const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int N = 1e6 + 1 , M = 30 , MOD = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
using Set = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template <typename K , typename V>
using Map = tree<K , V , less<K> , rb_tree_tag , tree_order_statistics_node_update>;





void testcase() {
    int n; cin >> n;
    string S; cin >> S;

    vll p(n + 1) , cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + (S[i - 1] == '*') * i;
        cnt[i] = cnt[i - 1] + (S[i - 1] == '*');
    }

    ll ans = 1e18;
    for (ll i = 1; i <= n; i++) {
        if (S[i - 1] == '.') continue;
        // ll tmp = cnt[n] - cnt[i];
        // dbg(cnt[i - 1] * i - p[i - 1] - -cnt[i - 1] - cnt[i - 1] * (cnt[i - 1] - 1) / 2 , (p[n] - p[i]) - (cnt[n] - cnt[i]) * i - (cnt[n] - cnt[i]) - tmp * (tmp - 1) / 2);
        ans = min(ans , cnt[i - 1] * i - p[i - 1] - cnt[i - 1] - cnt[i - 1] * (cnt[i - 1] - 1) / 2 + (p[n] - p[i]) - (cnt[n] - cnt[i]) * i - (cnt[n] - cnt[i]) - (cnt[n] - cnt[i] - 1) * (cnt[n] - cnt[i]) / 2);
    }
    if (ans >= 1e18) ans = 0;
    cout << ans << endl;

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
    cin >> _;

    while (_--) {
        // cout << "Case #" << __++ << ": ";
        testcase();
    }

    cerr << endl << "Run Time: " << ((double) (clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
