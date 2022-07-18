
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class D {
    public static class Item {
        char c;
        int index;

        public Item(char c, int index) {
            this.c = c;
            this.index = index;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            String s = br.readLine();
            int count = Integer.parseInt(br.readLine());
            PriorityQueue<Item> pq = new PriorityQueue<>(new Comparator<Item>() {
                @Override
                public int compare(Item item, Item t1) {
                    return t1.c - item.c;
                }
            });
            List<Item> list = new ArrayList<>();
            int sum = 0;
            char[] chars = s.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                list.add(new Item(chars[i], i));
                pq.add(new Item(chars[i], i));
                sum += (chars[i] - 'a' + 1);
            }

            while (sum > count && !pq.isEmpty()) {
                Item item = pq.poll();
                list.get(item.index).index = -1;
                sum -= (item.c - 'a' + 1);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i).index != -1) {
                    sb.append(list.get(i).c);
                }
            }
            System.out.println(sb.toString());
        }
    }
}
