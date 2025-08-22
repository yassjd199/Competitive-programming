/**
 * Created on: 2025-08-22
 * Author: yassjd199
 * https://atcoder.jp/contests/abc182/tasks/abc182_e
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
    int h , w; cin >> h >> w;
    int n , m; cin >> n >> m;

    vector<vector<char>> G(h , vector<char>(w));


    vector<vii> R(h , vii(w + 1 , 0));

    for (int i = 0; i < n; i++) {
        int a , b; cin >> a >> b;
        a-- , b--;
        G[a][b] = '.';
    }
    for (int i = 0; i < m; i++) {
        int a , b; cin >> a >> b;
        a--; b--;
        G[a][b] = '#';
    }

    for (int i = 0; i < h; i++) {
        vii v;
        for (int j = 0; j < w; j++) {
            if (G[i][j] == '#') v.emplace_back(j);
        }

        for (int j = 0; j < w; j++) {
            if (G[i][j] == '.') {
                if (v.empty( )) {
                    R[i][0]++ , R[i][w]--;
                    continue;
                }
                int e = upper_bound(all(v) , j) - v.begin( );
                int s = (e - 1 >= 0 ? v[e - 1] : 0);
                e = (e < v.size( ) ? v[e] + 1 : w);
                R[i][s]++ , R[i][e]--;

            }
        }

        for (int j = 1; j <= w; j++) R[i][j] += R[i][j - 1];

    }

    vector<vii> C(w , vii(h + 1 , 0));

    for (int j = 0; j < w; j++) {
        vii v;
        for (int i = 0; i < h; i++) {
            if (G[i][j] == '#') v.emplace_back(i);
        }
        for (int i = 0; i < h; i++) {
            if (G[i][j] == '.') {
                if (v.empty( )) {
                    C[j][0] ++ , C[j][h]--;
                    continue;
                }
                int e = upper_bound(all(v) , i) - v.begin( );
                int s = (e - 1 >= 0 ? v[e - 1] : 0);
                e = (e < v.size( ) ? v[e] + 1 : h);
                // dbg(s , e);
                C[j][s]++ , C[j][e]--;
            }
        }
        for (int i = 1; i <= h; i++) C[j][i] += C[j][i - 1];

    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (G[i][j] == '#') continue;
            ans += (R[i][j] || C[j][i]);
        }
    }
    cout << ans;

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
