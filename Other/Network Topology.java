/*
 * Author: yassjd199
 * https://codeforces.com/contest/292/problem/B
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
    static int n, m;
    static ArrayList<Integer>[] adj = new ArrayList[N];
    static int deg[] = new int[N];

    static void testcase() {
        n = in.nextInt();
        m = in.nextInt();
        int mx = 0, c = 1;
        for (int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = in.nextInt(), b = in.nextInt();
            adj[a].add(b);
            adj[b].add(a);
            deg[a]++;
            deg[b]++;
            if (deg[a] > mx) {
                mx = deg[a];
                c = a;
            }
            if (deg[b] > mx) {
                mx = deg[b];
                c = b;
            }
        }
        boolean ring = (m == n);
        for (int i = 1; i <= n; i++) {
            if (deg[i] != 2) {
                ring = false;
                break;
            }
        }
        if (ring) {
            out.print("ring topology");
            return;
        }
        int deg1 = 0, deg2 = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1)
                deg1++;
            else
                deg2++;
        }
        if (deg1 == 2 && deg2 == n - 2 && m == n - 1) {
            out.print("bus topology");
            return;
        }
        boolean star = (m == n - 1);
        if (adj[c].size() != n - 1) {
            star = false;
        }
        for (int i = 1; i <= n; i++) {
            if (i == c)
                continue;
            if (adj[i].size() > 1 || adj[i].get(0) != c) {
                star = false;
                break;
            }
        }
        if (star) {
            out.print("star topology");
            return;
        }

        out.print("unknown topology");
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
