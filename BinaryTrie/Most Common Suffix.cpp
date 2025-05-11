/**
 * Created on: 2025-05-11
 * Author: yassjd199
 * https://codeforces.com/gym/101502/problem/G
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


int ans[N];
struct node {
    int nxt[26];
    int end;
    int pref;
    node( ) {
        memset(nxt , 0 , sizeof(nxt));
        end = pref = 0;
    }
};
struct Trie {

    vector<node> T;

    Trie( ) {
        T.resize(1);
    }

    void insert(string& word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) {
                T[cur].nxt[x] = T.size( );
                T.emplace_back( );
            }

            cur = T[cur].nxt[x];
            T[cur].pref++;

        }
        T[cur].end++;
    }

    int countWordsEqualTo(string& word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) return  0;
            cur = T[cur].nxt[x];
        }
        return T[cur].end;
    }

    int countWordsStartingWith(string& word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) return  0;
            cur = T[cur].nxt[x];
        }
        return T[cur].pref;
    }

    void erase(string& word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) return;
            cur = T[cur].nxt[x];
            T[cur].pref--;
        }
        T[cur].end--;

    }
    void dfs(int nd , int d) {
        ans[d] = max(ans[d] , T[nd].pref);

        int i;
        for (i = 0; i < 26; i++) {
            if (T[nd].nxt[i]) {
                // dbg(d , T[nd].pref);
                dfs(T[nd].nxt[i] , d + 1);
            }
        }
    }
};



void testcase( ) {

    int n , q; cin >> n >> q;
    Trie T;
    fill(ans , ans + N , 1);
    for (int i = 0; i < n; i++) {
        string txt; cin >> txt;
        reverse(all(txt));
        T.insert(txt);
    }
    T.dfs(0 , 0);
    while (q--) {
        int dpth; cin >> dpth;
        cout << ans[dpth] << endl;

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
