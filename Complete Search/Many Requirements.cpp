/**
 * Created on: 2025-08-23
 * Author: yassjd199
 * https://atcoder.jp/contests/abc165/tasks/abc165_c
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


int Q[51][4];
int n , m , q;
int ans;

void gen(int i , vii A) {
    if (A.size( ) == n) {
        int score = 0;
        for (int j = 0; j < q; j++) {
            score += (Q[j][2] == A[Q[j][1]] - A[Q[j][0]]) * Q[j][3];
        }
        ans = max(ans , score);
        return;
    }
    if (i > m) {

        return;
    }
    if (A.size( ) > n) return;


    // vii B = A;
    // B.emplace_back(i);
    // gen(i , B);
    // gen(i + 1 , A);
    // gen(i + 1 , B);

    A.emplace_back(i);
    gen(i , A);
    A.pop_back( );
    A.emplace_back(i);
    gen(i + 1 , A);
    A.pop_back( );
    gen(i + 1 , A);

}


void testcase( ) {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2] >> Q[i][3];
        Q[i][0]--;
        Q[i][1]--;
    }
    gen(1 , {});
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
