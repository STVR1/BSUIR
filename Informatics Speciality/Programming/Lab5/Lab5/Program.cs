using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{

    internal class Program
    {

        static void Main(string[] args)
        {

            string user;

            Console.WriteLine("***Начало работы***\n\nВведите имя оператора\n");
            Operator.GetSingleOperator(Console.ReadLine());

            Console.WriteLine("\nПриветствуем нового оператора " +Operator.GetSingleOperator().OperatorName+"\n");

            do
            {
                switch(Choices.Variants().Operation())
                {
                    case 1:
                        {
                            Console.WriteLine("\nВведите новое имя\n");
                            Operator.GetSingleOperator().OperatorName = Console.ReadLine();
                            Console.WriteLine("\nИмя успешно изменено\n");

                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("\nВведите имя пользователя\n");
                            user= Console.ReadLine();
                            Console.WriteLine("\nВыберите тариф\n");

                            if (Operator.GetSingleOperator().Register(user, Choices.Variants().Rate()))
                                Console.WriteLine("\nПользователь успешно добавлен\n");
                            else Console.WriteLine("\nПользователь с таким именем уже существует\n");

                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("\n1. " + Convert.ToString(Access.Drive5) + " - " + Convert.ToString(Convert.ToDouble(Access.Drive5) - 0.1)+" $");
                            Console.WriteLine("2. " + Convert.ToString(Access.Drive20) + " - " + Convert.ToString(Convert.ToDouble(Access.Drive20) - 0.1)+" $");
                            Console.WriteLine("3. " + Convert.ToString(Access.Giga30) + " - " + Convert.ToString(Convert.ToDouble(Access.Giga30) - 0.1) + " $");
                            Console.WriteLine("4. " + Convert.ToString(Access.Giga100) + " - " + Convert.ToString(Convert.ToDouble(Access.Giga100) - 0.1) + " $");
                            Console.WriteLine("5. " + Convert.ToString(Access.UnlimitedXS) + " - " + Convert.ToString(Convert.ToDouble(Access.UnlimitedXS) - 0.1)+" $" + "\n");
                            
                            break;
                        }
                    case 4:
                        {
                            if (Operator.GetSingleOperator().MaxPaidMoney() == null)
                            {
                                Console.WriteLine("\nУ вас нет клиентов\n");
                                break;
                            }

                            Console.WriteLine("\nВведите имя пользователся\n");
                            user = Console.ReadLine();
                            Console.WriteLine("\nВведите значение\n");

                            if (Operator.GetSingleOperator().SetTrafficAmount(user, Choices.Variants().InputAmount()))
                                Console.WriteLine("\nИзменения успешно внесены\n");
                            else Console.WriteLine("\nПользователь с таким именем не найден\n");

                            break;
                        }
                    case 5:
                        {
                            Console.WriteLine("\n"+Convert.ToString(Operator.GetSingleOperator().AllTrafficAmount())+" $\n");

                            break;
                        }
                    case 6:
                        {
                            if (Operator.GetSingleOperator().MaxPaidMoney() == null) Console.WriteLine("\nУ вас нет клиентов\n");
                            else Console.WriteLine("\n"+Convert.ToString(Operator.GetSingleOperator().MaxPaidMoney().Name)+": "+Convert.ToString(Operator.GetSingleOperator().MaxPaidMoney().PaidMoney)+" $\n");
                            
                            break;
                        }
                    case 7:
                        {
                            Console.WriteLine("\nВведите имя\n");
                            user = Console.ReadLine();

                            if (Operator.GetSingleOperator().SetPaidMoney(user)) Console.WriteLine("\nОплата успешно добавлена\n");
                            else Console.WriteLine("\nТакого пользователя нет\n");

                            break;
                        }
                    case 8:
                        {
                            Console.WriteLine("\nВведите имя\n");
                            user = Console.ReadLine();
                            Client client = Operator.GetSingleOperator().GetClient(user);

                            if (client == null) Console.WriteLine("\nТакого пользователя нет\n");
                            else
                            {
                                Console.WriteLine("\nName: "+client.Name);
                                Console.WriteLine("Traffic: "+client.Amount +" MB");
                                Console.WriteLine("All cost: "+client.PaidMoney+" $");
                                Console.WriteLine("Rate: "+Convert.ToString(client.Rate.Access)+" - "+ Convert.ToString(Convert.ToDouble(client.Rate.Access) - 0.1) + " $\n");
                            }
                            break;
                        }
                    case 9:
                        {
                            Console.WriteLine("\nВведите имя\n");
                            user = Console.ReadLine();

                            if (Operator.GetSingleOperator().Delete(user)) Console.WriteLine("\nКлиент успешно удалён\n");
                            else Console.WriteLine("\nТакой пользователь не найден\n");

                            break;
                        }
                }
            } while (Choices.Variants().End()==false);

        }

        // Class to make choices and other controlling work for users

        class Choices
        {

            private static Choices variants;

            public static Choices Variants()
            {
                if (variants == null) variants = new Choices();
                return variants;
            }

            public int Operation()
            {
                int choice;
                Boolean input;
                Console.Write("\nОператор - "+Operator.GetSingleOperator().OperatorName+"\n");
                Console.Write("\n1. Изменить имя оператора\n2. Зарегестрировать пользователя\n3. Вывести доступные тарифы\n");
                Console.Write("4. Изменить потреблённый трафик клиента\n5. Общая стоимость реализованного трафика\n6. Клиент, который больше всех заплатил\n");
                Console.WriteLine("7. Добавить оплату пользователю\n8. Информация о пользователе\n9. Удалить клиента\n");

                do
                {
                    input = true;
                    if (int.TryParse(Console.ReadLine(), out choice) && choice<10 && choice>0)
                    {
                        return choice;
                    }
                    else
                    {
                        Console.WriteLine("\nОшибка ввода. Введите повторно\n");
                        input = false;
                    }
                }
                while (input == false);

                return -1;
            }

            public Access Rate()
            {
                Boolean input = false;
                int choice;

                Console.WriteLine("\n1. "+Convert.ToString(Access.Drive5)+" - "+Convert.ToString(Convert.ToDouble(Access.Drive5)-0.1)+" $");
                Console.WriteLine("2. "+Convert.ToString(Access.Drive20)+" - "+Convert.ToString(Convert.ToDouble(Access.Drive20)-0.1)+ " $");
                Console.WriteLine("3. "+Convert.ToString(Access.Giga30)+" - "+Convert.ToString(Convert.ToDouble(Access.Giga30)-0.1)+ "$");
                Console.WriteLine("4. " + Convert.ToString(Access.Giga100) + " - " + Convert.ToString(Convert.ToDouble(Access.Giga100) - 0.1) + " $");
                Console.WriteLine("5. "+Convert.ToString(Access.UnlimitedXS)+" - " + Convert.ToString(Convert.ToDouble(Access.UnlimitedXS)-0.1)+" $\n");

                do
                {
                    input = true;
                    if (int.TryParse(Console.ReadLine(), out choice) && choice<6 && choice>0) break;
                    else
                    {
                        Console.WriteLine("\nОшибка ввода. Введите повторно\n");
                        input = false;
                    }
                }
                while (input == false);

                switch (choice)
                {
                    case 1: { return Access.Drive5; }
                    case 2: { return Access.Drive20; }
                    case 3: { return Access.Giga30; }
                    case 4: { return Access.Giga100; }
                    case 5: { return Access.UnlimitedXS; }
                    default: { return Access.Drive5; }
                }
            }

            public bool End()
            {
                int choice;
                Boolean input;

                Console.WriteLine("\n1. Продолжить работу\n2. Завершить работу\n");
                do
                {
                    input = true;
                    if (int.TryParse(Console.ReadLine(), out choice) && choice>0 && choice<3) break;
                    else
                    {
                        Console.WriteLine("\nОшибка ввода. Введите повторно\n");
                        input = false;
                    }
                }
                while (input == false);

                if (choice == 1) return false;
                return true;
            }

            public int InputAmount()
            {
                Boolean input;
                int amount;

                do
                {
                    input = true;
                    if(int.TryParse(Console.ReadLine(), out amount))
                    {
                        return amount;
                    }
                    else
                    {
                        Console.WriteLine("\nОшибка ввода. Введите повторно\n");
                        input = false;
                    }
                }
                while (input==false);
                return -1;
            }

        }

    }
}