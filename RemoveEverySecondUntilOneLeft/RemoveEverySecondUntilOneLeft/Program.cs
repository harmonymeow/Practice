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
            int length = 20;
            for (int i = 1; i <= length; i++)
            {
                Console.WriteLine(i + " " + findRemaining(i));
            }
            Console.ReadKey();
        }

        static int findRemaining(int n)
        {
            double loged = (int)(Math.Log((double)n) / Math.Log(2.0));
            int powered = (int)Math.Pow(2.0, loged);
            return 1 + (n - powered) * 2;
        }
    }
}
