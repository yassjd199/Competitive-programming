// author : yassjd199
//https://codeforces.com/contest/2014/problem/E
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


int n, m, h;
bool H[N];
vector<pll> adj[N];

vector<vll> dijk(ll S) {
	vector<vll> dp(n + 1, vll(2, 1e18));
	priority_queue<vll> pq;
	dp[S][0] = 0;
	pq.push({0ll, S, 0});
	while (!pq.empty()) {
		vll v = pq.top();
		pq.pop();
		ll d = -v[0], cur = v[1], hasHorse = v[2];
		if (d != dp[cur][hasHorse]) continue ;
		hasHorse |= H[cur];
		for (auto nd : adj[cur]) {
			ll x = nd.f, w = nd.s;
			if (hasHorse) w >>= 1;
			if (d + w < dp[x][hasHorse] ) {
				dp[x][hasHorse] = w + d;
				pq.push({ -dp[x][hasHorse], x, hasHorse });
			}
		}
	}
	return dp;
}


void testcase() {
	cin >> n >> m >> h;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		H[i] = 0;
	}
	for (int i = 0, x; i < h; i++) {
		cin >> x;
		H[x] = 1;
	}
	for (ll i = 0, a, b, w; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
	vector<vll> dp1 = dijk(1);
	vector<vll> dp2 = dijk(n);
	ll ans = 1e18;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, max(min(dp1[i][0], dp1[i][1]) , min(dp2[i][0], dp2[i][1])));
	}
	if (ans >= 1e18) ans = -1;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int _ = 1;
	int __ = 1;
	clock_t z = clock();
	cin >> _;

	while (_--) {
		//cout<<"Case #"<<__++<<": ";
		testcase();
	}

	cerr << endl << "Run Time: " << (( double ) ( clock() - z ) / CLOCKS_PER_SEC ) << endl;
	return 0;
}
