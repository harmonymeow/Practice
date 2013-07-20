using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Diagnostics;
using System.Threading;

// Execution time 6:00 sec

namespace Part2
{
	class Program
	{
		static void Main(string[] args)
		{
			// Timer for testing
			Stopwatch stopWatch = new Stopwatch();
			stopWatch.Start();

			int curValue = 1;
			int curPosition = 1;
			int targetPosition = 1500;
			Dictionary<int, int> passedValues = new Dictionary<int, int>();

			passedValues.Add(1, 1);

			// loop until we hit our target position
			while (curPosition != targetPosition)
			{
				curValue++;
				if (testValue(curValue, passedValues))
				{
					curPosition++;
					passedValues.Add(curValue, curPosition);
					// Print values for testing
					Console.WriteLine(curPosition + ": " + curValue);
				}
			}
			// Print the value of the target position
			Console.WriteLine(curValue);
			
			// Timer for testing
			stopWatch.Stop();
			TimeSpan ts = stopWatch.Elapsed;
			string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
				ts.Hours, ts.Minutes, ts.Seconds,
				ts.Milliseconds / 10);
			Console.WriteLine("RunTime " + elapsedTime);

			Console.ReadLine();
		}

		// return true if the value is one of the series
		static bool testValue(int value, Dictionary<int, int> passedValues)
		{
			int[] modNum = { 2, 3, 5 };
			for (int i = 0; i < modNum.Length; i++)
			{
				// find perfectly divisible values of 2, 3, or 5
				if (value % modNum[i] == 0)
				{
					int dividedNum = value / modNum[i];
					// This only find 2, 3, and 5
					if (dividedNum == 1)
					{
						return true;
					}
					else
					{
						// If the divided number is in the hashtable, it is one of the series
						if (passedValues.ContainsKey(dividedNum))
						{
							return true;
						}
					}
				}
			}
			return false;
		}
	}
}
