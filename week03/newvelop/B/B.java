
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Collectors;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int total = Integer.parseInt(br.readLine());
        for (int t = 0; t < total; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int index = 0;
            int[] result = new int[arr.length];
            boolean flag = true;

            for (int i = 1; i < arr.length; i++) {
                if (arr[i] != arr[i - 1]) {
                    if (i - index == 1) {
                        System.out.println(-1);
                        flag = false;
                        break;
                    } else {
                        for (int j = index; j < i; j ++) {
                            if (j == i - 1) {
                                result[j] = index + 1;
                            } else {
                                result[j] = j + 2;
                            }
                        }
                        index = i;
                    }
                }
            }

            if (flag) {
                if (arr.length - index != 1) {
                    for (int j = index; j < arr.length; j++) {
                        if (j == arr.length - 1) {
                            result[j] = index + 1;
                        } else {
                            result[j] = j + 2;
                        }
                    }
                } else {
                    System.out.println(-1);
                    continue;
                }

                System.out.println(Arrays.stream(result)
                        .mapToObj(String::valueOf)
                        .collect(Collectors.joining(" ")));
            }

        }
    }
}
