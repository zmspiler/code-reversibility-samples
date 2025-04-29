using System;
using System.Reflection;
using System.Reflection.Emit;

// Define a dynamic assembly and module
AssemblyName asmName = new("DynamicAssembly");
AssemblyBuilder asmBuilder = AssemblyBuilder.DefineDynamicAssembly(asmName, AssemblyBuilderAccess.Run);
ModuleBuilder modBuilder = asmBuilder.DefineDynamicModule("MainModule");

// Define a new type and method
TypeBuilder typeBuilder = modBuilder.DefineType("DynamicType", TypeAttributes.Public);
MethodBuilder methodBuilder = typeBuilder.DefineMethod("SayHello",
    MethodAttributes.Public | MethodAttributes.Static,
    typeof(void), Type.EmptyTypes);

// Emit IL to print "Hello from dynamically generated code!"
ILGenerator il = methodBuilder.GetILGenerator();
il.Emit(OpCodes.Ldstr, "Hello from dynamically generated code!");
il.Emit(OpCodes.Call, typeof(Console).GetMethod("WriteLine", new[] { typeof(string) }));
il.Emit(OpCodes.Ret);

// Create the type and invoke the method
Type dynamicType = typeBuilder.CreateType();
MethodInfo sayHello = dynamicType.GetMethod("SayHello");
sayHello.Invoke(null, null);
