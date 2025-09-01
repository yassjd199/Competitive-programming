/**
 * Author: yassjd199
 * https://codeforces.com/contest/546/problem/D
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
const int  M = 20;
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


const int N = 5000001;
int ct[N];

// Sieve and SieveForPrimeFactorisation are tow preprocessing functions they may be called in main in case of mutlitple testcases ;
const int MX = 10000000;
int sieve[MX + 1]; // for prime factorization in O(MXlog(MX));
int prime[MX + 1]; // for getting primes up to MX;
void Sieve() {
    prime[1] = prime[0] = 0;
    prime[2] = 1;
    for (int i = 3; i <= MX; i += 2) {
        prime[i] = 1;
    }
    for (ll i = 3; i <= MX; i++)
        if (prime[i])
            for (ll j = i * i; j <= MX; j = j + i)
                prime[j] = 0;

}
///////////////////////////////////////// prime factorization in O(Nlog(N))///////////////////////////////////////
/// dont forget to  call SieveForPrimeFactorisation  !!!!
void SieveForPrimeFactorisation() { // marks x with its smallest prime factor ;
    for (int i = 1; i <= MX; i++) {
        sieve[i] = i;
    }
    for (ll i = 2; i <= MX; i++)
        if (sieve[i] == i)
            for (ll j = i * i; j <= MX; j = j + i)
                if (sieve[j] == j)
                    sieve[j] = i;
}


unordered_map<ll, ll> getFactorisation(ll x) {
    unordered_map<ll, ll> ret;
    while (x != 1) {
        ret[sieve[x]]++;
        x = x / sieve[x];
    }
    return ret;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int f (int x) {
    int ret = 0;
    while (x != 1) {
        ret++;
        x = x / sieve[x];
    }
    return ret;
}

void testcase( ) {

    int a, b; cin >> a >> b;

    cout << ct[a] - ct[b] << endl;

}








int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SieveForPrimeFactorisation();
    for (int x = 1; x < N; x++) {
        ct[x] = f(x) + ct[x - 1];
    }



    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int _ = 1;
    // int __ = 1;
    clock_t z = clock( );
    cin >> _;

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
