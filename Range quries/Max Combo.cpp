/**
 * Created on: 2025-08-13
 * Author: yassjd199
 * https://atcoder.jp/contests/abc415/tasks/abc415_f
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



struct node {
    int mx , s , p;
    char chs , chp;
    bool hole;
    node( ) {
        mx = -N , s = p = 0;
        chs = chp = '#';
        hole = 0;
    }
    node(int _mx , int _s , int _p , char _chs , char _chp , bool  _h) {
        mx = _mx;
        s = _s;
        p = _p;
        chs = _chs;
        chp = _chp;
        hole = _h;

    }
};



int n;
string str;

node st[4 * N];
node merg(node l , node r) {
    int cross = (l.chs == r.chp) * (l.s + r.p);
    if (l.chs == r.chp) {
        cross = l.s + r.p;
    }

    int newp = l.p;
    if (l.hole && l.chp == r.chp) {
        newp += r.p;
    }

    int news = r.s;
    if (r.hole && r.chs == l.chs) {
        news += l.s;
    }
    bool newhole = (l.chs == r.chp && l.hole && r.hole);
    return node(max({ l.mx, r.mx, cross }) , news , newp , r.chs , l.chp , newhole);
}


void build(int cur = 0 , int s = 0 , int e = n - 1) {
    if (s == e) {
        st[cur] = node(1 , 1 , 1 , str[s] , str[s] , 1);
        return;
    }
    int m = (s + e) >> 1;
    build(2 * cur + 1 , s , m);
    build(2 * cur + 2 , m + 1 , e);
    st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}

void upd(int pos , node val , int cur = 0 , int s = 0 , int e = n - 1) {
    if (s == e) {
        st[cur] = val;
        return;
    }
    int m = (s + e) >> 1;
    (pos <= m) ? upd(pos , val , 2 * cur + 1 , s , m) : upd(pos , val , 2 * cur + 2 , m + 1 , e);
    st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}

node query(int l , int r , int cur = 0 , int s = 0 , int e = n - 1) {
    if (e < l || s > r) return node( );
    if (s >= l && e <= r) {
        return st[cur];
    }
    int m = (s + e) >> 1;
    return merg(query(l , r , 2 * cur + 1 , s , m) , query(l , r , 2 * cur + 2 , m + 1 , e));
}
void testcase( ) {
    int q;
    cin >> n >> q;
    cin >> str;

    build( );

    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int pos; cin >> pos;
            char x; cin >> x;
            upd(--pos , node(1 , 1 , 1 , x , x , 1));
        }
        else {
            int l , r; cin >> l >> r;
            cout << query(--l , --r).mx << endl;
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
