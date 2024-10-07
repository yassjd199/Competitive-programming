// author : yassjd199
//https://atcoder.jp/contests/abc188/tasks/abc188_e
// dp + toplogical sorting
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

int n, m;
ll A[N];
vii adj[N];
ll dp[N][2][2];
ll solve(int cur, int buy , int sell) {
	if (buy && sell) return 0ll;
	if (adj[cur].empty()) {
		if (buy && !sell) {
			return A[cur - 1];
		}
	}
	ll &ret = dp[cur][buy][sell];
	if (ret > -1e17) return ret;
	ret = -1e17;
	for (int nd : adj[cur]) {
		ret = max(ret, solve(nd, buy, sell));
		if (!buy) {
			ret = max(ret, -A[cur - 1] + solve(nd, 1, 0));
		}
		if (buy && !sell) ret = max(ret, A[cur - 1] + solve(nd, 1, 1));
	}
	return ret;
}


void testcase() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n ; i++) {
		cin >> A[i];
	}
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		adj[a].emplace_back(b);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) dp[i][j][k] = -1e17;
		}
	}
	ll ans = -1e17;
	for (int i = 1; i <= n; i++)
		ans = max(ans, solve(i, 0, 0));



	cout << ans;
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
	//cin >> _;

	while (_--) {
		//cout<<"Case #"<<__++<<": ";
		testcase();
	}

	cerr << endl << "Run Time: " << (( double ) ( clock() - z ) / CLOCKS_PER_SEC ) << endl;
	return 0;
}
