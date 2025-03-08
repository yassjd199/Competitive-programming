/**
 * Created on: 2025-03-08
 * Author: yassjd199
 * https://codeforces.com/contest/1985/problem/H1
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

struct DSU {
    vector<ll> p , r;
    ll SetsCount;
    DSU(ll n) {
        p.resize(n + 1);
        r.resize(n + 1);
        for (int i = 0; i <= n; i++) p[i] = i , r[i] = 1;
        SetsCount = n;
    }
    ll find(ll e) {
        return e == p[e] ? e : p[e] = find(p[e]);
    }
    void merg(ll a , ll b) {
        a = find(a) , b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a , b);
        SetsCount--;
        p[b] = a;
        r[a] += r[b];
        r[b] = 0ll;
    }
    bool same(ll a , ll b) {
        return find(a) == find(b);
    }
    ll rnk(ll x) {
        x = find(x);
        return r[x];
    }
    ll size( ) {
        return SetsCount;
    }
};


void testcase( ) {
    int n , m; cin >> n >> m;
    vector<vector<char>> G(n , vector<char>(m));
    DSU dsu(n * m);
    auto F = [&m] (int i , int j)->int {

        return i * m + j;

    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == '#') {
                if (i - 1 >= 0) {
                    if (G[i - 1][j] == '#') dsu.merg(F(i , j) , F(i - 1 , j));
                }
                if (j - 1 >= 0) {
                    if (G[i][j - 1] == '#') dsu.merg(F(i , j) , F(i , j - 1));
                }
            }
            ans = max(ans * 1ll , dsu.rnk(F(i , j)));
        }

    }
    auto ok = [&n , &m] (int i , int j)->bool {
        return i >= 0 && j >= 0 && i < n && j < m;
    };
    set<int> se;
    int curAns = 0ll;
    for (int i = 0; i < n; i++) {
        se.clear( );
        curAns = 0;
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '#')continue;
            curAns++;
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k] , b = j + dy[k];
                if (ok(a , b) && G[a][b] == '#') {
                    //dbg(i , j , a , b);
                    if (!se.count(dsu.find(F(a , b)))) {
                        curAns += dsu.rnk(F(a , b));
                        se.insert(dsu.find(F(a , b)));
                    }
                }
            }
        }
        ans = max(ans , curAns);
    }
    for (int j = 0; j < m; j++) {
        curAns = 0;
        se.clear( );
        for (int i = 0; i < n; i++) {
            if (G[i][j] == '#') continue;
            curAns++;
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k] , b = j + dy[k];
                if (ok(a , b) && G[a][b] == '#') {
                    if (!se.count(dsu.find(F(a , b)))) {
                        curAns += dsu.rnk(F(a , b));
                        // dbg(i , j , a , b);
                        se.insert(dsu.find(F(a , b)));
                    }
                }
            }

        }
        ans = max(ans , curAns);
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
