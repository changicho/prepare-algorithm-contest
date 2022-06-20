
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class F {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            Map<Integer, Integer> map = new HashMap<>();
            for (int n : arr) {
                int digit = n % 10;
                if (!map.containsKey(digit)) {
                    map.put(digit, 1);
                } else {
                    if (map.get(digit) != 3) {
                        map.put(digit, map.get(digit) + 1);
                    }
                }
            }

            List<Integer> list = new ArrayList<>();
            for (int key : map.keySet()) {
                for (int i = 0; i < map.get(key); i++) {
                    list.add(key);
                }
            }

            boolean flag = false;
            for (int i = 0; i < list.size() - 2; i++) {
                for (int j = i + 1; j < list.size() - 1; j++) {
                    for (int k = j + 1; k < list.size(); k++) {
                        int sum = list.get(i) + list.get(j) + list.get(k);
                        if (sum % 10 == 3) {
                            System.out.println("YES");
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (!flag) {
                System.out.println("NO");
            }
        }
    }
}
