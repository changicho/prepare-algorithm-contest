
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

            if (arr.length == 1) {
                System.out.println("YES");
                continue;
            }

            Map<Integer, Integer> map = new HashMap<>();
            //key 는 mod 숫자, value 는 십의자리 숫자 / 2 한것. 싸이클이 20 주기로 이뤄지기 때문
            map.put(6, -1);
            map.put(2, -1);
            map.put(4, -1);
            map.put(8, -1);


            boolean flag = true;
            boolean hasFiveOrZero = arr[0] % 5 == 0;

            for (int i = 0; i < arr.length; i++) {
                int n = arr[i];
                int startMod = n % 10;
                if (startMod == 5) {
                    if (!hasFiveOrZero) {
                        flag = false;
                        break;
                    }
                    if (i < arr.length - 1) {
                        if (!(arr[i] == arr[i + 1] || arr[i] + 5 == arr[i + 1])) {
                            flag = false;
                            break;
                        }
                    } else {
                        if (!(arr[i] == arr[i - 1] || arr[i] + 5 == arr[i - 1])) {
                            flag = false;
                            break;
                        }
                    }
                } else if (startMod == 0) {
                    if (!hasFiveOrZero) {
                        flag = false;
                        break;
                    }
                    if (i < arr.length - 1) {
                        if (!(arr[i] == arr[i + 1] || arr[i] == arr[i + 1] + 5)) {
                            flag = false;
                            break;
                        }
                    } else {
                        if (!(arr[i] == arr[i - 1] || arr[i] == arr[i - 1] + 5)) {
                            flag = false;
                            break;
                        }
                    }
                } else {
                    if (hasFiveOrZero) {
                        flag = false;
                        break;
                    }
                    if (i == 0) {
                        int mod = n;
                        while (!map.containsKey(mod % 10) || map.get(mod % 10) == -1) {
                            map.put(mod % 10, mod / 10 % 2);
                            mod = mod + mod % 10;
                        }
                    } else {
                        int mod = n;
                        while (!map.containsKey(mod % 10)) {
                            mod = mod + mod % 10;
                        }
                        int value = map.get(mod % 10);
                        if (value != mod / 10 % 2) {
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if (flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
