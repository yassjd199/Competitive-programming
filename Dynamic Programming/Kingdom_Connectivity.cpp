// author : yassjd199
//https://www.hackerrank.com/challenges/kingdom-connectivity/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countPaths' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 */
#define ll long long

int n, m;
vector<int> adj[10002];
int state[10002];
vector<int> v;
vector<bool> vis;
void dfs(int cur) {
	state[cur] = 1;
	for (auto nd : adj[cur]) {
		if (state[nd] == 1) v.emplace_back(nd);
		if (state[nd] == 0) dfs(nd);
	}
	state[cur] = 2;
}
void dfs1(int cur) {
	if (vis[cur]) return ;
	vis[cur] = 1;
	for (auto nd : adj[cur]) dfs1(nd);
}
const int MOD = 1000000000;
ll dp[10004];
ll countPaths(int cur) {
	if (cur == 1) return 1;
	ll &ret = dp[cur];
	if (~ret) return ret;
	ret = 0;
	for (auto nd : adj[cur]) {
		ret += countPaths(nd);
		ret %= MOD;
	}
	return ret;
}

int main()
{
	string first_multiple_input_temp;
	getline(cin, first_multiple_input_temp);

	vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

	n = stoi(first_multiple_input[0]);

	m = stoi(first_multiple_input[1]);

	vector<vector<int>> edges(m);

	for (int i = 0; i < m; i++) {
		edges[i].resize(2);

		string edges_row_temp_temp;
		getline(cin, edges_row_temp_temp);

		vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

		for (int j = 0; j < 2; j++) {
			int edges_row_item = stoi(edges_row_temp[j]);

			edges[i][j] = edges_row_item;
		}
		adj[edges[i][1]].emplace_back(edges[i][0]);
	}
	dfs(n);
	fill(dp, dp + n + 1, -1);
	for (auto x : v) {
		if (state[x]) {
			vis.clear();
			vis.resize(n + 1, 0);
			dfs1(x);
			if (vis[1]) {
				cout << "INFINITE PATHS";
				return 0;
			}
		}
	}
	cout << countPaths(n);


	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
	    s.begin(),
	    find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
	    find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
	    s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
