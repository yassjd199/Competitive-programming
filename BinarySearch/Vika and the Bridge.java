/*
 * Author: yassjd199
 * https://codeforces.com/contest/1848/problem/B
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
    static ArrayList<Integer> pos[] = new ArrayList[N];
    static int n, k;

    static boolean ok(int step) {

        boolean can = false;
        outer: for (int i = 1; i <= k; i++) {
            boolean chance = true;
            if (pos[i].isEmpty())
                continue;
            for (int j = 1; j < pos[i].size(); j++) {
                if (pos[i].get(j) - pos[i].get(j - 1) - 1 > step) {
                    if (chance) {
                        if (pos[i].get(j) - pos[i].get(j - 1) - 2 > 2 * step)
                            continue outer;
                        chance = false;
                    } else {
                        continue outer;
                    }
                }

            }
            can = true;
        }
        return can;
    }

    static void testcase() {
        n = in.nextInt();
        k = in.nextInt();
        int C[] = in.readArray(n);
        for (int i = 1; i <= k; i++) {
            pos[i] = new ArrayList<>();
        }
        for (int i = 1; i <= k; i++) {
            pos[i].add(0);
        }
        for (int i = 0; i < n; i++) {
            pos[C[i]].add(i + 1);
        }
        for (int i = 1; i <= k; i++) {
            pos[i].add(n + 1);
        }

        int l = -1, r = n;
        while (r > 1 + l) {
            int m = (l + r) / 2;
            if (ok(m)) {
                r = m; // it works → try smaller
            } else {
                l = m; // impossible → try larger
            }
        }
        out.println(r);

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
