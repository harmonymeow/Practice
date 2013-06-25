using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RemoveEverySecondUntilOneLeft
{
    class Program
    {
        static void Main(string[] args)
        {
            int length = 50;
            for (int i = 1; i <= length; i++)
            {
                Console.WriteLine(i + " " + findRemaining1(i));
            }
            Console.ReadKey();
        }

        static int findRemaining1(int n)
        {
            double loged = (int)(Math.Log((double)n) / Math.Log(2.0));
            int powered = (int)Math.Pow(2.0, loged);
            return 1 + (n - powered) * 2;
        }

        static int findRemaining2(int n)
        {
            //Set leftmost 1 in binary number to 0
            //multiply the result by 2 and add 1
            return 1;
        }
    }
}
