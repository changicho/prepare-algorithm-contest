import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            Set<Integer> set = new HashSet<>();
            for (int n : arr) {
                set.add(n);
            }
            if ((arr.length - set.size()) % 2 == 0) {
                System.out.println(set.size());
            } else {
                System.out.println(set.size() - 1);
            }
        }
    }
}
