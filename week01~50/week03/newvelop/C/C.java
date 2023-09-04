
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int total = Integer.parseInt(br.readLine());
        for (int t = 0; t < total; t++) {
            int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            String s = br.readLine();
            boolean canLeft = s.charAt(0) == '0';
            boolean canRight = s.charAt(s.length() - 1) == '0';
            int move = input[1];
            int result = 0;
            for (int i = s.length() - 1; i >= 1; i--) {
                if (s.charAt(i) == '1') {
                    if (i == s.length() - 1) {
                        result += 1;
                    } else {
                        if (canRight) {
                            if (i + move >= s.length() - 1) {
                                result += 1;
                                move -= (s.length() - 1 - i);
                                canRight = false;
                            } else {
                                if (canLeft) {
                                    if (i - move <= 0) {
                                        result += 10;
                                        move -= i;
                                        canLeft = false;
                                    } else {
                                        result += 11;
                                    }
                                } else {
                                    result += 11;
                                }
                            }
                        } else if (canLeft) {
                            if (i - move <= 0) {
                                result += 10;
                                move -= i;
                                canLeft = false;
                            } else {
                                result += 11;
                            }
                        } else {
                            result += 11;
                        }
                    }
                }
            }

            if (s.charAt(0) == '1') {
                if (s.length() == 1) {
                    result += 1;
                } else {
                    if (canRight) {
                        if (move >= s.length() - 1) {
                            result += 1;
                        } else {
                            result += 10;
                        }
                    } else {
                        result += 10;
                    }
                }
            }
            System.out.println(result);
        }
    }
}
