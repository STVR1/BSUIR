using Lab3.Services;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Lab3
{
    internal class Program
    {

        private static int ChoiceFinishTask()
        {
            int choice=0;
            Boolean input;

            do
            {
                try
                {
                    input = true;
                    Console.WriteLine("Повторить задание (1)");
                    Console.WriteLine("Прекратить задание (2)");
                    choice = int.Parse(Console.ReadLine());
                }
                catch (Exception)
                {
                    input = false;
                    Console.WriteLine("Ошибка ввода");
                }
            }
            while (input == false || choice > 2 || choice < 1);
            return choice;
        }

        private static int ChoiceFinishProgram()
        {
            int choice = 0;
            Boolean input;

            do
            {
                try
                {
                    input = true;
                    Console.WriteLine("Повторить задания (1)");
                    Console.WriteLine("Прекратить работу программу (2)");
                    choice = int.Parse(Console.ReadLine());
                }
                catch (Exception)
                {
                    input = false;
                    Console.WriteLine("Ошибка ввода");
                }
            }
            while (input == false || choice > 2 || choice < 1);
            return choice;
        }
    
        private static bool CheckDate(string date)
        {
            if (date.Length == 10)
            {

                for(int i=0;i<10;i++)
                {
                    if (i != 2 && i != 5) if (!('0' <= date[i] && date[i] <= '9')) return false;
                }

                if (Convert.ToUInt32(date[3].ToString() + date[4].ToString()) > 12 || Convert.ToUInt32(date[3].ToString() + date[4].ToString())==0) return false;

                if (Convert.ToUInt32(date[0].ToString() + date[1].ToString()) > 31 || Convert.ToUInt32(date[0].ToString() + date[1].ToString()) == 0) return false;
                else
                {
                    switch(Convert.ToUInt32(date[0].ToString() + date[1].ToString()))
                    {
                        case 31:
                            {
                                switch(Convert.ToUInt32(date[3].ToString() + date[4].ToString()))
                                {
                                    case 1: return true;
                                    case 3:return true;
                                    case 5:return true;
                                    case 7: return true;
                                    case 8: return true;
                                    case 10:return true;
                                    case 12:return true;
                                    default:return false;
                                }
                            }
                        case 30:
                            {
                                switch (Convert.ToUInt32(date[3].ToString() + date[4].ToString()))
                                {
                                    case 4: return true;
                                    case 6: return true;
                                    case 9: return true;
                                    case 11: return true;
                                    default: return false;
                                }
                            }
                        case 29:
                            {
                                if (Convert.ToUInt32(date[3].ToString() + date[4].ToString()) == 2 && Convert.ToUInt32(date[6].ToString() + date[7].ToString() + date[8].ToString() + date[9].ToString()) % 4 == 0) return true;
                                else return false;
                            }
                        case 28:
                            {
                                if (Convert.ToUInt32(date[3].ToString() + date[4].ToString()) == 2) return true;
                                else return false;
                            }
                        default: return true;
                    }
                }
  
            }
            else return false;
        }

        static void Main(string[] args)
        {

            int num;
            string date;

            do
            {

                Console.WriteLine("Задание 1");

                do
                {
                    try
                    {
                        Console.WriteLine("Введите двузначное число");
                        num = int.Parse(Console.ReadLine());
                        if (num > 9 && num < 100)
                        {
                            Task1 task1 = new Task1();
                            num = task1.Replace(num);
                            Console.WriteLine("Результат: " + num);
                        }
                        else Console.WriteLine("Ошибка ввода");

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("Ошибка ввода");
                    }

                }
                while (ChoiceFinishTask() == 1);

                Console.WriteLine("Задание 2");

                do
                {
                    Task2 task2 = new Task2();

                    Console.WriteLine("Результат: " + task2.Calculate());
                }
                while (ChoiceFinishTask() == 1);

                Console.WriteLine("Задание 3");

                do
                {
                    DataService task3 = new DataService();
                    Console.WriteLine("Введите дату");
                    date = Console.ReadLine();

                    while (CheckDate(date) == false)
                    {
                        Console.WriteLine("Ошибка ввода. Введите дату повторно");
                        date = Console.ReadLine();
                    }

                    Console.WriteLine("День недели: " + task3.GetDay(date));
                    Console.WriteLine("Разница между датами: " + task3.GetDaysSpan(Convert.ToInt32(date[0].ToString() + date[1].ToString()), Convert.ToInt32(date[3].ToString() + date[4].ToString()), Convert.ToInt32(date[6].ToString() + date[7].ToString() + date[8].ToString() + date[9].ToString())));

                }
                while (ChoiceFinishTask() == 1);



            }
            while (ChoiceFinishProgram()==1);
        }
    }
}