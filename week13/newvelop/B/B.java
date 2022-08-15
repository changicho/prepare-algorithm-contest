

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File("b.txt")), StandardCharsets.UTF_8));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            int num = Integer.parseInt(br.readLine());
            char[][] arr = new char[num][num];
            for (int i = 0; i < num; i++) {
                arr[i] = br.readLine().toCharArray();
            }
            int min = Integer.MAX_VALUE;
            Map<Integer, Set<Integer>> map = new HashMap<>();
            int count = 0;
            for (int i = 0; i < num; i++) {
                int temp = 0;
                int x = 0;
                int y = 0;
                for (int j = 0; j < num; j++) {
                    if (arr[i][j] == 'O') {
                        temp = Integer.MAX_VALUE;
                        break;
                    }

                    if (arr[i][j] == '.') {
                        temp++;
                        if (temp == 1) {
                            x = i;
                            y = j;
                        }
                    }
                }
                if (temp < min) {
                    min = temp;
                    map = new HashMap<>();
                    map.put(x, new HashSet<>());
                    map.get(x).add(y);
                    count = 1;
                } else if (temp == min) {
                    count++;
                    if (min == 1) {
                        if (!map.containsKey(x)) {
                            map.put(x, new HashSet<>());
                        }
                        map.get(x).add(y);
                    }
                }
            }

            for (int i = 0; i < num; i++) {
                int temp = 0;
                int x = 0;
                int y = 0;
                for (int j = 0; j < num; j++) {
                    if (arr[j][i] == 'O') {
                        temp = Integer.MAX_VALUE;
                        break;
                    }

                    if (arr[j][i] == '.') {
                        temp++;
                        if (temp == 1) {
                            x = j;
                            y = i;
                        }
                    }
                }
                if (temp < min) {
                    min = temp;
                    map = new HashMap<>();
                    map.put(x, new HashSet<>());
                    map.get(x).add(y);
                    count = 1;
                } else if (temp == min) {
                    count ++;
                    if (min == 1) {
                        if (!map.containsKey(x)) {
                            map.put(x, new HashSet<>());
                        }
                        map.get(x).add(y);
                    }
                }
            }
            if (min == Integer.MAX_VALUE) {
                pw.println("Case #" + t + ": Impossible");
                System.out.println("Case #" + t + ": Impossible");
            } else {
                if (min == 1) {
                    pw.println("Case #" + t + ": " + min + " " + map.values().stream().mapToInt(Set::size).sum());
                    System.out.println("Case #" + t + ": " + min + " " + map.values().stream().mapToInt(Set::size).sum());
                } else {
                    pw.println("Case #" + t + ": " + min + " " + count);
                    System.out.println("Case #" + t + ": " + min + " " + count);
                }
            }
            pw.flush();
        }
    }
}
