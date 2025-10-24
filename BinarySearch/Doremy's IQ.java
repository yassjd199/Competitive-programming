/*
 * Author: yassjd199
 * https://codeforces.com/contest/1708/problem/C
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
    static int n, q;
    static int A[];

    /*
     * lets look at the final solution: will have some contests that will not be
     * done lets suppose that there number is x
     * 
     * if we dont do x , we can also dont do x+1 (so binary search on the minimal
     * number of contests that will not be done)
     * 
     * 
     * now how to check if we can skip x contests and have q>=0 at the end
     * 
     * lets look at the case x = 1 (skip on contest) we can skip contest at index i
     * or at index j (j>i) it is clear that if
     * skip the contest with the smaller index will have a better or equal solution
     * to the case where we skip j
     * 
     * 
     * so if we want to check if we can skip x contests the we can greedily skip the
     * first x contests and check if it correct in O(n);
     * 
     * final time complexity is O(nlog(n)) ;
     * but it can be done greedily in O(n) by starting in the reverse order
     */
    static boolean ok(int x) {
        ArrayList<Integer> pos = new ArrayList<>();
        int curQ = q;
        for (int i = 0; i < n && pos.size() < x; i++) {
            if (A[i] > curQ)
                pos.add(i);
        }
        if (pos.size() < x)
            return true;

        for (int i = 0, j = 0; i < n; i++) {
            if (A[i] > curQ) {
                if (j < pos.size() && i == pos.get(j)) {
                    j++;
                } else {
                    curQ--;
                }
            }
        }
        // dbg(curQ);
        // dbg(" ");
        return curQ >= 0;

    }

    static void testcase() {
        n = in.nextInt();
        q = in.nextInt();
        A = in.readArray(n);

        char S[] = new char[n];
        for (int i = 0; i < n; i++)
            S[i] = '1';
        if (q >= n) {
            out.println(S);
            return;
        }

        int l = 0, r = n, dontDo = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (ok(m)) {
                dontDo = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        ArrayList<Integer> pos = new ArrayList<>();

        for (int i = 0; i < n && pos.size() < dontDo; i++) {
            if (A[i] > q)
                pos.add(i);
        }

        for (int i = 0, j = 0; i < n; i++) {
            if (A[i] > q) {
                if (j < pos.size() && i == pos.get(j)) {
                    j++;
                    S[i] = '0';
                    continue;
                }
            }
        }

        out.println(S);

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
