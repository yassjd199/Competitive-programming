import java.io.*;
import java.util.*;

/*
    author: yassjd199
    https://codeforces.com/contest/1692/problem/F
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
    static int N = 1000001;
    static  int [] a = new int [N];
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        int t=in.nextInt();
        for(int tt=0;tt<t;tt++) {
            int n = in.nextInt();
            int [] fr = new int [10];
            for(int i =0;i<n ; i++) {
                a[i] = in.nextInt() % 10;
                fr[a[i]%10]++;
            }
            Boolean ok = false ;
            for(int a =0;a<=9;a++){
                for(int b =0;b<=9;b++){
                    for(int c =0;c<=9;c++){
                        if ((a+b+c)%10==3){
                            int [] fr1 = new int [10];
                            fr1[a]++;
                            fr1[b]++;
                            fr1[c]++;
                            if(fr[a]-fr1[a]>=0 && fr[b]-fr1[b]>=0 && fr[c]-fr1[c]>=0 ){
                               ok=true;
                            }
                        }
                    }
                }
            }
            out.println(ok? "YES":"NO");


        }






        out.flush();
        out.close();
    }

}
