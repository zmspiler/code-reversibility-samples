import javax.tools.*;
import java.io.*;
import java.lang.reflect.*;
import java.net.*;
import java.util.*;

public class Level10 {
    public static void main(String[] args) throws Exception {
        // Java source code to be compiled at runtime
        String className = "DynamicHello";
        String sourceCode = """
            public class DynamicHello {
                public void sayHello() {
                    System.out.println("Hello from dynamically compiled code!");
                }
            }
            """;

        // Save source in .java file
        File sourceFile = new File(className + ".java");
        try (FileWriter writer = new FileWriter(sourceFile)) {
            writer.write(sourceCode);
        }

        // Compile source file
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        int compilationResult = compiler.run(null, null, null, sourceFile.getPath());
        if (compilationResult != 0) {
            System.out.println("Compilation failed.");
            return;
        }

        // Load and instantiate compiled class
        URLClassLoader classLoader = URLClassLoader.newInstance(new URL[] { new File("").toURI().toURL() });
        Class<?> dynamicClass = Class.forName(className, true, classLoader);
        Object instance = dynamicClass.getDeclaredConstructor().newInstance();

        // Invoke the sayHello method
        Method method = dynamicClass.getMethod("sayHello");
        method.invoke(instance);

        // Clean up by deleting the generated files
        sourceFile.delete();
        new File(className + ".class").delete();
    }
}
