// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: C728FDD0-1DBB-49F4-873F-755A9BED3FDF
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\07-delegates-and-lambda\Level7.dll

using System;

#nullable disable
Console.WriteLine($"Result: {((Func<int, int, int>)((a, b) => a + b))(3, 4)}");
