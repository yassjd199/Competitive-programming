/*
 * Author: yassjd199
 * https://codeforces.com/contest/584/problem/C
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

/*

4 0
aaaa
aaaa


try to focus on taking care of (n-t) the number of simliar chartchers

 *
 * 
 * 
 */

public class Main {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void testcase() {
        int n = in.nextInt(), t = in.nextInt();
        char[] A, B;
        A = in.next().toCharArray();
        B = in.next().toCharArray();
        int same = 0;
        for (int i = 0; i < n; i++)
            same += (A[i] == B[i] ? 1 : 0);
        int s = n - t;
        if (s > same && (n + same) < 2 * s) {
            out.println(-1);
            return;
        }
        char ans[] = new char[n];
        Arrays.fill(ans, '#');
        for (int i = 0; i < n && s > 0; i++) {
            if (A[i] == B[i]) {
                s--;
                ans[i] = A[i];
            }
        }
        for (int i = 0, c = 0; i < n && s > 0; i++) {
            if (A[i] == B[i])
                continue;
            if (c == 0) {
                ans[i] = A[i];
            } else {
                ans[i] = B[i];
                s--;
            }
            c ^= 1;
        }
        outer: for (int i = 0; i < n; i++) {
            if (ans[i] == '#') {
                for (char x = 'a'; x <= 'c'; x++) {
                    if (x != A[i] && x != B[i]) {
                        ans[i] = x;
                        continue outer;
                    }
                }
            }
        }

        out.println(ans);

    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        // t = in.nextInt();
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
