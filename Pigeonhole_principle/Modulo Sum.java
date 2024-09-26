import java.io.*;
import java.util.*;

/*
    made by yassjd199
    https://codeforces.com/problemset/problem/577/B
*/
public class Main {


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

    final static int MX = (int) 1e3 + 3;
    static int n, m;
    static int[] a = new int[MX];
    static int[][][] dp = new int[MX][MX][2];

    static boolean solve(int i, int x, int ok) {
        // System.err.println(i + " " + x + " " + ok);
        if (i >= n) {
            return ((x % m) == 0 && ok == 1);
        }
        if (dp[i][x][ok] != -1) return (dp[i][x][ok] == 1) ? true : false;
        boolean ret = false;
        ret = solve(i + 1, (x % m + a[i] % m) % m, 1) || solve(i + 1, x, ok);
        dp[i][x][ok] = ret ? 1 : 0;
        return ret;
    }

    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        FastReader in = new FastReader();
        n = in.nextInt();
        m = in.nextInt();
        if (n > m) { // let's look a the prefix sums y pigeonhole principle, there should be two equals sums modulo m so p[r]-p[l-1]=0 divisible by m
            out.println("YES");
            out.flush();
            out.close();
            return;

        }
        // else lets use a dynamic programming  approach for finding such a sequence which is ok since n<=m=1001
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        out.println(solve(0, 0, 0) ? "YES" : "NO");

        out.flush();
        out.close();
    }

}
