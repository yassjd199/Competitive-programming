/**
 * Author: yassjd199
 * https://codeforces.com/contest/35/problem/D
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


// int dp[101][10001];

int dp[10001];

void testcase( ) {
    int n, X ; cin >> n >> X;
    vii c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    // dp[0][j] = 0 , no days , then the max number of animls is 0 regradless of the value of j


    // for (int i = 1; i <= n; i++) {
    //     for (int x = 1; x <= X ; x++) {
    //         dp[i][x] = dp[i - 1][x];
    //         if ((n - i + 1)*c[i - 1] <= x) dp[i][x] = max(dp[i - 1][x], 1 + dp[i - 1][x - ((n - i + 1) * c[i - 1])]) ;

    //     }
    // }

    // cout << dp[n][X];

    for (int i = 1; i <= n; i++) {
        for (int x = X; x >= 0 ; x--) {
            if ((n - i + 1)*c[i - 1] <= x) dp[x] = max(dp[x], 1 + dp[x - ((n - i + 1) * c[i - 1])]) ;

        }
    }

    cout << dp[X];

}



int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
