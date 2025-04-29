using System;
using System.Reflection;

string className = "System.Text.StringBuilder";
Type? type = Type.GetType(className);

if (type != null)
{
    object? instance = Activator.CreateInstance(type);
    MethodInfo? appendMethod = type.GetMethod("Append", new[] { typeof(string) });
    appendMethod?.Invoke(instance, new object[] { "Reflection says hi!" });

    MethodInfo? toStringMethod = type.GetMethod("ToString", Type.EmptyTypes);
    string? result = toStringMethod?.Invoke(instance, null) as string;
    Console.WriteLine(result);
}
