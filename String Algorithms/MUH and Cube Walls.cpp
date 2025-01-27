    /**
     * Created on: 2025-01-27
     * Author: yassjd199
	 *https://codeforces.com/contest/471/problem/D
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
		int n,m;cin>>n>>m;
		

		
		vii a(n),b(m);
		for(int i =0;i<n;i++) cin>>a[i];
		for(int i =0;i<m;i++) cin>>b[i];

		if(m>n){
			cout<<0<<endl;
			return ;
		}
		
		if(n==1 || m==1){
		
			cout<<n<<endl;
			return ;
		}
		vii str(n-1),pat(m-1);
		for(int i=0;i<n-1;i++) str[i]=a[i+1]-a[i];	
		for(int i=0;i<m-1;i++) pat[i]=b[i+1]-b[i];

		vii pi(m-1);
		for(int i=1,k=0;i<m-1;i++){
			while(k>0 && pat[k]!=pat[i]) k=pi[k-1];
			if(pat[k]==pat[i]) pi[i]=++k;
			else pi[i]=k;
		}

		int ans=0;
		for(int i =0,k=0;i<n-1;i++){
			while(k>0 && str[i]!=pat[k]) k=pi[k-1];

			if(str[i]==pat[k]) ++k;

			if(k==m-1) ans++,k=pi[k-1];
		
		
		
		}

		cout<<ans<<endl;
    }

    int main( ) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // freopen("input.txt", "r", stdin);
        //bcababcab freopen("output.txt", "w", stdout);
        int _ = 1;
        // int __ = 1;
        clock_t z = clock( );
        //cin >> _;

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
