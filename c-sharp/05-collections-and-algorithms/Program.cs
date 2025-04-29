using System.Collections.Generic;

var numbers = new List<int> { 1, 2, 3, 4, 5 };
int sum = 0;

foreach (int number in numbers)
{
    sum += number;
}

Console.WriteLine($"Sum is: {sum}");
