// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: AB510250-BD83-4DF5-8FC6-1536C2A0E1B0
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\09-reflection\Leve9.dll

using System;

#nullable disable
Type type = Type.GetType("System.Text.StringBuilder");
if (!(type != (Type)null))
    return;
object instance = Activator.CreateInstance(type);
type.GetMethod("Append", new Type[1] { typeof(string) })?.Invoke(instance, new object[1]
{
  (object) "Reflection says hi!"
});
Console.WriteLine(type.GetMethod("ToString", Type.EmptyTypes)?.Invoke(instance, (object[])null) as string);
