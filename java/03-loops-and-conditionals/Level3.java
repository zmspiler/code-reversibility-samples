public class Level3 {
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            System.out.printf("Count: %d\n", i);

            if (i > 3) {
                System.out.println("More than 3");
            } else if (i == 3) {
                System.out.println(3);
            } else {
                System.out.println("Less than 3");
            }
        }

        if (java.time.LocalTime.now().getHour() < 12) {
            System.out.println("Good morning!");
        } else {
            System.out.println("Good afternoon!");
        }
    }
}
