/**
 * Created on: 2025-02-12
 * Author: yassjd199
 * https://codeforces.com/problemset/problem/1490/D
 */



#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 200000
int n , a[N] , depth[N];

void calc(int l , int r , int d) {
    if (l > r) return;
    int mid = l , mx = -1;
    for (int i = l; i <= r; i++) {
        if (a[i] > mx) {
            mx = a[i];
            mid = i;
        }
    }
    if (mx != -1) {
        depth[mid] = d;
        calc(l , mid - 1 , d + 1);
        calc(mid + 1 , r , d + 1);
    }
}
 
int main( ) {
    int _;
    scanf("%d" , &_);
    while (_--) {
        scanf("%d" , &n);
        for (int i = 0; i < n; i++)
            scanf("%d" , &a[i]);

        calc(0 , n - 1 , 0);
        for (int i = 0; i < n; i++) printf("%d " , depth[i]);
        printf("\n");
    }

}
