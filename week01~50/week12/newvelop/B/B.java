

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            Set<Integer> set = new HashSet<>();
            int result = 0;
            for (int i = arr.length - 1; i>= 0; i--) {
                if (set.contains(arr[i])) {
                    result = i + 1;
                    break;
                }
                set.add(arr[i]);
            }

            System.out.println(result);
        }
    }
}
