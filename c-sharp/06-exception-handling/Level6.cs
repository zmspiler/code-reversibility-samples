try
{
    int x = int.Parse("NotANumber");
}
catch (FormatException ex)
{
    Console.WriteLine($"Format error: {ex.Message}");
}
finally
{
    Console.WriteLine("Parsing attempt finished.");
}
