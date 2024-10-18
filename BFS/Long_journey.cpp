// author : yassjd199
//https://csacademy.com/contest/archive/task/long_journey/statement/
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
int S, A, B;
vii adj[N];
vii bfs(int src) {
	vii dis(n + 1, 1e9);
	dis[src] = 0;
	queue<int>q ;
	q.push(src);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//dbg(cur);
		for (auto nd : adj[cur]) {
			if (dis[nd] != 1e9) continue ;
			dis[nd] = dis[cur] + 1;
			q.push(nd);
		}
	}
	return dis;
}
void testcase() {
	cin >> n >> m;
	cin >> S >> A >> B;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	int ans = 0;
	//ll mn = 3e9;
	vii dis1 = bfs(S);
	vii dis2 = bfs(A);
	vii dis3 = bfs(B);
	for (int i = 1; i <= n; i++) {
		if (dis2[i] + dis3[i] + 2 * dis1[i] == dis1[A] + dis1[B]) {
			ans = max(ans, dis1[i]);
		}
	}
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
