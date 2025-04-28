for (int i = 0; i < 5; i++)
{
    Console.WriteLine($"Count: {i}");

    if (i > 3)
    {
        Console.WriteLine("More than 3");
    }
    else if (i == 3)
    {
        Console.WriteLine(3);
    }
    else
    {
        Console.WriteLine("Less than 3");
    }
}

if (DateTime.Now.Hour < 12)
{
    Console.WriteLine("Good morning!");
}
else
{
    Console.WriteLine("Good afternoon!");
}