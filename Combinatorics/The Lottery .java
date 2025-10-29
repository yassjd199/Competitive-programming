/*
 * Author: yassjd199
 * https://vjudge.net/problem/UVA-10325
 * Inclusion exclusion principle:
 * one way to do it is add the contribution of sets with odd size and substract the contribution of sets with even size
 * because When the size of the set is odd, it adds something new to the count.And when the size of th set is even, it cancels something that was already added before.
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
    // static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return b * (a / gcd(a, b));
    }

    static void testcase() {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            long n = sc.nextLong();
            int m = sc.nextInt();
            long A[] = new long[m];
            for (int i = 0; i < m; i++) {
                A[i] = sc.nextLong();
            }
            long ans = n;

            for (int mask = 1; mask < (1 << m); mask++) {
                int setSz = 0;
                long LCM = 1;
                for (int bit = 0; bit < m; bit++) {
                    if ((mask & (1 << bit)) != 0) {
                        setSz++;
                        LCM = lcm(LCM, A[bit]);
                    }
                }
                long sg = (setSz % 2 == 0 ? 1 : -1);
                ans += (sg * (n / LCM));
            }
            out.println(ans);
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
