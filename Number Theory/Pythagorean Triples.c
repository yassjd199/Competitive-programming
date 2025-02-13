/**
 * Created on: 2025-02-13
 * Author: yassjd199
 * https://codeforces.com/contest/1487/problem/D
 */



#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 262145

int main( ) {
    int _;
    scanf("%d" , &_);
    while (_--) {
        int n;
        scanf("%d" , &n);
        int ans = 0;
        for (int a = 2; a * a <= 2 * n + 1; a++) {
            if ((a * a - 1) % 2) continue;
            int b = (a * a - 1) / 2;
            int c = b + 1;
            if (b > n || c > n || a > n) continue;
            ans++;
        }
        printf("%d\n" , ans);
    }

}
