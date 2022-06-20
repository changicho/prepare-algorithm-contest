import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            String[] arr = br.readLine().split(" ");
            int tenH = arr[0].charAt(0) - '0';
            int oneH = arr[0].charAt(1) - '0';
            int tenM = arr[0].charAt(3) - '0';
            int oneM = arr[0].charAt(4) - '0';


            int tempTenH = tenH;
            int tempOneH = oneH;
            int tempTenM = tenM;
            int tempOneM = oneM;

            int plus = Integer.parseInt(arr[1]);

            boolean flag = true;
            int count = 0;
            while (flag) {
                int temp = plus;
                int pTenH = temp / 600;
                temp = temp - (pTenH * 600);
                int pOneH = temp / 60;
                temp = temp - (pOneH * 60);
                int pTenM = temp / 10;
                temp = temp - (pTenM * 10);
                int pOneM = temp;

                int curMinute = (tempTenM * 10 + tempOneM + pTenM * 10 + pOneM);

                int rest = curMinute / 60;
                curMinute = curMinute % 60;
                tempTenM = curMinute / 10;
                tempOneM = curMinute - tempTenM * 10;

                int curHour = tempTenH * 10 + tempOneH;
                curHour = (curHour + pTenH * 10 + pOneH + rest) % 24;

                tempTenH = curHour / 10;
                tempOneH = curHour - (tempTenH * 10);

                if (tempTenH == tempOneM && tempOneH == tempTenM) {
                    count ++;
                }

                if (tempTenH == tenH && tempOneH == oneH && tempTenM == tenM && tempOneM == oneM) {
                    break;
                }
            }

            System.out.println(count);
        }
    }
}
