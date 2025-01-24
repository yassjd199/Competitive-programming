/*
    @author : yassjd199
    https://codeforces.com/contest/1016/problem/C
    very good prefix / suffix sums problem
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

    vector<vll> v(2 , vll(n));
    for (int i = 0; i < n; i++) {
        cin >> v[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[1][i];
    }

    vector<vll> p(2 , vll(n + 1 , 0ll)) , s(2 , vll(n + 1 , 0)) , pref(2 , vll(n + 1 , 0ll)) , suff(2 , vll(n + 1 , 0ll));

    for (ll i = 1; i <= n; i++) p[0][i] = p[0][i - 1] + (i - 1) * v[0][i - 1] , p[1][i] = p[1][i - 1] + (i - 1) * v[1][i - 1];
    for (ll i = n - 1; i >= 0; i--) s[0][i] = s[0][i + 1] + (n - i - 1) * v[0][i] , s[1][i] = s[1][i + 1] + (n - i - 1) * v[1][i];

    for (ll i = 1; i <= n; i++) pref[0][i] = pref[0][i - 1] + v[0][i - 1] , pref[1][i] = pref[1][i - 1] + v[1][i - 1];
    for (ll i = n - 1; i >= 0; i--) suff[0][i] = suff[0][i + 1] + v[0][i] , suff[1][i] = suff[1][i + 1] + v[1][i];



    auto f1 =
        [&n , &s , &suff , &p , &pref] (int i , ll x) ->ll {
        return (p[0][n] - p[0][i]) + (x - i) * (pref[0][n] - pref[0][i]) + s[1][i] + (x + n - i) * suff[1][i];
        };

    auto f2 =
        [&n , &s , &suff , &p , &pref] (int i , ll x) ->ll {
        return (p[1][n] - p[1][i]) + (x - i) * (pref[1][n] - pref[1][i]) + s[0][i] + (x + n - i) * suff[0][i];
        };
    ll ans = 0ll;
    ll tmpAns = 0ll;
    ll x = 0ll;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans = max(ans , tmpAns + f1(i , x));
            tmpAns += ((x++) * v[0][i]);
            tmpAns += ((x++) * v[1][i]);
            ans = max(ans , tmpAns + f2(i + 1 , x));
        }
        else {
            ans = max(ans , tmpAns + f2(i , x));
            tmpAns += ((x++) * v[1][i]);
            tmpAns += ((x++) * v[0][i]);
            ans = max(ans , tmpAns + f1(i + 1 , x));
        }
    }
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
