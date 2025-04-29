public class Level9 {
    public static void main(String[] args) throws Exception {
        String className = "java.lang.StringBuilder";
        Class<?> cls = Class.forName(className);
        Object obj = cls.getDeclaredConstructor().newInstance();

        cls.getMethod("append", String.class).invoke(obj, "Reflection says hi!");
        String result = (String) cls.getMethod("toString").invoke(obj);
        System.out.println(result);
    }
}
