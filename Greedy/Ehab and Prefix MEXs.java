/*
 * Author: yassjd199
 * https://codeforces.com/contest/1364/problem/C
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
        int B[] = in.readArray(n);

        int A[] = new int[n];
        Arrays.fill(A, n + 5);
        TreeSet<Integer> ts = new TreeSet<>();
        ArrayList<Integer> ava = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ava.add(i);
            if (i == 0) {
                if (B[i] == 1) {
                    A[i] = 0;
                    ava.removeLast();
                    ts.add(0);
                }
            } else {
                int first = B[i], last = B[i] - 1;
                if (!ts.isEmpty()) {
                    first = ts.getFirst();
                    last = ts.getLast();
                }

                int toAdd = first + B[i] - 1 - last;
                // dbg(i, "toAdd: ", toAdd);
                if (toAdd <= 0)
                    continue;

                if (toAdd > ava.size()) {
                    out.println(-1);
                    return;
                }
                for (int k = 0; k < first; k++) {
                    ts.add(k);
                    A[ava.getLast()] = k;
                    ava.removeLast();
                }
                for (int k = last + 1; k < B[i]; k++) {
                    ts.add(k);
                    A[ava.getLast()] = k;
                    ava.removeLast();
                }

            }
            // dbg(A);
        }

        for (int x : A) {
            out.printf("%d ", x);
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
