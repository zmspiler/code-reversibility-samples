Car car = new(1998, 235000, "Golf IV", "VW");

car.Beep();

Console.WriteLine(car.GetDescriptor());

car.RevertKilometers();

Console.WriteLine(car.GetDescriptor());

class Car
{
    public int Year { get; set; }
    public string Model { get; set; }
    public string Brand { get; set; }
    public int Kilometers { get; set; }

    public Car(int year, int kilometers, string model, string brand)
    {
        Year = year;
        Kilometers = kilometers;
        Model = model;
        Brand = brand;
    }

    public void Beep()
    {
        Console.WriteLine("Beep!");
    }

    public void RevertKilometers()
    {
        Kilometers -= 50000;
    }

    public string GetDescriptor()
    {
        return $"{Brand} {Model} - {Year} ({Kilometers}km)";
    }
}
