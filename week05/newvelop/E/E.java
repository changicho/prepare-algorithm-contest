
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class E {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int[] leftArr = new int[arr.length];
            int[] rightArr = new int[arr.length];
            int total = 0;
            for (int i = 0; i< arr.length; i++) {
                total += arr[i];
                if (i == 0) {
                    leftArr[i] = arr[i];
                } else {
                    leftArr[i] = leftArr[i - 1] + arr[i];
                }
            }

            if (input[1] > total) {
                System.out.println( -1);
                continue;
            } else if (input[1] == total) {
                System.out.println(0);
                continue;
            }

            for (int i = arr.length - 1; i >= 0; i--) {
                if (i == arr.length - 1) {
                    rightArr[i] = arr[i];
                } else {
                    rightArr[i] = rightArr[i + 1] + arr[i];
                }
            }

            int rightIndex = arr.length - 1;
            int diff = total - input[1];
            while (rightArr[rightIndex] < diff) {
                rightIndex --;
            }

            int result = arr.length - rightIndex;

            int leftIndex = 0;
            while (leftArr[leftIndex] < diff) {
                int rest = diff - leftArr[leftIndex];
                while(rightIndex < arr.length && rightArr[rightIndex] >= rest) {
                    rightIndex++;
                }
                int tempSum = leftIndex + 1 + (arr.length - rightIndex + 1);
                result = Math.min(tempSum, result);
                leftIndex++;
            }

            result = Math.min(result, leftIndex + 1);

            System.out.println(result);
        }
    }
}
