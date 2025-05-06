// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: F84A3593-F657-4391-B1E3-127C27525529
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\08-async-await\Leve8.dll

using System;
using System.Threading.Tasks;

#nullable enable
await GreetAsync();

static async Task GreetAsync()
{
    await Task.Delay(1000);
    Console.WriteLine("Hello after delay!");
}
