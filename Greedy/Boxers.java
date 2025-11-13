/*
 * Author: yassjd199
 * https://codeforces.com/contest/1203/submission/348789584
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
        int fr[] = new int[150002];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            fr[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= 150001; i++) {
            if (fr[i - 1] > 0) {
                ans++;
                continue;
            }
            if (fr[i] > 0) {
                ans++;
                fr[i]--;
                continue;
            }
            if (i + 1 < 150001 && fr[i + 1] > 0) {
                ans++;
                fr[i + 1]--;
            }
        }
        out.println(ans);

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

    /*
     * Ordered MultiSet in java using TreeMap.
     * Can be iterated over.
     * 
     * setSize() returns the number of distinct elements in the multiset.
     * Other method names are either self-explanatory,
     * or same as TreeSet.
     */

    static class TreeMultiSet<T> implements Iterable<T> {
        private final TreeMap<T, Integer> map;
        private int size;

        public TreeMultiSet() {
            map = new TreeMap<>();
            size = 0;
        }

        public TreeMultiSet(boolean reverse) {
            if (reverse)
                map = new TreeMap<>(Collections.reverseOrder());
            else
                map = new TreeMap<>();
            size = 0;
        }

        public void clear() {
            map.clear();
            size = 0;
        }

        public int size() {
            return size;
        }

        public int setSize() {
            return map.size();
        }

        public boolean contains(T a) {
            return map.containsKey(a);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public Integer get(T a) {
            return map.getOrDefault(a, 0);
        }

        public void add(T a, int count) {
            int cur = get(a);
            map.put(a, cur + count);
            size += count;
            if (cur + count == 0)
                map.remove(a);
        }

        public void addOne(T a) {
            add(a, 1);
        }

        public void remove(T a, int count) {
            add(a, Math.max(-get(a), -count));
        }

        public void removeOne(T a) {
            remove(a, 1);
        }

        public void removeAll(T a) {
            remove(a, Integer.MAX_VALUE - 10);
        }

        public T ceiling(T a) {
            return map.ceilingKey(a);
        }

        public T floor(T a) {
            return map.floorKey(a);
        }

        public T first() {
            return map.firstKey();
        }

        public T last() {
            return map.lastKey();
        }

        public T higher(T a) {
            return map.higherKey(a);
        }

        public T lower(T a) {
            return map.lowerKey(a);
        }

        public T pollFirst() {
            T a = first();
            removeOne(a);
            return a;
        }

        public T pollLast() {
            T a = last();
            removeOne(a);
            return a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private final Iterator<T> iter = map.keySet().iterator();
                private int count = 0;
                private T curElement;

                public boolean hasNext() {
                    return iter.hasNext() || count > 0;
                }

                public T next() {
                    if (count == 0) {
                        curElement = iter.next();
                        count = get(curElement);
                    }
                    count--;
                    return curElement;
                }
            };
        }
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
