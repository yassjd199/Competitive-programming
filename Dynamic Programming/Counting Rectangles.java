

/*
 * Author: yassjd199
 * https://codeforces.com/contest/1722/problem/E
 *
 */

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import static java.lang.Math.round;


import java.io.*;
import java.util.*;


public class Main {

    // ----------- Fast Input -----------
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    // --------------------------------
    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static final int[] dx = {0, 0, -1, 1};
    static final int[] dy = {-1, 1, 0, 0};
    static final double EPS = 1e-9;
    static int[] a = new int[N];
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    //-------------------------------------
    static void testcase() {
        int n = in.nextInt(), q = in.nextInt();
        long[][] mat = new long[1010][1010];
        for (int i = 0; i < n; i++) {
            int h = in.nextInt(), w = in.nextInt();
            mat[h][w] += (long) h * w;
        }

        for (int i = 1; i <= 1001; i++) {
            for (int j = 1; j <= 1001; j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }


        while (q-- > 0) {
            int h1 = in.nextInt(), w1 = in.nextInt(), h2 = in.nextInt(), w2 = in.nextInt();
            h2--;
            w2--;
            h1++;
            w1++;
            out.println(mat[h2][w2] - mat[h1 - 1][w2] - mat[h2][w1 - 1] + mat[h1 - 1][w1 - 1]);
        }

    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        t = in.nextInt();
        for (int tt = 1; tt <= t; tt++) {
//            out.print("Case #" + tt + ": ");
            testcase();
        }
        out.flush();
        out.close();
        long end = System.currentTimeMillis();
        System.err.println("\nRun Time: " + (end - start) / 1000.0 + "s");
    }

    /*
         /\_/\
        (= ._.)
        / >  \>
     */
}
