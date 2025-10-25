// Author: yassjd199
// https://codeforces.com/contest/706/problem/C


#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = 1e-12;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll  long long int
#define llu unsigned
const int dx[4] = {0, 0, -1, 1}, dy[4] = { -1, 1, 0, 0};
//const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1} , dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const long long mod = 1e9 + 7;
const int N = 1e6 + 1, M = 20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


int n;
string aa[N];	
ll a[N];
ll dp[N][2];
bool ok(string a,string b){
	for(int i=0;i<min(a.size(),b.size());i++){
		if(a[i]!=b[i]) return a[i]<b[i];
	}
	return a.size()<=b.size();
}
ll solve(int i,int state){
	if(i>=n) return 0ll;
	if(dp[i][state]!=-1) return dp[i][state];
	ll ans=1e17;
	string str=aa[i],prev=aa[i-1];
	if(state) reverse(all(prev));
	// dont reverse ith string 
	if(ok(prev,str)) ans=min(ans,solve(i+1,0));
	//reverse ith string 
	reverse(all(str));
	if(ok(prev,str)) ans=min(ans,a[i]+solve(i+1,1));
	return dp[i][state]=ans;
	
	
}
void testcase() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
	memset(dp,-1,sizeof(dp));
	ll ans=min(solve(1,0),a[0]+solve(1,1));
	cout<<(ans<1e17 ? ans:-1);

	
	
}



int main() {
	fast;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	int tt = 1;
	clock_t z = clock();
	//cin>>t;

	while (t--) {
		//cout<<"Case #"<<tt++<<": ";
		testcase();
	}
	cerr << endl << "Run Time: " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
