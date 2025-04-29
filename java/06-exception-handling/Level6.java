public class Level6 {
    public static void main(String[] args) {
        try {
            int x = Integer.parseInt("NotANumber");
        } catch (NumberFormatException ex) {
            System.out.println("Format error: " + ex.getMessage());
        } finally {
            System.out.println("Parsing attempt finished.");
        }
    }
}
