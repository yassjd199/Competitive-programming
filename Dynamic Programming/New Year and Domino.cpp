/**
 * Created on: 2025-01-24
 * Author: yassjd199
 *https://codeforces.com/problemset/problem/611/C
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

    int n , m; cin >> n >> m;
    vector<vector<char>> g(n , vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    auto ok =
        [&n , &m , &g] (int i , int j)->bool {
        return i < n && i >= 0 && j >= 0 && j < m && g[i][j] == '.';
        };
    vector<vii> dp1(n + 1 , vii(m + 1)) , dp2(n + 1 , vii(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1] - dp1[i - 1][j - 1] + (g[i - 1][j - 1] == '.' && ok(i - 1 , j));
            dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1] + (g[i - 1][j - 1] == '.' && ok(i , j - 1));
        }
    }

    int q; cin >> q;
    while (q--) {
        int x1 , y1 , x2 , y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << dp1[x2][y2 - 1] - dp1[x2][y1 - 1] - dp1[x1 - 1][y2 - 1] + dp1[x1 - 1][y1 - 1] + dp2[x2 - 1][y2] - dp2[x2 - 1][y1 - 1] - dp2[x1 - 1][y2] + dp2[x1 - 1][y1 - 1] << endl;
    }





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
