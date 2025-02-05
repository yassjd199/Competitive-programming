/**
 * Created on: 2025-02-05
 * Author: yassjd199
 * https://codeforces.com/contest/1538/problem/D
 */
#include <stdio.h>
// C++ cloudnt passed the time limit , (in my case but it does for others) wired ?!

int main( ) {
    int t; scanf("%d" , &t);
    while (t--) {
        int a , b , k;
        scanf("%d" , &a); scanf("%d" , &b); scanf("%d" , &k);
 

        if (a == b && a == 1) {
            printf("NO\n");
            continue;
        }
        if (k == 1) {

            if (a == b) {
                printf("NO\n");
                continue;

            } 
            if (a % b == 0 || b % a == 0) {
                printf("YES\n");
            }
            else  printf("NO\n");
            continue;


        }
        for (int i = 2; i * i <= a; i++) {
            while (a % i == 0) k-- , a /= i;
        }
        if (a > 1) k--;
        for (int i = 2; i * i <= b; i++) {
            while (b % i == 0) k-- , b /= i;
        }
        if (b > 1) k--;
        if (k > 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
