/*
 * Author: yassjd199
 * https://codeforces.com/problemset/problem/1276/A
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
        char S[] = in.next().toCharArray();
        int n = S.length;
        StringBuilder T = new StringBuilder();

        int pos[] = new int[n];
        int cnt[] = new int[n];
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] == 'o')
                cur++;
            else {
                if (cur != 0) {
                    pos[T.length()] = i - 1;
                    cnt[T.length()] = cur;
                    T.append('o');
                }
                pos[T.length()] = i;
                T.append(S[i]);
                cur = 0;
            }

        }
        if (cur != 0) {
            pos[T.length()] = n - 1;
            cnt[T.length()] = cur;
            T.append('o');
        }
        S = T.toString().toCharArray();
        n = S.length;
        ArrayList<Integer> ans = new ArrayList<>();
        // dbg(S);
        for (int i = 0; i + 5 <= n; i++) {
            if (S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o' && S[i + 3] == 'n' && S[i + 4] == 'e') {
                // dbg(i, cnt[i + 2]);
                if (cnt[i + 2] <= 1) {
                    ans.add(pos[i + 2]);
                    S[i + 2] = '#';
                } else {
                    ans.add(pos[i + 1]);
                    ans.add(pos[i + 3]);
                    S[i + 1] = S[i + 3] = '#';
                }
            }

        }

        for (int i = 0; i + 3 <= n; i++) {
            if (S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o') {
                ans.add(pos[i + 1]);
            }
            if (S[i] == 'o' && S[i + 1] == 'n' && S[i + 2] == 'e') {
                ans.add(pos[i + 1]);
            }
        }

        out.println(ans.size());
        for (Integer x : ans) {
            out.printf("%d ", x + 1);
        }
        out.println();
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
