using System.Threading.Tasks;

await GreetAsync();

async Task GreetAsync()
{
    await Task.Delay(1000);
    Console.WriteLine("Hello after delay!");
}
