import java.util.*;

public class Level5 {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        System.out.printf("Sum is: %d\n", sum);
    }
}
