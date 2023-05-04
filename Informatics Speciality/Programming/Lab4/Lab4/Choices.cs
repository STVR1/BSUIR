using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    class Choices
    {

        private static Choices instance;

        public static Choices GetInstance()
        {
            if (instance == null) instance = new Choices();
            return instance;
        }

        public int ChoiceOperation()
        {
            bool input = true;
            int choice = 0;
            do
            {
                try
                {
                    if(input==false) Console.WriteLine("\nОшибка ввода\n");

                    Console.WriteLine("\n1. Добавить пользователя");
                    Console.WriteLine("2. Получить информацию о всех пользователях");
                    Console.WriteLine("3. Количество пользователей");
                    Console.WriteLine("4. Общая выручка");
                    Console.WriteLine("5. Изменить тариф");
                    Console.WriteLine("6. Завершить работу\n");

                    input = true;

                    choice = int.Parse(Console.ReadLine());

                    if (choice < 1 || choice > 6) input=false;
                }
                catch (Exception)
                {
                    input = false;
                }
                
            } while (input == false);

            return choice;
        }

        public int ChoiceRate(string choices)
        {
            int choice = 0;
            bool input = true;
            do
            {
                try
                {
                    if(input==false) Console.WriteLine("\nОшибка ввода\n");

                    input = true;

                    Console.WriteLine("\nВыберите тариф\n"+choices);
                    choice = int.Parse(Console.ReadLine());

                    if (choice < 1 || choice > 5) input = false;
                }
                catch (Exception)
                {
                    input = false;
                }
            }
            while (input == false);

            return choice;
        }

        public int ChoiceChangeRate()
        {
            int choice = 0;
            bool input=true;
            do
            {
                try
                {
                    if(input==true)Console.WriteLine("\n1. Задать новую цену\n2. Увеличить\n3. Уменьшить\n");
                    else Console.WriteLine("\nОшибка ввода\n");

                    input = true;

                    choice = int.Parse(Console.ReadLine());

                    if (choice > 3 || choice < 1) input = false;
                }
                catch (Exception)
                {
                    input = false;
                }
            }
            while (input == false);

            return choice;
        }

        public string ChoiceName()
        {
            string name;
            bool check = true;

            do
            {

                if (check == true) Console.WriteLine("Введите название интернет-оператора\n");
                else Console.WriteLine("\nОшибка ввода. Введите название повторно\n");
                check = true;
                name = Console.ReadLine();
                if (name.Length == 0) check = false;
                for (int i = 0; i < name.Length; i++)
                    if (name[i] == ' ')
                    {
                        check = false;
                        break;
                    }
            }
            while (check == false);

            return name;
        }

        public double ChoiceRateParameter()
        {
            double choice = 0;
            bool input;
            do
            {
                try
                {
                    input = true;
                    Console.WriteLine("\nВведите значение\n");
                    choice = double.Parse(Console.ReadLine());
                }
                catch (Exception)
                {
                    input = false;
                    Console.WriteLine("\nОшибка ввода\n");
                }
            }
            while (input == false);

            return choice;
        }

    }
}