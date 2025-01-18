// @author : yassjd199
//https://codeforces.com/contest/1360/problem/F
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
#define ll long long int
#define ull unsigned long long int
const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
// const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1} , dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const long long mod = 1e9 + 7;
const int N = 1e6 + 1, M = 20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
using Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V>
using Map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void dbg_out()
{
	cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
	cerr << ' ' << H;
	dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<string> v;
int n, m;
int dp[11][(1 << 11)];

bool solve(int i, int mask)
{
	if (i >= m)
		return 1;
	int &ret = dp[i][mask];
	if (~ret)
		return ret;
	ret = 0;
	for (char x = 'a'; x <= 'z'; x++)
	{
		bool ok = 1;
		for (int j = 0; j < n; j++)
		{
			if (x == v[j][i])
				continue;
			if (x != v[j][i] && (mask & (1 << j)) == 0)
				continue;
			ok = 0;
			break;
		}
		if (ok)
		{
			// dbg(i,x);
			int tmpMask = mask;
			for (int j = 0; j < n; j++)
			{
				if (x != v[j][i] && (mask & (1 << j)) == 0)
					tmpMask |= (1 << j);
			}
			ret |= solve(i + 1, tmpMask);
		}
	}
	return ret;
}

void print(int i, int mask)
{
	if (i >= m)
		return;

	for (char x = 'a'; x <= 'z'; x++)
	{
		bool ok = 1;
		for (int j = 0; j < n; j++)
		{
			if (x == v[j][i])
				continue;
			if (x != v[j][i] && (mask & (1 << j)) == 0)
				continue;
			ok = 0;
			break;
		}
		if (ok)
		{
			// dbg(i,x);
			int tmpMask = mask;
			for (int j = 0; j < n; j++)
			{
				if (x != v[j][i] && (mask & (1 << j)) == 0)
					tmpMask |= (1 << j);
			}
			if (solve(i + 1, tmpMask))
			{
				cout << x;
				print(i + 1, tmpMask);
				return;
			}
		}
	}
}

void testcase()
{

	cin >> n >> m;
	v.clear();
	v.resize(n);
	for (auto &x : v)
		cin >> x;

	memset(dp, -1, sizeof(dp));

	if (solve(0, 0))
	{
		print(0, 0);
		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int _ = 1;
	// int __ = 1;
	clock_t z = clock();
	cin >> _;

	while (_--)
	{
		// cout<<"Case #"<<__++<<": ";
		testcase();
	}

	cerr << endl
		 << "Run Time: " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}

/*   /\_/\
 *   (= ._.)
 *   / >  \>
 */
