/**
 * Created on: 2025-05-11
 * Author: yassjd199
 * https://codeforces.com/group/qAGblhphAA/contest/227981/problem/C
 * (form jcpc level 2 training 2018 (day2) (group on codeforces))
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
const int N = 1e6 + 1 , M = 17;
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


ll mx;
int a[N];
int n;
int dp[101][131080];
int solve(int i , int have) {
    if (i >= n) return  have == mx ? 0 : 1e9;
    int& ret = dp[i][have];
    if (~ret) return ret;
    ret = 1e9;
    ret = min(ret , solve(i + 1 , have));
    ret = min(ret , 1 + solve(i + 1 , have | a[i]));
    return ret;
}
void print(int i , int have) {
    if (i >= n) return;
    int ret1 = solve(i + 1 , have);
    int ret2 = 1 + solve(i + 1 , have | a[i]);
    if (ret1 < ret2) {
        print(i + 1 , have);
    }
    else {
        cout << a[i] << " ";
        print(i + 1 , have | a[i]);
    }

}

void testcase( ) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for (int i = 0; i < n; i++) {
        for (int j = M; j >= 0; j--) {
            if (a[i] & (1 << j)) mx |= (1 << j);
        }
    }
    memset(dp , -1 , sizeof(dp));
    cout << solve(0 , 0) << endl;
    print(0 , 0);






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
