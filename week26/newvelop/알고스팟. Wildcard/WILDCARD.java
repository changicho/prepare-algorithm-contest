
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class WILDCARD {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tCase = Integer.parseInt(br.readLine());
		for (int t = 0; t < tCase; t++) {
			String pattern = br.readLine();
			int testCount = Integer.parseInt(br.readLine());
			List<String> list = new ArrayList<>();
			for (int index = 0; index < testCount; index++) {
				String s = br.readLine();
				int[][] arr = new int[101][101];
				if (cal(arr, pattern, s, 0, 0)) {
					list.add(s);
				}
			}
			Collections.sort(list);
			for (String temp : list) {
				System.out.println(temp);
			}
		}
	}

	public static boolean cal(int[][] arr, String w, String s, int wIndex, int sIndex) {
		if (arr[wIndex][sIndex] != 0) {
			return arr[wIndex][sIndex] == 1;
		}

		while (wIndex < w.length()
			&& sIndex < s.length()
			&& (w.charAt(wIndex) == '?' || w.charAt(wIndex) == s.charAt(sIndex))) {
			arr[wIndex][sIndex] = 1;
			sIndex++;
			wIndex++;
		}

		if (wIndex == w.length()) {
			return sIndex == s.length();
		}

		if (w.charAt(wIndex) == '*') {
			for (int i = sIndex; i <= s.length(); i++) {
				if (cal(arr, w, s, wIndex + 1, i)) {
					return true;
				}
			}
		}

		arr[wIndex][sIndex] = -1;

		return false;
	}
}
