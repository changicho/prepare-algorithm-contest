
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            int sum = arr[1] * 60 + arr[2];
            int curMin = Integer.MAX_VALUE;

            for (int i = 0; i < arr[0]; i++) {
                Integer[] input = Arrays.stream(br.readLine().split(" ")).map(Integer::valueOf).toArray(Integer[]::new);
                int tempSum = input[0] * 60 + input[1];
                int temp = 0;
                if (sum <= tempSum) {
                    temp = tempSum - sum;
                } else {
                    temp = 24 * 60 - sum + tempSum;
                }


                if (curMin > temp) {
                    curMin = temp;
                }
            }

            System.out.println(curMin / 60 + " " + curMin % 60);
        }
    }
}
