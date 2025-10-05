/**
 * Author: yassjd199
 * https://vjudge.net/problem/UVA-11404
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

string txt ;


int dp[1005][1005];


int S(int l , int r) {
	if (l == r) return 1;

	if (l > r) return 0;

	int &ret  = dp[l][r];

	if (~ret) return ret ;
	ret = 0;

	if (txt[l] == txt[r]) ret = max(ret , 2 + S(l + 1, r - 1));
	ret = max({ret , S(l + 1, r), S(l, r - 1)});

	return ret ;

}


string gen(int l, int r) {
	if (l == r) {

		return txt.substr(l, 1);
	}
	if (l > r) return "";


	int p1 = 0;
	int best = S(l, r);
	if (txt[l] == txt[r]) p1 = 2 + S(l + 1, r - 1);
	int p2 = S(l + 1, r), p3 = S(l, r - 1);
	string ret = "{";

	if (best == p1) ret = min(ret , txt[l] + gen(l + 1, r - 1) + txt[l]);
	if (best == p2) ret = min(ret , gen(l + 1, r));
	if (best == p3) ret = min(ret , gen(l, r - 1));
	return ret ;
}




void testcase( ) {


	while (cin >> txt) {


		int len = txt.size();

		memset(dp, -1, sizeof(dp));
		cout << gen(0, len - 1) << endl;


	}




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
