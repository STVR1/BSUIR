using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _221703_Veksha
{
    internal class Program
    {
        static void Main(string[] args)
        {

            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());
            int res1 = a / b;
            int res2 = b / a;
            Console.WriteLine(res1);
            Console.WriteLine(res2);

            Console.ReadKey();
        }
    }
}
