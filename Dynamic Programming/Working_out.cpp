// @author : yassjd199
//https://codeforces.com/contest/429/problem/B

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
ll G[1003][1003], dp1[1003][1003], dp2[1003][1003], dp3[1003][1003], dp4[1003][1003];





void testcase() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> G[i][j];


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp1[i][j] = max(dp1[i][j], G[i - 1][j - 1] + max(dp1[i - 1][j], dp1[i][j - 1]));
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			dp2[i][j] = max(dp2[i][j], G[i - 1][j - 1] + max(dp2[i + 1][j], dp2[i][j + 1]));
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			dp3[i][j] = max(dp3[i][j], G[i - 1][j - 1] + max(dp3[i + 1][j], dp3[i][j - 1]));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			dp4[i][j] = max(dp4[i][j], G[i - 1][j - 1] + max(dp4[i - 1][j], dp4[i][j + 1]));
		}
	}
	ll ans = 0ll;
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			//remember they should meet in only one square ;
			ans = max(ans, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
			ans = max(ans, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
		}
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
