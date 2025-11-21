/**
 * Author: yassjd199
 * https://codeforces.com/problemset/problem/1512/D
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
    vll A(n + 2);
    for (auto& x : A) cin >> x;
    sort(all(A));

    // case 1: 
    ll S = accumulate(A.begin() , A.begin() + n , 0LL);
    if (A[n] == S || A[n + 1] == S) {
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }

    // case 2: 
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        if (S - A[i] + A[n] == A[n + 1]) {
            swap(A[n] , A[i]);
            ok = 1; break;
        }
    }
    if (ok) {
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
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
