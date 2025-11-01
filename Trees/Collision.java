/*
 * Author: yassjd199
 * https://atcoder.jp/contests/abc209/tasks/abc209_d
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
    static ArrayList<Integer> adj[] = new ArrayList[N];
    static int color[] = new int[N];

    static void dfs(int cur, int p) {

        color[cur] = color[p] ^ 1;

        for (int nd : adj[cur]) {
            if (nd == p)
                continue;
            dfs(nd, cur);
        }
    }

    static void testcase() {
        int n = in.nextInt();
        int q = in.nextInt();
        for (int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt(), v = in.nextInt();
            adj[u].add(v);
            adj[v].add(u);
        }
        color[0] = 0;
        dfs(1, 0);

        while (q-- > 0) {
            int u = in.nextInt(), v = in.nextInt();
            out.println(color[u] == color[v] ? "Town" : "Road");
        }

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
