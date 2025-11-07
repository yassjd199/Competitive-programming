/*
 * Author: yassjd199
 * https://codeforces.com/contest/1271/problem/C
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

    static int X[], Y[], n, Sx, Sy;

    static int manhattan(int x, int y, int i, int j) {
        return abs(x - i) + abs(y - j);
    }

    static int F(int x, int y) {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (manhattan(Sx, Sy, X[i], Y[i]) == 1 + manhattan(x, y, X[i], Y[i]))
                ret++;
        }
        return ret;
    }

    // note that every student should go throught one of the 4 points directly
    // adjecent to the school to reach the school , so it is optimal to put the
    // shwarma shop in on of them
    static void testcase() {
        n = in.nextInt();
        Sx = in.nextInt();
        Sy = in.nextInt();

        X = new int[n];
        Y = new int[n];

        for (int i = 0; i < n; i++) {
            X[i] = in.nextInt();
            Y[i] = in.nextInt();
        }
        int Ax = 0, Ay = 0, mx = 0;
        for (int i = 0; i < 4; i++) {
            int tmp = F(Sx + dx[i], Sy + dy[i]);
            if (tmp > mx) {
                mx = tmp;
                Ax = Sx + dx[i];
                Ay = Sy + dy[i];
            }
        }
        out.println(mx);
        out.printf("%d %d", Ax, Ay);

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
