// author : yassjd199
//https://codeforces.com/contest/598/problem/E

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


int n, m, K;
const int MX1 = 51, MX2 = 31;
int dp[MX2][MX2][MX1];
int solve(int i, int j, int k = K) {
	//dbg(i, j, k);
	if (k == 0) return 0ll;
	if (k < 0) return 1e9;
	int &ret = dp[i][j][k];
	if (~ret) return ret;
	ret = 1e9;
	ret = min(ret, solve(0, 0, k - (i * j)));
	for (int i1 = 1; i1 <= i / 2; i1++) {
		ret = min({ret, j * j + solve(i1, j, k), j * j + solve(i - i1, j, k)});
		ret = min(ret, j * j + solve(i1, j, k - ((i - i1) * j)) );
		ret = min(ret, j * j + solve(i - i1, j, k - (i1 * j)));
		ret = min(ret, j * j + solve(i1, j, k) + solve(i - i1, j, k ));
	}
	for (int j1 = 1; j1 <= j / 2; j1++) {
		ret = min({ret, i * i + solve(i, j1, k) , i * i + solve(i, j - j1, k)});
		ret = min(ret, i * i + solve(i, j1, k) + solve(i, j - j1, k));
		ret = min(ret, i * i + solve(i, j1, k - (i * (j - j1))));
		ret = min(ret, i * i + solve(i, j - j1, k - (i * j1)));
	}
	return ret;
}

void testcase() {
	cin >> n >> m >> K;
	cout << solve(n, m) << endl;




}

int main() {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	memset(dp, -1, sizeof(dp));
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
