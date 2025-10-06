/**
 * Author: yassjd199
 * https://vjudge.net/problem/UVA-607
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

int n , L, C;
vii T;
int dp1[1010];
ll dp2[1010];

int S(int i) {
	if (i == n) return 0 ;
	if (i > n) return 1e9;
	int &ret = dp1[i];
	if (~ret) return ret ;
	ret = 1e9;
	for (int j =  i, sm = 0;  sm <= L; j++) {
		sm += T[j];
		if (sm <= L)
			ret = min(ret , 1 + S(j + 1));
	}
	return ret ;
}

ll F(int i) {
	if (i == n) return 0LL;
	if (i > n) return 1e18;
	ll &ret = dp2[i];
	if (~ret) return ret ;
	int x = S(i);

	ret = 1e18;
	for (ll j = i , sm = 0LL; sm <= L; j++) {
		sm += T[j];
		if (sm <= L) {
			if (1 + S(j + 1) == x) {
				ll diff = ( L * 1LL) - sm;
				ll cur = 0LL;
				if (diff > 0 && diff <= 10) cur = -C * 1LL;
				else if (diff > 10) cur = (diff - 10) * (diff - 10);
				ret = min(ret , cur + F(j + 1)) ;
			}
		}
	}



	return ret  ;
}

void testcase( ) {
	int t = 1;
	while (cin >> n && n) {
		cin >> L >> C;
		T.clear();
		T.resize(n);
		for (int i = 0; i < n; i++) cin >> T[i];
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		if (t != 1) cout << endl;
		cout << "Case " << t++ << ":" << endl;
		cout << "Minimum number of lectures: " << S(0) << endl;
		cout << "Total dissatisfaction index: " << F(0) << endl;


	}


}



int main( ) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int _ = 1;
	int __ = 1;
	clock_t z = clock( );
	// cin >> _;

	while (_--) {
		// cout << "Case " << __++ << ": " << endl;
		testcase( );
	}

	cerr << endl << "Run Time: " << ((double)(clock( ) - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
//
