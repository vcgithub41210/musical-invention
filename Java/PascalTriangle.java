import java.io.*;
import java.util.HashMap;
import java.util.List;

class PascalTriangle {
    public static long pascalTriangle(int currentIndex, int rowIndex, HashMap<List<Integer>, Long> memo) {
        // Check base case
        if (currentIndex == rowIndex || currentIndex == 0)
            return 1;

        if (memo.containsKey(List.of(rowIndex, currentIndex)))
            return memo.get(List.of(rowIndex, currentIndex));
        // Actual recursive function call
        long value = pascalTriangle(currentIndex - 1, rowIndex - 1, memo) + pascalTriangle(currentIndex, rowIndex - 1, memo);
        memo.put(List.of(rowIndex, currentIndex), value);
        return value;
    }

    public static void main(String[] args) {
        int rowIndex = 64;
        long[] result = new long[rowIndex + 1];
        HashMap<List<Integer>, Long> memo = new HashMap<>();
        for (int i = 0; i <= rowIndex / 2; i++) {
            long element = pascalTriangle(i, rowIndex, memo);
            result[i] = element;
            result[rowIndex - i] = element;
        }
        for (int j = 0; j < rowIndex + 1; j++) {
            System.out.println(result[j]);
        }
    }
}
