import java.util.function.BiFunction;

public class Level7 {
    public static void main(String[] args) {
        BiFunction<Integer, Integer, Integer> add = (a, b) -> a + b;
        System.out.printf("Result: %d\n", add.apply(3, 4));
    }
}
