
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            String s = br.readLine();
            int count = Integer.parseInt(br.readLine());
            List<String> list = new ArrayList<>();
            for (int i = 0; i < count; i++) {
               list.add(br.readLine());
            }
            int next = 0;
            int result = 0;
            List<Integer[]> resultList = new ArrayList<>();
            boolean flag = true;
            while (next < s.length()) {
                int tempMax = 0;
                int tempIndex = 0;
                int tempStartIndex = 0;
                for (int i = 0; i < list.size(); i++) {
                    String temp = list.get(i);
                    int tempNext = next;
                    while (tempNext >= 0 && tempNext + temp.length() > next) {
                        int index = s.indexOf(temp, tempNext);
                        if (index == tempNext) {
                            if (index + temp.length() > tempMax) {
                                tempMax = index + temp.length();
                                tempIndex = i + 1;
                                tempStartIndex = index + 1;
                            }
                            break;
                        } else {
                            tempNext --;
                        }
                    }
                }
                if (tempMax == 0) {
                    System.out.println(-1);
                    flag = false;
                    break;
                } else {
                    next = tempMax;
                    result++;
                    Integer[] intArr = new Integer[2];
                    intArr[0] = tempIndex;
                    intArr[1] = tempStartIndex;
                    resultList.add(intArr);
                }
            }
            if (flag) {
                System.out.println(result);
                for (Integer[] tempArr : resultList) {
                    System.out.println(tempArr[0] + " " + tempArr[1]);
                }
            }
        }
    }
}
