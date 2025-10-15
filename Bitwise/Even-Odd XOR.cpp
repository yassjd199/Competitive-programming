/**
 * Created on: 2025-07-26
 * Author: yassjd199
 * https://codeforces.com/contest/1722/problem/G
 * 
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int , int> pii;
typedef pair<long long , long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon( );
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll long long int
#define ull unsigned long long int
const int dx[4] = { 0, 0, -1, 1 } , dy[4] = { -1, 1, 0, 0 };
// const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const long long mod = 1e9 + 7;
const int N = 1e6 + 1 , M = 20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> using Set = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template<typename K , typename V> using Map = tree<K , V , less<K> , rb_tree_tag , tree_order_statistics_node_update>;

void dbg_out( ) {
    cerr << endl;
}
template <typename Head , typename... Tail>
void dbg_out(Head H , Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)





void testcase( ) {
    int n; cin >> n;
    if (n == 3) {
        cout << "2 1 3" << endl;
        return;
    }
    if (n == 4) {
        cout << "2 1 3 0" << endl;
        return;
    }
    if (n == 5) {
        cout << "2 0 4 5 3" << endl;
        return;
    }
    if (n == 6) {
        cout << "4 1 2 12 3 8" << endl;
        return;
    }
    if (n == 7) {
        cout << "1 2 3 4 5 6 7" << endl;
        return;
    }
    vii ans(n);
    ans[0] = (1LL << 30);
    ans[1] = (1LL << 29);
    ll xor1 = ans[0];
    int j = 1;
    for (int i = 2; i < n; i += 2) {
        ans[i] = j;
        xor1 ^= j;
        j++;
    }
    ll xor2 = ans[1];
    for (int i = 5; i < n; i += 2) {
        ans[i] = j;
        xor2 ^= j;
        j++;
    }
    ans[3] = xor1 ^ xor2;
    ll a = 0 , b = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) a ^= ans[i];
        else b ^= ans[i];
        cout << ans[i] << " ";
    }
    cout << endl;
    // dbg(a , b);
}

int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int _ = 1;
    // int __ = 1;
    clock_t z = clock( );
    cin >> _;

    while (_--) {
        // cout << "Case #" << __++ << ": ";
        testcase( );
    }

    cerr << endl << "Run Time: " << ((double)(clock( ) - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
