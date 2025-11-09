/*
 * Author: yassjd199
 * https://codeforces.com/contest/1398/problem/C
 */

import java.io.*;
import java.util.*;

public class Main {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = {0, 0, -1, 1, -1, -1, 1, 1};
    static int[] dy = {-1, 1, 0, 0, -1, 1, -1, 1};
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void testcase() {

        int n = in.nextInt();

        char S[] = in.next().toCharArray();

        long p[] = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (S[i - 1] - '0') * 1L;
        }

        for (int i = 1; i <= n; i++) {
            p[i] -= i;
        }

        HashMap<Long, Long> fr = new HashMap<>();

        // dbg(p) ;

        long ans = 0;

        for (int i = 0; i <= n; i++) {
            ans += (fr.containsKey(p[i]) ? fr.get(p[i]) : 0L);
            fr.put(p[i], fr.containsKey(p[i]) ? fr.get(p[i]) + 1 : 1);
        }

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
            for (int i = 0; i < n; i++) a[i] = nextInt();
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
