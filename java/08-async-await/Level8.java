import java.util.Random;

class ThreadRunnable implements Runnable {
    private final int index;
    public ThreadRunnable(final int index) {
        this.index = index;
    }
    @Override
    public void run() {
        final int sleep_time = new Random().nextInt(Level8.NUM_THREADS);
        System.out.printf("Thread %d: Started.\n", index);
        System.out.printf("Thread %d: Will be sleeping for %d seconds.\n", index, sleep_time);
        try {
        Thread.sleep(sleep_time*1000);
        } catch (Exception e) {}
        System.out.printf("Thread %d: Ended.\n", index);
    }
    
    
}
public class Level8 {
    static final int NUM_THREADS = 5;
    public static void main(String[] args) throws InterruptedException {
        Thread[] threads = new Thread[NUM_THREADS];
        for (int i = 0; i<NUM_THREADS; i++) {
            threads[i] = new Thread(new ThreadRunnable(i));
            threads[i].start();
        }
        System.out.println("In main: All threads are created.");
        for (Thread thread : threads) {
            thread.join();
        }
    }
}
