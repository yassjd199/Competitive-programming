/**
 * Created on: 2025-08-20
 * Author: yassjd199
 * https://atcoder.jp/contests/abc410/tasks/abc410_e
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

/*


dp[i][h] is defined as the minimum magic power required to defeat the first i monsters, given that the total health consumed so far is exactly h.

Now, let's break down the recurrence with this correct definition:

Let's say I am considering the i-th monster. To achieve a state where I have defeated i monsters and used a total of h health, I have two choices:

I use HEALTH on the i-th monster."

This means I pay its health cost A_i. Therefore, before this fight, when I had only defeated the first i-1 monsters, I must have already used h - A_i health. The magic power required for this path remains the same as it was for the first i-1 monsters at that health level, which is dp[i-1][h - A_i].

This option is only valid if h >= A_i.

I use MAGIC on the i-th monster."

This means I pay its magic cost B_i. The total health consumed remains unchanged from the previous state. Therefore, I take the magic cost required for the first i-1 monsters at h health (dp[i-1][h]) and add the cost of this monster (B_i).

The recurrence dp[i][h] = min( dp[i-1][h - A_i], B_i + dp[i-1][h] ) simply chooses the cheapest magic cost option between these two strategies for reaching the state (i, h).
with dp[0][h:1->H] =  0 (dont need to spent any magic to kill 0 monsters for whatever healh).

And then we can make the classic knapsack 1D dp optimization , by going for h = H to 1; 


*/




void testcase( ) {

    int n; cin >> n;
    int H , P; cin >> H >> P;
    vii A(n) , B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    // vector<vii> dp(n + 1 , vii(H + 1 , 1e9));

    // for (int i = 0; i <= H; i++) dp[0][i] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int h = 0; h <= H; h++) {
    //         dp[i][h] = B[i - 1] + dp[i - 1][h];
    //         if (h >= A[i - 1]) dp[i][h] = min(dp[i][h] , dp[i - 1][h - A[i - 1]]);
    //     }
    // }

    // for (int i = n; i >= 0; i--) {
    //     for (int h = 0; h <= H; h++) {
    //         if (dp[i][h] <= P) {
    //             cout << i;
    //             return;
    //         }
    //     }
    // }

    vii dp(H + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int h = H; h >= 0; h--) {
            dp[h] += B[i - 1];
            if (h >= A[i - 1]) dp[h] = min(dp[h] , dp[h - A[i - 1]]);
            if (dp[h] <= P) ans = i;
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
