using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    internal class Task_1
    {

        public void Task1()
        {
            Boolean inp = true;
            int a = 0,
                sum = 0,
                check = 0,
                choice = 0;

            do
            {
                try
                {
                    Console.WriteLine("Введите двузначное число");
                    a = int.Parse(Console.ReadLine());

                    if (a >= 10)
                    {
                        sum = 0;
                        while (a > 0)
                        {
                            sum = sum + a % 10;
                            a = a / 10;
                        }
                        check = sum % 2;

                        switch (check)
                        {
                            case 0:
                                {
                                    Console.WriteLine(sum + "\tНе является нечётной");
                                    break;
                                }
                            default:
                                {
                                    Console.WriteLine(sum + "\tЯвляется нечётной");
                                    break;
                                }
                        }
                    }
                    else Console.WriteLine("Ошибка ввода");
                }
                catch (Exception)
                {
                    Console.WriteLine("Ошибка ввода");
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
                        Console.WriteLine("Ошибка при вводе. Повторите ввод");
                        inp = false;
                    }
                }
                while (inp == false || choice > 2 || choice < 1);

            } while (choice == 1);
        }

    }
}
