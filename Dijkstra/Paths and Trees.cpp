// @author : yassjd199
//https://codeforces.com/contest/545/problem/E
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



priority_queue < pll>  pq;
int n, m;
vector<pll> adj[N];
int par[N];
ll dis[N], lastW[N];
map<pll, ll> id;
map<ll, pll> used;
vll Edges;
int W[N];
void testcase() {
	cin >> n >> m;
	for (ll i = 0, a, b, w; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
		id[ {min(a, b), max(a, b)} ] = i + 1;
		W[i + 1] = w;


	}
	ll S; cin >> S;
	fill(dis, dis + n + 1, 1e18);
	fill(par, par + n + 1, -1);
	fill(lastW, lastW + n + 1, 1e18);
	ll mnW = 0;
	pq.push({0ll, S});
	dis[S] = 0ll;
	while (!pq.empty()) {
		ll cur = pq.top().s;
		ll d = -pq.top().f;
		pq.pop();
		if (dis[cur] < d) continue ;
		for (auto nd : adj[cur]) {
			ll x = nd.f, w = nd.s;
			if (d + w < dis[x]) {
				//dbg(x, cur);
				dis[x] = d + w;
				lastW[x] = w;
				par[x] = cur;
				pq.push({ -dis[x], x});
				used[x] = {min(cur, x), max(cur, x)};
			}
			if (d + w == dis[x] && lastW[x] > w) {
				//dbg(cur, x);
				lastW[x] = w;
				used[x] = {min(cur, x), max(cur, x)};
				par[x] = cur;
			}
		}
	}
	// for (auto [k, v] : used) {
	// 	dbg(k, v.f, v.s);
	// }
	for (int i = 1; i <= n; i++) {
		if (i == S) continue ;
		mnW += W[id[used[i]]];
		Edges.pb(id[used[i]]);
	}
	cout << mnW << endl;
	for (auto ed : Edges) cout << ed << " ";







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
	//cin >> _;

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
