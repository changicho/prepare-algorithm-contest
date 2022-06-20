package codeforce.y2022.d0613_0619;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class H {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            int[] result = new int[3];

            int maxCount = 1;

            result[0] = arr[0];
            result[1] = 1;
            result[2] = 1;

            Set<Integer> visit = new HashSet<>();
            for (int i = 0; i < arr.length; i++) {
                int cur = arr[i];
                int curIndex = i;
                int curCount = 1;
                int j = i + 1;
                if (!visit.contains(i)) {
                    visit.add(i);
                    while (j < arr.length) {
                        if (cur != arr[j]) {
                            curCount--;
                        } else {
                            curCount++;
                            visit.add(j);
                        }

                        if (curCount == 0) {
                            break;
                        } else {
                            if (maxCount < curCount) {
                                maxCount = curCount;
                                result[0] = arr[j];
                                result[1] = curIndex + 1;
                                result[2] = j + 1;
                            }
                        }

                        j++;
                    }
                }
            }

            System.out.println(result[0] + " " + result[1] + " " + result[2]);
        }
    }
}
