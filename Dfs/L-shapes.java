

/*
 * Author: yassjd199
 * https://codeforces.com/contest/1722/problem/F
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
    static int[] dy = {-1, 1, 0, 0, -1, 1, -1, 1};

    static final double EPS = 1e-9;
    static int[] a = new int[N];
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    //-------------------------------------
    static char[][] grid = new char[52][52];
    static int n, m;
    static Boolean[][] vis = new Boolean[52][52];

    static Boolean Lshape(int i1, int j1, int i2, int j2, int i3, int j3) {
        if (i1 == i2 && i1 == i3) return false;
        if (j1 == j2 && j1 == j3) return false;
        if (i1 == i2) {
            if (j3 == j1 || j3 == j2) return true;
        }
        if (i1 == i3) {
            if (j1 == j2 || j3 == j2) return true;
        }
        if (i2 == i3) {
            if (j2 == j1 || j3 == j1) return true;
        }
        if (j1 == j2) {
            if (i1 == i3 || i2 == i3) return true;
        }
        if (j1 == j3) {
            if (i1 == i2 || i3 == i2) return true;

        }
        if (j2 == j3) {
            if (i2 == i1 || i3 == i1) return true;
        }
        return false;
    }

    static ArrayList<int[]> A = new ArrayList<>();

    static Boolean ok(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    static void dfs(int i, int j) {
        if (vis[i][j]) return;
        vis[i][j] = true;
        A.add(new int[]{i, j});

        for (int k = 0; k < 8; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (ok(x, y) && grid[x][y] == '*') {
                dfs(x, y);
            }
        }
    }


    static void testcase() {
        n = in.nextInt();
        m = in.nextInt();
        for (int i = 0; i < n; i++) {
            String row = in.next();
            for (int j = 0; j < m; j++) {
                vis[i][j] = false;
                grid[i][j] = row.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*' && !vis[i][j]) {
                    A.clear();
                    dfs(i, j);

                    if (A.size() != 3) {
                        out.println("NO");
                        return;
                    }
                    if (!Lshape(A.get(0)[0], A.get(0)[1], A.get(1)[0], A.get(1)[1], A.get(2)[0], A.get(2)[1])) {
                        out.println("NO");
                        return;
                    }
                }
            }
        }
        out.println("YES");


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
