/**
 * Created on: 2025-05-11
 * Author: yassjd199
 * https://codeforces.com/gym/100989/problem/M
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


vii v;
int n;

int dp[302][30010][2];
int sig(int x) {
    return x < 0 ? 0 : 1;
}

int solve(int i , int sum , int sn) {
    if (i >= n) return sum == 0 ? 0 : 1e9;
    int& ret = dp[i][sum][sn];
    if (~ret) return ret;
    ret = 1e9;
    int newSn = sn ? 1 : -1;
    ret = min(ret , solve(i + 1 , abs(newSn * sum + v[i]) , sig(newSn * sum + v[i])));
    ret = min(ret , 1 + solve(i + 1 , abs(newSn * sum - v[i]) , sig(newSn * sum - v[i])));
    return ret;
}

void testcase( ) {
    int m; cin >> m;
    ll p = 1;
    for (int i = 0; i < 2 * m - 1; i++) {
        string x; cin >> x;

        if (x == "+") p = 1;
        else if (x == "-") p = -1;
        else v.emplace_back(p * (stol(x)));
    }
    n = v.size( );
    memset(dp , -1 , sizeof(dp));

    int ans = solve(1 , abs(v[0]) , sig(v[0]));
    if (ans >= 1e9) ans = -1;
    cout << ans << endl;



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
