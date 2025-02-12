/**
 * Created on: 2025-02-12
 * Author: yassjd199
 * https://codeforces.com/contest/1385/problem/D
 */



#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 200000
int n;

char str[N];
int calc(int l , int r , char x) {
    if (l > r) return 10000000;
    if (l == r) return (str[l] != x);
    int ret1 = 0 , ret2 = 0;
    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; i++) ret1 += (str[i] != x);
    for (int i = mid + 1; i <= r; i++) ret2 += (str[i] != x);
    char u = (char)((int)x + 1);
    return min(ret1 + calc(mid + 1 , r , u) , ret2 + calc(l , mid , u));
}

int main( ) {
    int _;
    scanf("%d" , &_);
    while (_--) {
        scanf("%d" , &n);
        scanf("%s" , str);
        printf("%d\n" , calc(0 , n - 1 , 'a'));
    }

}
