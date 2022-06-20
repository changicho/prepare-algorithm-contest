
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            br.readLine();
            List<String> list = new ArrayList<>();
            for (int i = 0; i < 8; i++) {
                list.add(br.readLine());
            }

            int lCount = 0;
            int hCount = 0;

            String low = list.get(0);
            String high = list.get(list.size() - 1);

            for (int j = 0; j < 8; j++) {
                if (low.charAt(j) == '#') {
                    lCount ++;
                }

                if (high.charAt(j) == '#') {
                    hCount ++;
                }
            }

            if (lCount == 1 && hCount == 1) {
                int startIndex = 0;
                for (; startIndex < list.size(); startIndex++) {
                    int count = 0;
                    String s = list.get(startIndex);
                    for (int j = 0; j < s.length(); j++) {
                        if (s.charAt(j) == '#') {
                            count++;
                        }
                    }
                    if (count == 2) {
                        break;
                    }
                }

                for (; startIndex < list.size(); startIndex++) {
                    String s = list.get(startIndex);
                    int count = 0;
                    int colIndex = 0;
                    for (int j = 0; j < s.length(); j++) {
                        if (s.charAt(j) == '#') {
                            count++;
                            colIndex = j;
                        }
                    }
                    if (count == 1 && startIndex >= 1 && startIndex <= 6) {
                        System.out.println((startIndex + 1) + " " + (colIndex + 1));
                        break;
                    }
                }
            } else if (lCount == 1) {
                for (int i = list.size() - 1; i >= 0; i --) {
                    String s = list.get(i);
                    int count = 0;
                    int colIndex = 0;
                    for (int j = 0; j < s.length(); j++) {
                        if (s.charAt(j) == '#') {
                            count++;
                            colIndex = j;
                        }
                    }
                    if (count == 1 && i >= 1 && i <= 6) {
                        System.out.println((i + 1) + " " + (colIndex + 1));
                        break;
                    }

                }
            } else if (hCount == 1) {
                for (int i = 0; i < 8; i++) {
                    String s = list.get(i);
                    int count = 0;
                    int colIndex = 0;
                    for (int j = 0; j < s.length(); j++) {
                        if (s.charAt(j) == '#') {
                            count++;
                            colIndex = j;
                        }
                    }
                    if (count == 1 && i >= 1 && i <= 6) {
                        System.out.println((i + 1) + " " + (colIndex + 1));
                        break;
                    }
                }
            } else if (lCount == 2) {
                for (int i = 0; i < 8; i++) {
                    String s = list.get(i);
                    int count = 0;
                    int colIndex = 0;
                    for (int j = 0; j < s.length(); j++) {
                        if (s.charAt(j) == '#') {
                            count++;
                            colIndex = j;
                        }
                    }
                    if (count == 1 && i >= 1 && i <= 6) {
                        System.out.println((i + 1) + " " + (colIndex + 1));
                        break;
                    }
                }
            } else if (hCount == 2) {
                for (int i = list.size() - 1; i >= 0; i --) {
                    String s = list.get(i);
                    int count = 0;
                    int colIndex = 0;
                    for (int j = 0; j < s.length(); j++) {
                        if (s.charAt(j) == '#') {
                            count++;
                            colIndex = j;
                        }
                    }
                    if (count == 1 && i >= 1 && i <= 6) {
                        System.out.println((i + 1) + " " + (colIndex + 1));
                        break;
                    }

                }
            }
        }
    }
}
