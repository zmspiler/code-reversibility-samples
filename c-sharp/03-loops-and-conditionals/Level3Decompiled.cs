// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: AC925B65-17FA-4B97-AB4F-1DD5383F7D8A
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\03-loops-and-conditionals\Level3.dll

using System;

#nullable disable
for (int index = 0; index < 5; ++index)
{
    Console.WriteLine($"Count: {index}");
    if (index > 3)
        Console.WriteLine("More than 3");
    else if (index == 3)
        Console.WriteLine(3);
    else
        Console.WriteLine("Less than 3");
}
if (DateTime.Now.Hour < 12)
    Console.WriteLine("Good morning!");
else
    Console.WriteLine("Good afternoon!");
