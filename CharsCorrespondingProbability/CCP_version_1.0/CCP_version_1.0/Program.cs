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
			Dictionary<char, int> chars = new Dictionary<char, int>();
			chars.Add('a', 10);
			chars.Add('b', 20);
			chars.Add('c', 30);
			chars.Add('d', 40);
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

			Console.WriteLine("Test cases for Binary Search:");
			Console.WriteLine("Expect: a Result: " + charsRanges[BinarySearch(ranges, 0, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: a Result: " + charsRanges[BinarySearch(ranges, 5, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: a Result: " + charsRanges[BinarySearch(ranges, 10, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: b Result: " + charsRanges[BinarySearch(ranges, 15, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: c Result: " + charsRanges[BinarySearch(ranges, 25, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: d Result: " + charsRanges[BinarySearch(ranges, 35, 0, ranges.Length - 1)]);
			Console.WriteLine("Expect: e Result: " + charsRanges[BinarySearch(ranges, 50, 0, ranges.Length - 1)]);

			Random r = new Random();
			for (int j = 0; j < 100; j++)
			{
				Console.WriteLine(random(charsRanges, ranges, total, r));
			}
		
			Console.ReadLine();			
		}
		
		static char random(Dictionary<int, char> charsRanges, int[] ranges, int total, Random r)
		{
			int n = r.Next(total);
			char selected = charsRanges[BinarySearch(ranges, n, 0, ranges.Length - 1)];

			return selected;
		}

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
