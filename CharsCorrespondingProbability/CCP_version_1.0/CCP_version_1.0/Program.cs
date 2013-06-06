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
			Dictionary<char, int> charsRanges = new Dictionary<char, int>();
			foreach (var pair in chars)
			{
				total = total + pair.Value;
				ranges[i] = total;
				i++;
				charsRanges.Add(pair.Key, total);
			}


			Console.ReadLine();			
		}
		
		static char random(Dictionary<char, int> charsRanges, int[] ranges, int total)
		{
			Random r = new Random();
			int n = r.Next(total);
			return 'a';
		}

		static int BinarySearch(int[] ranges, int target)
		{
			
			return 0;
		}

	}
}
