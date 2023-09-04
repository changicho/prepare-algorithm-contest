
import java.util.Arrays;

public class successful_pairs_of_spells_and_potions {
    public static void main(String[] args) {
        int[] s = {15, 8, 19};
        int[] p = {38, 36, 23};
        successfulPairs(s, p, 328);
    }

    public static int[] successfulPairs(int[] spells, int[] potions, long success) {
        int[] result = new int[spells.length];
        long[] arr = new long[potions.length];


        for (int i = 0; i < potions.length; i++) {
            long div = (success / potions[i]);
            long rest = (success % potions[i]);
            if (rest != 0) {
                arr[i] = div + 1;
            } else {
                arr[i] = div;
            }
        }

        Arrays.sort(arr);


        for (int i = 0; i < spells.length; i++) {
            int left = 0;
            int right = arr.length - 1;
            int mid = 0;
            if (spells[i] < arr[0]) {
                result[i] = 0;
            } else {
                while (left < right) {
                    mid = (left + right) / 2;
                    if (arr[mid] <= spells[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                if (arr[left] <= spells[i]) {
                    result[i] = left + 1;
                } else {
                    result[i] = left;
                }
            }
        }
        return result;
    }
}
