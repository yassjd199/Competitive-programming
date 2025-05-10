/**
 * Created on: 2025-05-10
 * Author: yassjd199
 * https://codeforces.com/contest/813/problem/C
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

/////////// just lca
int p[N][M] , depth[N];
vii adj[N];
int n , m;
void dfs(int cur , int par) {
    p[cur][0] = par;
    depth[cur] = 1 + depth[par];
    for (int i = 1; i < M; i++) {
        p[cur][i] = p[p[cur][i - 1]][i - 1];
    }
    for (auto nd : adj[cur]) {
        if (nd != par) dfs(nd , cur);
    }
}

int lca(int a , int b) {
    if (depth[a] < depth[b]) swap(a , b);
    int k = depth[a] - depth[b];

    // go to the same level
    for (int i = M - 1; i >= 0; i--) {
        if (k & (1 << i)) a = p[a][i];
    }
    if (a == b) return a;
    for (int i = M - 1; i >= 0; i--) {
        if (p[a][i] != p[b][i]) {
            a = p[a][i];
            b = p[b][i];
        }
    }
    return p[a][0];
}

int DIS(int a , int b) { // distance between a and b ;
    return depth[a] + depth[b] - 2 * depth[lca(a , b)];
}
int getkth(int x , int k) {
    // parent of the root is 0 , this implementation returns -1 for this case
    if (k > DIS(x , 1)) return -1;
    for (int i = M - 1; i >= 0; i--) {
        if (k & (1 << i)) x = p[x][i];
    }
    return !x ? -1 : x;
}

/*
10 4
1 2
2 3
3 4
4 5
5 9
3 6
6 7
7 8
8 10
*/
int dp[N];
void dfs1(int cur , int par) {
    for (auto x : adj[cur]) {
        if (x != par) {
            dfs1(x , cur);
        }
    }
    dp[par] = max(dp[par] , dp[cur]);
}

void testcase( ) {
    int x;
    cin >> n >> x;
    for (int i = 0 , a , b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1 , 0);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (DIS(x , i) < DIS(1 , i)) {
            ans = max(ans , depth[i] - 1);
        }
    }
    cout << ans * 2 << endl;
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
