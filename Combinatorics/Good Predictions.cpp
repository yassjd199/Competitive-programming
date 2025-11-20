/**
 * Author: yassjd199
 * https://www.spoj.com/problems/GOODB/
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

const int MX = 2000005;


ll F[MX];
ll mod_exp(ll b , ll p , ll m = MOD) {
    ll x = 1;
    while (p) {
        if (p & 1)
            x = (x * b) % m;
        b = (b * b) % m;
        p = p >> 1;
    }
    return x;
}

ll invFermat(ll a , ll p = MOD) {
    return mod_exp(a , p - 2 , p);
}


ll C(int n , int k) {
    return (F[n] * (invFermat(F[k]) * invFermat(F[n - k])) % MOD) % MOD;
}
void testcase() {
    int n , w , t , r;
    cin >> n >> w >> t >> r;


    ll ans = F[n];
    ans *= invFermat(F[w]);
    ans %= MOD;
    ans *= invFermat(F[t]);
    ans %= MOD;
    ans *= invFermat(F[r]);
    ans %= MOD;

    cout << ans;


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    F[0] = F[1] = 1;
    for (ll i = 2; i < MX; i++) {
        F[i] = i * F[i - 1];
        F[i] %= MOD;
    }
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

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
