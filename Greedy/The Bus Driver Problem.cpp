// @author : yassjd199
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2384
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





void testcase() {
	ll n, d, r;
	while ( cin >> n >> d >> r && n && d && r) {
		vll morning(n);
		multiset<ll> evening;
		for (int i = 0; i < n; i++) cin >> morning[i];
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			evening.insert(x);
		}

		ll ans = 0;
		sort(rall(morning));
		for (int i = 0; i < n; i++) {
			// m[i]+e[i]<=d -> e[i]<=d-m[i];
			auto it = evening.upper_bound(d - morning[i]);
			if (it != evening.begin()) it--;
			ll e = *it;
			evening.erase(evening.find(e));
			ans += max(0ll, morning[i] + e - d) * r;
		}
		cout << ans << endl;
	}






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
