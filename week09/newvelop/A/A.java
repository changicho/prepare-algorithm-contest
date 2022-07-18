import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        long[] test = new long[10];
        test[0] = 1L;
        for (int j = 1; j < test.length; j++) {
            test[j] = test[j - 1] * 10;
        }
        for (int t = 1; t <= tcase; t++) {
            long target = Long.parseLong(br.readLine());
            int index = 0;
            while (target > test[index]) {
                index ++;
            }
            if (test[index] == target) {
                System.out.println(0);
            } else {
                long result = 0;
                if (index == 0) {
                    result = target - 1;
                } else {
                    result = target - test[index - 1];
                }
                System.out.println(result);
            }
        }
    }
}
