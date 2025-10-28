/*
 * Author: yassjd199
 * 
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

public class Main {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static int n, k, X, A[];

    static boolean ok(int x) {
        // cloud my answer be greater than or equal to x ?
        int p = 0;
        for (int i = 1; i < n; i++) {
            int l = A[i - 1] + x, r = A[i] - x;
            p += max(0, r - l + 1);

        }
        p += max(0, A[0] - x + 1);
        p += max(0, X - (A[n - 1] + x) + 1);
        return p >= k;
    }

    static void testcase() {
        n = in.nextInt();
        k = in.nextInt();
        X = in.nextInt();
        A = in.readArray(n);
        Arrays.sort(A);

        int l = 0, r = 1000000010, best = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (ok(m)) {
                best = m;
                l = m + 1;
            } else
                r = m - 1;
        }
        // dbg(best);

        TreeSet<Integer> ans = new TreeSet<>();
        for (int i = 1; i < n; i++) {
            int L = A[i - 1] + best, R = A[i] - best;
            if (L > R)
                continue;
            for (int u = L; u <= R && k > 0; u++) {
                if (ans.contains(u))
                    continue;
                ans.add(u);
                k--;
            }
        }
        // dbg(ans);
        for (int i = 0; i <= A[0] - best && k > 0; i++) {
            if (!ans.contains(i)) {
                ans.add(i);
                k--;
            }
        }
        for (int i = A[n - 1] + best; i <= X && k > 0; i++) {
            if (!ans.contains(i)) {
                ans.add(i);
                k--;
            }
        }

        for (Integer x : ans) {
            out.print(x + " ");
        }
        out.println();
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
