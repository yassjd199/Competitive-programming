/**
 * Created on: 2025-02-13
 * Author: yassjd199
 * https://codeforces.com/contest/1487/problem/D
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
/*

(a , b , c): 3 4 5
(a , b , c): 5 12 13
(a , b , c): 7 24 25
(a , b , c): 9 40 41
(a , b , c): 11 60 61
(a , b , c): 13 84 85
(a , b , c): 15 112 113
(a , b , c): 17 144 145
(a , b , c): 19 180 181
(a , b , c): 21 220 221
(a , b , c): 23 264 265
(a , b , c): 25 312 313
(a , b , c): 27 364 365
(a , b , c): 29 420 421
(a , b , c): 31 480 481
(a , b , c): 33 544 545
(a , b , c): 35 612 613
(a , b , c): 37 684 685
(a , b , c): 39 760 761
(a , b , c): 41 840 841
(a , b , c): 43 924 925


this is the brute force for a,b,c<=1000 ,lets focus on the values of c , note that

c[1] = 5
c[i] = c[i-1] +4*i; for i>=2

c[i=100000] is already greater than 1e9 , so time complexity is not an issue here


*/

vll v;

void testcase( ) {
    int n; cin >> n;
    int pos = upper_bound(all(v) , n) - v.begin( );

    cout << pos << endl;



}

int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (ll i = 2 , a = 5; a <= 1e9; a += 4 * i , i++) v.emplace_back(a);
    //dbg(v[0]);
    //dbg(v.size( ));
    //dbg(v.back( ));
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
