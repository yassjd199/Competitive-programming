/**
 * Created on: 2025-02-12
 * Author: yassjd199
 *https://codeforces.com/contest/1741/problem/D
 */



#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 262145
void swap(int* a , int* b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
int n , a[N];
int ans = 0;
void calc(int l , int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    calc(l , m); calc(m + 1 , r);
    if (m + 1 <= r) {
        if (a[m] > a[m + 1]) {
            ans++;
            for (int i = l; i <= m; i++) swap(&a[i] , &a[m + (i - l) + 1]);
        }
    }
}

int main( ) {
    int _;
    scanf("%d" , &_);
    while (_--) {
        ans = 0;
        scanf("%d" , &n);
        for (int i = 0; i < n; i++)
            scanf("%d" , &a[i]);
        calc(0 , n - 1);
        //for (int i = 0; i < n; i++) printf("%d " , a[i]);
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                ans = -1;
                break;
            }
        }
        printf("%d\n" , ans);
    }

}
