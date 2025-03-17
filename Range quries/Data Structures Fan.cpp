/**
 * Created on: 2025-03-17
 * Author: yassjd199
 * https://codeforces.com/contest/1872/problem/E
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




pll st[4 * N];
int lz[4 * N];
string str;
int n;
ll a[N];
pll merg(pll l , pll r) {
	return { l.f ^ r.f , l.s ^ r.s };
}

void push(int cur , int s , int e) {
	if (lz[cur]) {
		//	st[cur] = ((e - s + 1) * lz[cur]);
		swap(st[cur].f , st[cur].s);
		if (s != e) {
			lz[2 * cur + 1] ^= 1;
			lz[2 * cur + 2] ^= 1;
		}
		lz[cur] = 0;
	}
}

void build(int cur = 0 , int s = 0 , int e = n - 1) {
	lz[cur] = 0;
	st[cur] = { 0ll,0ll };
	if (s == e) {
		if (str[s] == '1') st[cur].f = a[s];
		else st[cur].s = a[s];
		return;
	}
	int m = (s + e) >> 1;
	build(2 * cur + 1 , s , m);
	build(2 * cur + 2 , m + 1 , e);
	st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}

void upd_rng(int l , int r , ll val = 1 , int cur = 0 , int s = 0 , int e = n - 1) {
	push(cur , s , e);
	if (e < l || r < s) return;
	if (l <= s && e <= r) {
		lz[cur] ^= 1;
		push(cur , s , e);
		return;
	}
	int m = (s + e) >> 1;
	upd_rng(l , r , val , 2 * cur + 1 , s , m);
	upd_rng(l , r , val , 2 * cur + 2 , m + 1 , e);
	st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}

pll query(int l = 0 , int r = n - 1 , int cur = 0 , int s = 0 , int e = n - 1) {
	if (e < l || s > r) return { 0ll,0ll };
	push(cur , s , e);
	if (s >= l && e <= r) {
		return st[cur];
	}
	int m = (s + e) >> 1;
	return merg(query(l , r , 2 * cur + 1 , s , m) , query(l , r , 2 * cur + 2 , m + 1 , e));
}


void testcase( ) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> str;
	build( );
	//dbg(query( ).f , query( ).s);
	int q; cin >> q;
	while (q--) {
		int typ; cin >> typ;
		if (typ == 1) {
			int l , r; cin >> l >> r;
			l-- , r--;
			upd_rng(l , r);
		}
		else {
			int g; cin >> g;
			if (g == 1) cout << query( ).f << " ";
			else cout << query( ).s << " ";

		}
	}
	cout << "\n";

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
