/*
  Ordered MultiSet in java using TreeMap.
  Can be iterated over.

  setSize() returns the number of distinct elements in the multiset.
  Other method names are either self-explanatory,
  or same as TreeSet.
*/

static class TreeMultiSet<T> implements Iterable<T> {
    private final TreeMap<T, Integer> map;
    private int size;

    public TreeMultiSet() {
        map = new TreeMap<>();
        size = 0;
    }

    public TreeMultiSet(boolean reverse) {
        if (reverse) map = new TreeMap<>(Collections.reverseOrder());
        else map = new TreeMap<>();
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
        if (cur + count == 0) map.remove(a);
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
