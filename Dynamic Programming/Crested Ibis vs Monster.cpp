/**
 * Created on: 2025-08-03
 * Author: yassjd199
 * https://atcoder.jp/contests/abc153/tasks/abc153_e
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

int H , n , A[1001] , B[1001];
int dp[1001][10001];
int solve(int i , int h) {
    // dbg(i , h);
    if (h <= 0) return 0;
    if (i >= n) {
        return h <= 0 ? 0 : 1e9;
    }
    int& ret = dp[i][h];
    if (~ret) return ret;
    ret = 1e9;
    ret = min(ret , B[i] + solve(i , h - A[i]));
    ret = min(ret , solve(i + 1 , h));
    ret = min(ret , B[i] + solve(i + 1 , h - A[i]));

    return ret;

}

void testcase( ) {

    cin >> H >> n;
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= H; j++)
            dp[i][j] = -1;


    cout << solve(0 , H);



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
    // cin >> _;

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
