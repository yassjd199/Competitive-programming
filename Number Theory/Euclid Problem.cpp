// @author : yassjd199
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
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

ll gcd(ll a, ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}

ll mod_exp(ll b, ll p, ll m) {
	ll x = 1;
	while (p) {
		if (p & 1)
			x = (x * b) % m;
		b = (b * b) % m;
		p = p >> 1;
	}
	return x;
}

ll invFermat(ll a, ll p) {
	return mod_exp(a, p - 2, p);
}

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	/*
	this implementation,gives a solution such that |x|+|y| is minimal and x<=y

	*/
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

ll exp(ll b, ll p) {
	ll x = 1;
	while (p) {
		if (p & 1)
			x = (x * b);
		b = (b * b);
		p = p >> 1;
	}
	return x;
}



void testcase() {
	ll a = 1, b = 1;
	while (cin >> a >> b) {
		ll x, y;
		dbg(a, b);
		ll gc = extended_gcd(a, b, x, y);
		cout << x << " " << y << " " << gc << endl;
	}






}

int main() {
	// ios::sync_with_stdio (0);
	// cin.tie (0);
	// cout.tie (0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int _ = 1;
	//int __ = 1;
	clock_t z = clock();
	// cin >> _;

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