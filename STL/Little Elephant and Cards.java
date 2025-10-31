/*
 * Author: yassjd199
 * https://codeforces.com/contest/204/problem/B
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

    static void testcase() {
        int n = in.nextInt();
        HashMap<Integer, int[]> mp = new HashMap<>();
        HashSet<Integer> unique = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int face = in.nextInt(), back = in.nextInt();
            unique.add(face);
            unique.add(back);

            if (!mp.containsKey(face)) {
                mp.put(face, new int[] { 1, 0 });
            } else {
                mp.get(face)[0]++;
            }
            if (face != back) {
                if (!mp.containsKey(back)) {
                    mp.put(back, new int[] { 0, 1 });
                } else {
                    mp.get(back)[1]++;
                }
            }
        }
        int ans = n + 1;

        for (Integer x : unique) {
            int up = mp.get(x)[0], down = mp.get(x)[1];
            if (up + down < (n + 1) / 2)
                continue;
            // dbg(x, up, down);
            // dbg(x, (n + 1) / 2 - up);
            ans = min(ans, max(0, ((n + 1) / 2) - up));
        }
        if (ans > n)
            ans = -1;
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
