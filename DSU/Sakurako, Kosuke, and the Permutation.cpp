// @author : yassjd199
//https://codeforces.com/contest/2033/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon();
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll  long long int
#define ull unsigned long long int
const int dx[4] = {0, 0, -1, 1}, dy[4] = { -1, 1, 0, 0};
//const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1} , dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const long long mod = 1e9 + 7;
const int N = 1e6 + 1, M = 20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> using Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using Map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n, p[N];
struct DSU {
	vector<ll> p, r;
	ll SetsCount;
	DSU(ll n) {
		p.resize(n + 1);
		r.resize(n + 1);
		for (int i = 0; i <= n; i++) p[i] = i, r[i] = 1;
		SetsCount = n;
	}
	ll find(ll e) {
		return e == p[e] ? e : p[e] = find(p[e]) ;
	}
	void merg(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return ;
		if (r[a] < r[b]) swap(a, b);
		SetsCount--;
		p[b] = a;
		r[a] += r[b];
		r[b] = 0ll;
	}
	bool same(ll a, ll b) {
		return find(a) == find(b) ;
	}
	ll rnk(ll x) {
		x = find(x);
		return r[x];
	}
	ll size() {
		return SetsCount ;
	}
};




void testcase() {
	cin >> n;
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		dsu.merg(i, p[i]);
	}
	vector<bool> vis(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[dsu.find(i)]) continue;
		vis[dsu.find(i)] = 1;
		ans += (dsu.rnk(i) - 1) / 2;
	}
	cout << ans << endl;





}

int main() {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int _ = 1;
	//int __ = 1;
	clock_t z = clock();
	cin >> _;

	while (_--) {
		//cout<<"Case #"<<__++<<": ";
		testcase();
	}

	cerr << endl << "Run Time: " << (( double ) ( clock() - z ) / CLOCKS_PER_SEC ) << endl;
	return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
