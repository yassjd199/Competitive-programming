// author : yassjd199
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2487
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


map<string, int> id;
// map<string, bool> hasId;
int m;
vector < vii > adj[N];
int dp[6000][28];
priority_queue<vii> pq;
void testcase() {
	while (cin >> m && m) {
		int ID = 1;
		id.clear();
		for (int i = 0; i <= m + 1; i++) {
			adj[i].clear();
			for (int j = 0; j <= 27; j++) dp[i][j] = 1e9;
		}

		string S, E; cin >> S >> E;
		if (!id[S]) id[S] = ID++;
		if (!id[E]) id[E] = ID++;
		for (int i = 0; i < m; i++) {
			string s, e, c;
			cin >> s >> e >> c;
			//dbg(s, e, c);
			if (!id[s]) id[s] = ID++;
			if (!id[e]) id[e] = ID++;
			//dbg(id[s], id[e]);
			adj[id[s]].pb({id[e], (int)c.size(), c[0] - 'a'});
			adj[id[e]].pb({id[s], (int)c.size(), c[0] - 'a'});
		}
		dp[id[S]][27] = 0;
		pq.push({0, id[S], 27});
		//dbg(dp[4][14]);
		while (!pq.empty()) {
			vii v = pq.top();
			pq.pop();
			int d = -v[0], cur = v[1], lastChar = v[2];
			if (d > dp[cur][lastChar]) continue ;
			for (auto nd : adj[cur]) {
				int x = nd[0], w = nd[1], curChar = nd[2];
				//dbg(cur, x, lastChar, curChar, d + w, dp[x][curChar]);
				if ((lastChar ^ curChar)  && d + w < dp[x][curChar]) {
					;
					dp[x][curChar] = d + w;
					pq.push({ -dp[x][curChar], x, curChar});
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < 27; i++) ans = min(ans, dp[id[E]][i]);
		if (ans >= 1e9) cout << "impossivel" << endl;
		else cout << ans << endl;
	}






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
