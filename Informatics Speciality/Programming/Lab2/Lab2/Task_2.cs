using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    internal class Task_2
    {

        public void Task2()
        {

            Boolean inp = true;

            int choice = 0, inCircle = 2;

            double x = 0, y = 0, r = 25;

            do
            {

                inCircle = 2;

                try
                {
                    Console.WriteLine("Введите координату x");
                    x = double.Parse(Console.ReadLine());

                    Console.WriteLine("Введите координату y");
                    y = double.Parse(Console.ReadLine());

                    while (x * x + y * y <= r * r && y <= 0 && -25 <= y && (x / y <= 1 || x / y >= -1))
                    {
                        inCircle = 1;

                        while (x == y || x == -y || x * x + y * y == r * r)
                        {
                            inCircle = 3;
                            break;
                        }
                        break;
                    }

                    switch (inCircle)
                    {
                        case 1:
                            {
                                Console.WriteLine("Да");
                                break;
                            }
                        case 2:
                            {
                                Console.WriteLine("Нет");
                                break;
                            }
                        case 3:
                            {
                                Console.WriteLine("На границе");
                                break;
                            }
                    }
                }
                catch (Exception)
                {
                    Console.WriteLine("Ошибка ввода. Введите повторно");
                }

                do
                {
                    try
                    {
                        inp = true;
                        Console.WriteLine("Повторить задание (1)");
                        Console.WriteLine("Прекратить задание (2)");
                        choice = int.Parse(Console.ReadLine());

                    }
                    catch (Exception)
                    {
                        inp = false;
                        Console.WriteLine("Ошибка ввода. Введите повторно");
                    }
                }
                while (inp == false || choice > 2 || choice < 1);

            } while (choice == 1);

        }

    }
}
