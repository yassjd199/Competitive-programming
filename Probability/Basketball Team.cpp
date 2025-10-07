/**
 * Author: yassjd199
 * https://codeforces.com/contest/107/problem/B
 *
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




void testcase( ) {
	int n , m, h  ; cin >> n >> m >> h ;
	vii s(m);
	int tot = 0, sm = 0;
	for (int i = 0; i < m; i++) cin >> s[i], tot += s[i], sm += s[i];
	if (sm < n) {
		cout << -1 << endl;
		return ;
	}
	sm--;
	tot -= (s[h - 1]);

	long double p = 1;

	for (int i = 0; i < n - 1; i++, sm--, tot--) {
		p *= (tot * 1.0) / ( sm * 1.0);

	}

	cout << fixed << setprecision(9) << 1 - p << endl;




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
	// cin >> _;

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
