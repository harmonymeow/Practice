using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*
 * Given an unsorted integer list, find the closest number to a given target, 
 * where closest means smaller than target with smallest difference. What 
 * the best running time and why
*/
namespace UCTGT_version_1._0
{
	class Program
	{
		static void Main(string[] args)
		{
			List<int> givenList = new List<int>();
			givenList.Add(40);
			givenList.Add(80);
			givenList.Add(5);
			givenList.Add(20);
			givenList.Add(99);
			givenList.Add(65);
			givenList.Add(10);

			// Test Cases
			Console.WriteLine("Try: " + findClostest(givenList,0) + " Should be: -1");
			Console.WriteLine("Try: " + findClostest(givenList, 50) + " Should be: 40");
			Console.WriteLine("Try: " + findClostest(givenList, 39) + " Should be: 20");
			Console.WriteLine("Try: " + findClostest(givenList, 99) + " Should be: 99");

			Console.ReadLine();
		}

		// Linear Search, Runtime Complexity of O(n)
		static int findClostest(List<int> givenList, int target)
		{
			int closest = -1;
			int dif = target - closest;
			foreach (int compare in givenList)
			{
				// Assuming that closest means smaller than or equal to the target value
				if (target >= compare)
				{
					if (target - compare < dif)
					{
						closest = compare;
						dif = target - closest;
					}
				}
			}
			return closest;
		}
	}
}
