// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: EC150FFF-CE2B-4AF5-A3FF-59854D89788E
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\06-exception-handling\Level6.dll

using System;

#nullable disable
try
{
    int.Parse("NotANumber");
}
catch (FormatException ex)
{
    Console.WriteLine("Format error: " + ex.Message);
}
finally
{
    Console.WriteLine("Parsing attempt finished.");
}
