using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/* Given a list of chars and corresponding probability, we want a random method so that the 
 * probability of producing a specific char is exactly same as in the probability list.
*/
namespace CCP_version_1._0
{
	class Program
	{
		static void Main(string[] args)
		{
			Random r = new Random();
			
			Dictionary<char, int> chars = new Dictionary<char, int>();
			// The values in the Dictionary need to be integers.
			// The values do not have to add up to 100 or any number.
			// The program will calculate the probability of each key to be outputted
			// eg. 10 will have 2x probability than 5
			chars.Add('a', 5);
			chars.Add('b', 10);
			chars.Add('c', 15);
			chars.Add('d', 20);
			chars.Add('e', 50);
			int[] ranges = new int[chars.Count+1];
			ranges[0] = 0;
			int i = 1;
			int total = 0;
			Dictionary<int, char> charsRanges = new Dictionary<int, char>();
			foreach (var pair in chars)
			{
				total = total + pair.Value;
				ranges[i] = total;
				i++;
				charsRanges.Add(total, pair.Key);
			}

			test(10000, chars, charsRanges, ranges, total, r);
			Console.WriteLine("\nPress any key to out a random char");
			Console.WriteLine("Or press q to quit:");
			while (true)
			{
				ConsoleKeyInfo input = Console.ReadKey(true);
				if (input.KeyChar == 'q' || input.KeyChar == 'Q')
				{
					return;
				}
				else
				{
					Console.WriteLine(random(charsRanges, ranges, total, r));
				}
			}
		}

		static void test(int repetition, Dictionary<char, int> chars, Dictionary<int, char> charsRanges, int[] ranges, int total, Random r)
		{
			Console.WriteLine("Test cases for Binary Search:");
			Console.WriteLine("Expect: a Result: " + charsRanges[BinarySearch(ranges, 0, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: a Result: " + charsRanges[BinarySearch(ranges, 5, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: a Result: " + charsRanges[BinarySearch(ranges, 10, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: b Result: " + charsRanges[BinarySearch(ranges, 15, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: c Result: " + charsRanges[BinarySearch(ranges, 25, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: d Result: " + charsRanges[BinarySearch(ranges, 35, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: e Result: " + charsRanges[BinarySearch(ranges, 50, 0, ranges.Length - 1)]);

			Console.WriteLine("\nProbability of each char under " + repetition + " iterations");
			// Make a new dictionary to count how many times the chars are selected
			Dictionary<char, int> selected = chars;
			foreach (var key in selected.Keys.ToList<char>())
			{
				selected[key] = 0;
			}

			// Run the random selection (repetition) times
			for (int j = 0; j < repetition; j++)
			{
				char temp = random(charsRanges, ranges, total, r);
				selected[temp] = selected[temp] + 1;
			}

			// Calculate and Print the probability of each char
			foreach (var pair in selected)
			{
				double probability = (double)pair.Value / repetition;
				Console.WriteLine(pair.Key + ": " + probability);
			}
		}
		
		// Get a random char from chars dictionary
		static char random(Dictionary<int, char> charsRanges, int[] ranges, int total, Random r)
		{
			int n = r.Next(total);
			char selected = charsRanges[BinarySearch(ranges, n, 0, ranges.Length - 1)];
			return selected;
		}

		// Binary Search (The return value has to be not 0 and round up to the upper bound within the ranges array)
		static int BinarySearch(int[] ranges, int target, int low, int high)
		{
			int mid = (high + low)/2;
			if (ranges[mid] > target)
			{
				if (low == mid)
					return ranges[high];
				return BinarySearch(ranges, target, low, mid);
			}
			else if (ranges[mid] < target)
			{
				if (low == mid)
					return ranges[high];
				return BinarySearch(ranges, target, mid, high);
			}
			else
			{
				if (ranges[mid] == 0)
					return ranges[mid + 1];
				return ranges[mid];
			}
		}
	}
}
