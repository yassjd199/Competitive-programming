import java.awt.*;
import java.io.*;
import java.util.*;

/*
    made by yassjd199
    https://codeforces.com/contest/427/problem/C
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

    static final int MX = 200005;
    static int n, m;
    static ArrayList<Integer>[] adj = new ArrayList[MX];
    static ArrayList<Integer>[] adjT = new ArrayList[MX];
    static long[] c = new long[MX];
    static boolean[] vis = new boolean[MX];
    static ArrayList<Integer> s = new ArrayList<>();


    static void order(Integer cur) {
        if (vis[cur]) return;
        vis[cur] = true;
        for (Integer nd : adj[cur]) {
            order(nd);
        }
        s.add(cur);
    }

    static long mn, mnCount;


    static void dfs(Integer cur) {
        if (vis[cur]) return;
        vis[cur] = true;
        if (c[cur - 1] < mn) {
            mn = c[cur - 1];
            mnCount = 1L;
        } else if (c[cur - 1] == mn) mnCount++;
        for (Integer nd : adjT[cur]) {
            dfs(nd);
        }
    }

    static final Long MOD = 1000000007L;

    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        FastReader in = new FastReader();
        n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
            adjT[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            c[i] = in.nextLong();
        }
        m = in.nextInt();
        for (int i = 0, a, b; i < m; i++) {
            a = in.nextInt();
            b = in.nextInt();
            adj[a].add(b);
            adjT[b].add(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) order(i);
        }
        long ans = 0L, cnt = 1L;
        for (int i = 0; i <= n; i++) vis[i] = false;
        Collections.reverse(s);
        for (Integer i : s) {
            if (!vis[i]) {
                mn = 10000000000L;
                mnCount = 0L;
                dfs(i);
                ans += mn;
                cnt *= mnCount;
                cnt %= MOD;
            }
        }
        out.println(ans + " " + cnt);
        out.flush();
        out.close();
    }

}
