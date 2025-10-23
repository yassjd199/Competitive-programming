/*
 * Author: yassjd199
 * https://codeforces.com/contest/1807/problem/F
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
    static int Ex, Ey;
    static int ans;
    static boolean vis = false;

    static boolean ok(int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);

    }

    static void dfs(int i, int j, int Dx, int Dy, int cnt) {
        // dbg(i, j);
        if (cnt <= 0)
            return;

        if (!ok(i, j))
            return;

        if (i == Ex && j == Ey)
            vis = true;
        int flip = 0;
        if (i + Dx < 0 || i + Dx >= n) {
            Dx *= -1;
            flip = 1;
        }
        if (j + Dy < 0 || j + Dy >= m) {
            Dy *= -1;
            flip = 1;
        }
        if (!vis)
            ans += flip;
        dfs(i + Dx, j + Dy, Dx, Dy, cnt - 1);
    }

    static void testcase() {
        n = in.nextInt();
        m = in.nextInt();
        ans = 0;
        vis = false;
        int Sx = in.nextInt(), Sy = in.nextInt();
        Ex = in.nextInt();
        Ey = in.nextInt();
        Sx--;
        Sy--;
        Ex--;
        Ey--;
        String dir = in.next();
        int Dx, Dy;
        switch (dir) {
            case "DR":
                Dx = Dy = 1;
                break;
            case "DL":
                Dx = 1;
                Dy = -1;
                break;
            case "UR":
                Dx = -1;
                Dy = 1;
                break;
            default:
                Dx = Dy = -1;
                break;
        }
        dfs(Sx, Sy, Dx, Dy, 2 * n * m); // 4*n*m to be safe
        if (!vis)
            ans = -1;
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
