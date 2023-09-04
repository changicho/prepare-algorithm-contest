
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PI {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tCase = Integer.parseInt(br.readLine());
		for (int t = 0; t < tCase; t++) {
			String s = br.readLine();
			int[] dp = new int[s.length() + 1];
			System.out.println(cal(0, s, dp));
		}
	}

	public static int cal(int index, String s, int[] dp) {
		if (index == s.length()) {
			return 0;
		}

		if (dp[index] != 0) {
			return dp[index];
		}

		int result = Integer.MAX_VALUE;
		for (int length = 3; length <= 5 && length + index - 1 < s.length(); length++) {
			int temp = cal(index + length, s, dp);
			if (temp < Integer.MAX_VALUE) {
				result = Math.min(result, temp + calMin(index, index + length, s, dp));
			}
		}

		dp[index] = result;

		return result;
	}

	public static int calMin(int startIndex, int endIndex, String s, int[] dp) {
		String sub = s.substring(startIndex, endIndex);
		boolean same = true;
		for (int i = 1; i < sub.length(); i++) {
			if (sub.charAt(i) != sub.charAt(0)) {
				same = false;
				break;
			}
		}

		if (same) {
			return 1;
		}

		boolean flag = true;
		int dif = 1;

		for (int i = 1; i < sub.length(); i++) {
			int source = sub.charAt(i - 1) - '0';
			int target = sub.charAt(i) - '0';
			if (source + dif != target) {
				flag = false;
				break;
			}
		}

		if (flag) {
			return 2;
		}

		flag = true;
		dif = -1;

		for (int i = 1; i < sub.length(); i++) {
			int source = sub.charAt(i - 1) - '0';
			int target = sub.charAt(i) - '0';
			if (source + dif != target) {
				flag = false;
				break;
			}
		}

		if (flag) {
			return 2;
		}

		flag = true;
		for (int i = 2; i < sub.length(); i++) {
			int source = sub.charAt(i - 2);
			int target = sub.charAt(i);
			if (source != target) {
				flag = false;
				break;
			}
		}

		if (flag) {
			 return 4;
		}

		flag = true;
		dif = sub.charAt(1) - sub.charAt(0);
		for (int i = 2; i < sub.length(); i++) {
			int temp = sub.charAt(i) - sub.charAt(i - 1);
			if (temp != dif) {
				flag = false;
				break;
			}
		}

		if (flag) {
			 return 5;
		}

		return 10;
	}
}
