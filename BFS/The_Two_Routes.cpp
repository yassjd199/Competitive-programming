// author : yassjd199
//https://codeforces.com/contest/601/problem/A

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
vii adj1[401], adj2[401];
map<pii, bool> edges;

// notice that one can always use the edge 1--->n , so there will be no accidents!

void testcase() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		edges[ {a, b}] = edges[ {b, a}] = 1;
		adj1[a].emplace_back(b);
		adj1[b].emplace_back(a);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (edges[ {i, j}] || edges[ {j, i}]) continue ;
			adj2[j].emplace_back(i);
			adj2[i].emplace_back(j);
			//dbg(i, j);
		}
	}
	queue<int> q;
	vii dis1(n + 1, 1e9), dis2(n + 1, 1e9);
	q.push(1);
	dis1[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//dbg(cur);
		for (auto x : adj1[cur]) {
			if (dis1[x] != 1e9) continue ;
			dis1[x] = 1 + dis1[cur];
			q.push(x);
		}
	}


	dis2[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//dbg(cur);
		for (auto x : adj2[cur]) {
			if (dis2[x] != 1e9) continue ;
			dis2[x] = 1 + dis2[cur];
			q.push(x);
		}
	}
	int ans = max(dis1[n], dis2[n]);
	if (ans >= 1e9) ans = -1;
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
	// cin >> _;

	while (_--) {
		//cout<<"Case #"<<__++<<": ";
		testcase();
	}

	cerr << endl << "Run Time: " << (( double ) ( clock() - z ) / CLOCKS_PER_SEC ) << endl;
	return 0;
}
