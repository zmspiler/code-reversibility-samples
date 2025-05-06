// Decompiled with JetBrains decompiler
// Type: Program
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: 29B1F0EE-1AAF-40B6-9E7D-956298A0E007
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\04-classes-and-objects\Level4.dll

using System;

#nullable disable
Car car = new Car(1998, 235000, "Golf IV", "VW");
car.Beep();
Console.WriteLine(car.GetDescriptor());
car.RevertKilometers();
Console.WriteLine(car.GetDescriptor());

// Decompiled with JetBrains decompiler
// Type: Car
// Assembly: proj, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: 29B1F0EE-1AAF-40B6-9E7D-956298A0E007
// Assembly location: C:\Users\zmspiler\Documents\GitHub\code-reversibility-samples\c-sharp\04-classes-and-objects\Level4.dll

#nullable enable
internal class Car
{
    public int Year { get; set; }

    public string Model { get; set; }

    public string Brand { get; set; }

    public int Kilometers { get; set; }

    public Car(int year, int kilometers, string model, string brand)
    {
        this.Year = year;
        this.Kilometers = kilometers;
        this.Model = model;
        this.Brand = brand;
    }

    public void Beep() => Console.WriteLine("Beep!");

    public void RevertKilometers() => this.Kilometers -= 50000;

    public string GetDescriptor() => $"{this.Brand} {this.Model} - {this.Year} ({this.Kilometers}km)";
}
