import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            StringTokenizer tokenizer = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(tokenizer.nextToken());
            int H = Integer.parseInt(tokenizer.nextToken());
            int M = Integer.parseInt(tokenizer.nextToken());

            Time nearestAlarmTime = Time.from(48,0);
            Time sleepTime = Time.from(H, M);
            for (int j = 0; j < n; j++) {
                tokenizer = new StringTokenizer(br.readLine());
                int hour = Integer.parseInt(tokenizer.nextToken());
                int minute = Integer.parseInt(tokenizer.nextToken());

                Time alarmTime = Time.from(hour, minute);
                if (alarmTime.isBeforeThan(sleepTime)) {
                    nearestAlarmTime = Time.getMinimumTime(nearestAlarmTime, alarmTime.plus(24, 0));
                } else {
                    nearestAlarmTime = Time.getMinimumTime(nearestAlarmTime, alarmTime);
                }
            }
            Time answer = nearestAlarmTime.minus(sleepTime);
            bw.write(answer + "\n");
        }
        bw.flush();
    }

    private static class Time {
        private static final int MINUTES_PER_HOUR = 60;
        private int timeInMinute;

        public Time(int timeInMinute) {
            this.timeInMinute = timeInMinute;
        }

        public static Time from(int hour, int minute) {
            return new Time(hour * MINUTES_PER_HOUR + minute);
        }

        public Time plus(int hour, int minute) {
            return new Time(this.getTimeInMinute() + hour * MINUTES_PER_HOUR + minute);
        }
        
        public Time minus(Time otherTime) {
            return new Time(this.getTimeInMinute() - otherTime.getTimeInMinute());
        }

        public static Time getMinimumTime(Time t1, Time t2) {
            return t1.isBeforeThan(t2) ? t1 : t2;
        }

        public int getTimeInMinute() {
            return timeInMinute;
        }

        public boolean isBeforeThan(Time otherTime) {
            return this.getTimeInMinute() < otherTime.getTimeInMinute();
        }
        
        public String toString() {
            int hour = this.getTimeInMinute() / MINUTES_PER_HOUR;
            int minute = this.getTimeInMinute() % MINUTES_PER_HOUR;
            return hour + " " + minute;
        }
    }
}
