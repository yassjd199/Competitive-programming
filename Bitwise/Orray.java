/*
 * Author: yassjd199
 * https://codeforces.com/contest/1742/problem/G
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
    //    static final int[] dx = {0, 0, -1, 1};
    //    static final int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1, -1, -1, 1, 1};
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1};

    static final double EPS = 1e-9;
    static int[] a = new int[N];
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    //-------------------------------------


    static void testcase() {



        int n = in.nextInt();
        int [] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = in.nextInt();
        }

        int best = 0;
        boolean [] vis = new boolean[n];
        for (int i = 0 ; i < 30; i++) {
            int cur = best;
            int p = -1;
            for (int j = 0; j < n ; j++) {
                if (vis[j]) continue ;
                if ((best | A[j]) > cur) {
                    cur = (best | A[j]);
                    p = j ;
                }

            }
            if (p != -1) {
                out.print(A[p] + " ");
                best = cur ;
                vis[p] = true ;
            }
        }






        for (int i = 0; i < n; i++) {
            if (!vis[i]) out.print(A[i] + " ");
        }

        out.println();






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
