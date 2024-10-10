import java.io.*;
import java.util.*;

/*
    author: yassjd199
    https://www.codechef.com/AUG14/problems/REVERSE
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
    static final long MOD = 1000000007L;
    static class Node{
        public int e;
        public int w;
        public Node(int e, int w) {
            this.e = e;
            this.w = w;
        }
        //public Node(){}
    }
    static int  n,m;

    static ArrayList<Node> []adj = new ArrayList[MX];
    static int [] dis = new int[MX];
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        n=in.nextInt();
        m=in.nextInt();
        for(int i=1;i<=n;i++){
            adj[i] = new ArrayList<>();
            dis[i]=MX;
        }
        for(int i=0,a,b;i<m;i++){
            a=in.nextInt();
            b=in.nextInt();
            adj[a].add(new Node(b,0));
            adj[b].add(new Node(a,1));
        }
        Deque<Integer> dq = new ArrayDeque<>();
        dis[1]=0;
        dq.addFirst(1);
        while(!dq.isEmpty()){
            int u=dq.pollFirst();
           // System.err.println(u);
            for(Node nd : adj[u]){
                int e=nd.e;
                int w=nd.w;
                if(dis[u]+w<dis[e]){
                    dis[e]=dis[u]+w;
                    if(w==0) dq.addFirst(e);
                    else dq.addFirst(e);
                }
            }
        }
        out.println(dis[n]);



        out.flush();
        out.close();
    }

}import java.io.*;
import java.util.*;

/*
    author: yassjd199
    https://www.codechef.com/AUG14/problems/REVERSE
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
    static final long MOD = 1000000007L;
    static class Node{
        public int e;
        public int w;
        public Node(int e, int w) {
            this.e = e;
            this.w = w;
        }
        //public Node(){}
    }
    static int  n,m;

    static ArrayList<Node> []adj = new ArrayList[MX];
    static int [] dis = new int[MX];
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        n=in.nextInt();
        m=in.nextInt();
        for(int i=1;i<=n;i++){
            adj[i] = new ArrayList<>();
            dis[i]=MX;
        }
        for(int i=0,a,b;i<m;i++){
            a=in.nextInt();
            b=in.nextInt();
            adj[a].add(new Node(b,0));
            adj[b].add(new Node(a,1));
        }
        Deque<Integer> dq = new ArrayDeque<>();
        dis[1]=0;
        dq.addFirst(1);
        while(!dq.isEmpty()){
            int u=dq.pollFirst();
           // System.err.println(u);
            for(Node nd : adj[u]){
                int e=nd.e;
                int w=nd.w;
                if(dis[u]+w<dis[e]){
                    dis[e]=dis[u]+w;
                    if(w==0) dq.addFirst(e);
                    else dq.addFirst(e);
                }
            }
        }
        out.println(dis[n]);



        out.flush();
        out.close();
    }

}
