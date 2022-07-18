
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int[] rail = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            Map<Integer, Integer> small = new HashMap<>();
            Map<Integer, Integer> big = new HashMap<>();

            for (int index = 0; index < rail.length; index++) {
                if (!small.containsKey(rail[index])) {
                    small.put(rail[index], index);
                }

                big.put(rail[index], index);
            }

            for (int i = 0; i < arr[1]; i++) {
                int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                int index1 = small.containsKey(input[0]) ? small.get(input[0]) : Integer.MAX_VALUE;
                int index2 = big.containsKey(input[1]) ? big.get(input[1]) : -1;
                if (index1 < index2) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}
