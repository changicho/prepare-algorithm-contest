import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class E {
    // 1 2 4 8 +1,6 +2,2 +2,4 +2,8 +3,6 +4,2
    // 3 +0,6 +1,2 +1,4 +1,8 +2,6 +3,2 +3,4 +3,8 +4,6
    // 5 +1,0 +1,0 +1,0
    // 7 +1,4 +1,8 +2,6 +3,2 +3,4 +3,8 +4,6
    // 9 +1,8, +2,6 +3,2 +3,4 +3,8 +4,6

    // 1,2,4,8 -> +1,6 // 이후 +20 마다 주기가 돌음
    // 3,6,7,9 -> +2,6 // 이후 +20 마다 주기가 돌음
    // 5 -> 자기 자신 또는 +5 밖에 만들 수 없음
    // 0 -> 자기 자신밖에 만들 수 없음

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCase = Integer.parseInt(br.readLine());

        int POSSIBLE_NUM1 = 1000_000_016;
        int POSSIBLE_NUM2 = 1000_000_026;

        for (int i = 0; i < testCase; i++) {
            int n = Integer.parseInt(br.readLine());

            boolean isPossible = true;
            Set<Integer> possibleNumberSet = new HashSet<>();

            StringTokenizer tokenizer = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int number = Integer.parseInt(tokenizer.nextToken());
                int possibleNumber = 0;
                switch (number % 10) {
                    case 1:
                    case 2:
                    case 4:
                    case 8:
                        possibleNumber = ((number / 10) * 10) + 16;
                        if ((POSSIBLE_NUM1 - possibleNumber) % 20 == 0) {
                            possibleNumberSet.add(POSSIBLE_NUM1);
                        } else {
                            possibleNumberSet.add(POSSIBLE_NUM2);
                        }
                        break;
                    case 3:
                    case 6:
                    case 7:
                    case 9:
                        possibleNumber = ((number / 10) * 10) + 26;
                        if ((POSSIBLE_NUM1 - possibleNumber) % 20 == 0) {
                            possibleNumberSet.add(POSSIBLE_NUM1);
                        } else {
                            possibleNumberSet.add(POSSIBLE_NUM2);
                        }
                        break;
                    case 5:
                        possibleNumberSet.add(number + 5);
                        break;
                    case 0:
                        possibleNumberSet.add(number);
                        break;
                }

                if (possibleNumberSet.size() > 1) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                bw.write("Yes\n");
            } else {
                bw.write("No\n");
            }
        }
        bw.flush();
    }
}
