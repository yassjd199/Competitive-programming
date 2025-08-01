/**
 * Created on: 2025-07-26
 * Author: yassjd199
 *https://codeforces.com/contest/1692/problem/H
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

ll a[N];
int n;
struct node {
    ll sum , pref , suff , ans;
    node( ) { sum = 0 , pref = -1e9 , suff = -1e9 , ans = -1e9; }
    //node(){sum=0,pref=0,suff=0,ans=0;}
    node(ll _sum , ll _pref , ll _suff , ll _ans) {
        sum = _sum;
        pref = _pref;
        suff = _suff;
        ans = _ans;
    }
};
node st[4 * N];

node merg(node lef , node rig) {
    return node(lef.sum + rig.sum , max({ lef.pref,lef.sum + rig.pref }) , max({ rig.suff,rig.sum + lef.suff }) , max({ lef.ans,rig.ans,lef.suff + rig.pref }));
}
void build(int cur = 0 , int s = 0 , int e = n - 1) {
    if (s == e) {
        st[cur] = node(-1 , -1 , -1 , -1);
        return;
    }
    int m = (s + e) >> 1;
    build(2 * cur + 1 , s , m);
    build(2 * cur + 2 , m + 1 , e);
    st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}
void upd(int pos , ll val , int cur = 0 , int s = 0 , int e = n - 1) {
    if (s == e) {
        st[cur] = node(val , val , val , val);
        return;
    }
    int m = (s + e) >> 1;
    if (pos <= m) upd(pos , val , 2 * cur + 1 , s , m);
    else upd(pos , val , 2 * cur + 2 , m + 1 , e);
    st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}
node query(int l , int r , int cur = 0 , int s = 0 , int e = n - 1) {
    // s e l  r s e 
    // l s  e r 
    if (e < l || r < s) return node( );
    if (l <= s && e <= r) return st[cur];
    int m = (s + e) >> 1;
    return merg(query(l , r , 2 * cur + 1 , s , m) , query(l , r , 2 * cur + 2 , m + 1 , e));
}




void testcase( ) {
    cin >> n;
    //dbg(n);
    map<ll , vii> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].emplace_back(i);
    }
    build( );
    int mx = 0 , A;
    for (auto p : pos) {
        ll X = p.f;
        vii v = p.s;
        for (auto x : v) upd(x , 1);
        ll res = query(0 , n - 1).ans;
        if (mx < res) {
            mx = res;
            A = X;
        }
        for (auto x : v) upd(x , -1);
        // dbg(X , res);

    }
    //dbg(mx , A);
    vii p(n , -1);
    for (auto x : pos[A]) {
        //dbg(x);
        p[x] = 1;
    }
    // dbg(mx);
    int sm = 0;
    for (int i = 0 , j = 0; i < n; i++) {
        sm += p[i];
        if (sm == mx) {
            cout << A << " " << j + 1 << " " << i + 1 << endl;
            return;
        }
        if (sm < 0) {
            sm = 0;
            j = i + 1;
        }
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
