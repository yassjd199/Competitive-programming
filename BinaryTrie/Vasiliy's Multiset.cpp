/**
 * Created on: 2025-05-11
 * Author: yassjd199
https://codeforces.com/problemset/problem/706/D */

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
    int nxt[2];
    int fr[2];
    node( ) {
        nxt[0] = nxt[1] = 0;
        fr[0] = fr[1] = 0;
    }
};

struct Trie {

    vector<node> T;
    int LEN;
    Trie(int _LEN) {
        T.resize(1);
        LEN = _LEN;
    }

    void insert(ll x) {
        int cur = 0;
        for (int i = LEN; i >= 0; i--) {
            int BIT = (x >> i) & 1;
            if (!T[cur].nxt[BIT]) {
                T[cur].nxt[BIT] = T.size( );
                T.emplace_back( );
            }
            T[cur].fr[BIT]++;
            cur = T[cur].nxt[BIT];
        }
    }

    void erase(ll x) {
        int cur = 0;
        for (int i = LEN; i >= 0; i--) {
            int BIT = (x >> i) & 1;
            if (!T[cur].nxt[BIT]) {
                return;
            }
            T[cur].fr[BIT]--;
            cur = T[cur].nxt[BIT];
        }
    }

    ll maxXor(ll x) {
        ll ret = 0ll;
        int cur = 0;
        for (int i = LEN; i >= 0; i--) {
            int BIT = (x >> i) & 1;
            if (!T[cur].fr[BIT ^ 1]) {
                cur = T[cur].nxt[BIT];
            }
            else {
                cur = T[cur].nxt[BIT ^ 1];
                ret |= (1 << i);
            }
        }

        return ret;
    }
    ll minXor(ll x) {
        ll ret = 0ll;
        int cur = 0;
        for (int i = LEN; i >= 0; i--) {
            int BIT = (x >> i) & 1;
            if (!T[cur].fr[BIT]) {
                cur = T[cur].nxt[BIT ^ 1];
                ret |= (1 << i);
            }
            else {
                cur = T[cur].nxt[BIT];
            }
        }

        return ret;
    }
};



void testcase( ) {
    int n; cin >> n;
    Trie T(30);
    T.insert(0ll);
    while (n--) {
        char typ; cin >> typ;
        ll x; cin >> x;
        if (typ == '+') {
            T.insert(x);
        }
        else if (typ == '-') {
            T.erase(x);
        }
        else {
            cout << T.maxXor(x) << endl;
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
    //  cin >> _;

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
