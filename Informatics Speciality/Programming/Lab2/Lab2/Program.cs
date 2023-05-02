using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int choice = 0;
            Boolean inp = true;

            do
            {
                Console.WriteLine("Задание 1");
                Task_1 task1 = new Task_1();
                task1.Task1();
                Console.WriteLine("Задание 2");
                Task_2 task2 = new Task_2();
                task2.Task2();

                do
                {
                    try
                    {
                        inp = true;
                        Console.WriteLine("Завершить ли программу?");
                        Console.WriteLine("Да (1)");
                        Console.WriteLine("Нет (2)");
                        choice = int.Parse(Console.ReadLine());
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("Ошибка ввода. Введите повторно");
                    }
                }
                while (inp == false || choice > 2 || choice < 1);
            }
            while (choice == 2);

            Console.WriteLine("Программа завершила свою работу");
        }
    }
}
