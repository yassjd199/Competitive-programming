// author : yassjd199
//https://codeforces.com/contest/1062/problem/B

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


//Notice that when dividing some x by tow, it reaches 1 faster if it is a power of two, 6/2=3(1op) , 3+1 = 4(2op)  , 4 / 2= 2(3op) ,  2/2= 1(4op)
// 8/2 = 4(1op) ,4/2= 2 (2op) , 2/2=1 (3op) 

int fr[N];
void testcase() {
	int n; cin >> n;
	int mx = 0;
	int m = n;
	int finalVal = 1, mnCost = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) finalVal *= i;
		while (n % i == 0) n /= i, fr[i]++, mx = max(fr[i], mx);
	}
	if (n > 1) fr[n]++, mx = max(fr[n], mx), finalVal *= n;
	for (int i = 2; i <= m; i++) {
		mnCost |= (fr[i] && (fr[i] != mx));
	}
	mnCost |= (mx > 1 && !(mx && (!(mx & (mx - 1)))));
	while (!(mx && (!(mx & (mx - 1))))) mx++;
	while (mx > 1) {
		mnCost++;
		mx >>= 1;
	}
	//dbg(mx);
	cout << finalVal << " " << mnCost;









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
