public class Level8 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(1000);
                System.out.println("Hello after delay!");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        t.start();
        t.join();
    }
}
