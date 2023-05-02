using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3.Services
{
    internal class Task2
    {

        private double Check()
        {

            double num=0;
            Boolean input;

            do
            {
                input = true;

                try
                {
                    num = double.Parse(Console.ReadLine());
                }
                catch (Exception)
                {
                    input = false;
                    Console.WriteLine();
                }
            }
            while (input==false);

            return num;

        }

        public double  Calculate()
        {

            double x, z, b;

            do
            {

                do
                {

                    Console.WriteLine("Введите число z");
                    z = Check();
                    Console.WriteLine("Введите число b");
                    b = Check();

                }
                while (z == 0 && b < 0);

                if (z <= 0) x = Math.Pow(z, b) + Math.Abs(b / 2);
                else x = Math.Sqrt(z);

            }
            while (x == 0 || x == Math.PI || x == Math.PI / 2);

            return 1 / Math.Cos(x) + Math.Log(Math.Tan(x / 2));
        }

    }
}