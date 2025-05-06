// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: 8B0FAF3E-63E8-4B8F-9170-19A4DDE60C6A
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\05-collections-and-algorithms\Level5.dll

using System;
using System.Collections.Generic;

#nullable disable
List<int> intList = new List<int>();
intList.Add(1);
intList.Add(2);
intList.Add(3);
intList.Add(4);
intList.Add(5);
int num1 = 0;
foreach (int num2 in intList)
    num1 += num2;
Console.WriteLine($"Sum is: {num1}");
