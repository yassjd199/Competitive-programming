/*
 * Author: yassjd199
 * https://codeforces.com/contest/2156/problem/C
 */

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.Math.floor;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import static java.lang.Math.round;

import java.io.*;
import java.util.*;

public class G {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);


    static void testcase() {
        int n = in.nextInt();
        int k = in.nextInt();
        int A[] = in.readArray(n);
        int fr[] = new int[n + 2];
        for (int i = 0; i < n; i++)
            fr[A[i]]++;
        Arrays.sort(A);
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            int toErase = lower(A, 0, n - 1, i) + 1;
            int rangeTot = lower(A, 0, n - 1, 4 * i) - ceiling(A, 0, n - 1, i) + 1;
            for (int j = i; j <= min(n, 3 * i); j += i) {
                rangeTot -= fr[j];
            }

            toErase += rangeTot;
            if (toErase <= k) {
                ans = i;
                break;
            }
        }
        out.println(ans);

    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        t = in.nextInt();
        for (int tt = 1; tt <= t; tt++) {
            testcase();
        }
        out.flush();
        out.close();
        long end = System.currentTimeMillis();
        System.err.println("\nRun Time: " + (end - start) / 1000.0 + "s");
    }

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    // Search in range [l, r] inclusive
    static int ceiling(int[] nums, int l, int r, int target) {
        int left = l, right = r + 1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left; // first index in [l, r] where nums[index] >= target
    }

    // Search in range [l, r] inclusive
    static int higher(int[] nums, int l, int r, int target) {
        int left = l, right = r + 1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left; // first index in [l, r] where nums[index] > target
    }

    // Search in range [l, r] inclusive
    static int floor(int[] nums, int l, int r, int target) {
        int left = l - 1, right = r;
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        return left; // last index in [l, r] where nums[index] <= target
    }

    // Search in range [l, r] inclusive
    static int lower(int[] nums, int l, int r, int target) {
        int left = l - 1, right = r;
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            if (nums[mid] < target)
                left = mid;
            else
                right = mid - 1;
        }
        return left; // last index in [l, r] where nums[index] < target
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return "";
        }
    }

    /*
     * /\_/\
     * (= ._.)
     * / > \>
     */
}
