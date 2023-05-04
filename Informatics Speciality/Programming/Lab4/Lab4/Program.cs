using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    class Program
    {

        private static string ChangeString(double[] rates)
        {
            string choices="";
            for (int i = 0; i < rates.Length; i++) choices += Convert.ToString(i+1)+". "+Convert.ToString(rates[i])+"\n";
            return choices;
        }

        static void Main(string[] args)
        {

            double[] rates = new double[5]{14.99, 15.99, 19.99, 29.99, 7.99 };
            
            double parameter2;

            int parameter1;

            bool end = false;

            string choices;

            Internet.GetInstance(Choices.GetInstance().ChoiceName());
            Console.WriteLine("\nОператор успешо добавлен\n");

            do
            {
                choices = ChangeString(rates);

                switch(Choices.GetInstance().ChoiceOperation())
                {
                    case 1:
                        {
                            Internet.GetInstance().Users.Add(new Rate(rates[Choices.GetInstance().ChoiceRate(choices)-1]));
                            Console.WriteLine("\nДобавление пользователя выполено успешно\n");
                            break;
                        }
                    case 2:
                        {
                            if (Internet.GetInstance().Users.Count!=0)
                            {
                                Console.WriteLine("\nПользователи\n");
                                for (int i = 0; i < Internet.GetInstance().Users.Count; i++) 
                                    Console.WriteLine(Convert.ToString(i+1)+". "+Internet.GetInstance().Users[i].Cost);
                            }
                            else Console.WriteLine("\nНет пользователей\n");
                            break;
                        }
                    case 3:
                        {
                            if (Internet.GetInstance().Users.Count!=0) 
                                Console.WriteLine("\nКоличество пользователей: " + Internet.GetInstance().Users.Count+"\n");
                            else Console.WriteLine("\nНет пользователей\n");
                            break;
                        }
                    case 4:
                        {
                            Console.WriteLine("\nСумма: "+Internet.GetInstance().Income()+"\n");
                            break;
                        }
                    case 5:
                        {

                            switch(Choices.GetInstance().ChoiceChangeRate())
                            {
                                case 1:
                                    {
                                        parameter1 = Choices.GetInstance().ChoiceRate(choices) - 1;
                                        parameter2 = Choices.GetInstance().ChoiceRateParameter();
                                        Internet.GetInstance().ChangeRate(rates[parameter1], parameter2);
                                        rates[parameter1] = parameter2;
                                        break;
                                    }
                                case 2:
                                    {
                                        parameter1 = Choices.GetInstance().ChoiceRate(choices)-1;
                                        parameter2 = Choices.GetInstance().ChoiceRateParameter();

                                        for (int i = 0; i < Internet.GetInstance().Users.Count; i++)
                                            if (Internet.GetInstance().Users[i].Cost == rates[parameter1])
                                                Internet.GetInstance().Users[i].Increase(parameter2);

                                        rates[parameter1] += parameter2;
                                        
                                        break;
                                    }
                                case 3:
                                    {
                                        parameter1 = Choices.GetInstance().ChoiceRate(choices) - 1;
                                        parameter2 = Choices.GetInstance().ChoiceRateParameter();

                                        for (int i = 0; i < Internet.GetInstance().Users.Count; i++)
                                            if (Internet.GetInstance().Users[i].Cost == rates[parameter1])
                                                Internet.GetInstance().Users[i].Decrease(parameter2);

                                        rates[parameter1] -= parameter2;

                                        break;
                                    }
                            }
                            
                            choices = ChangeString(rates);
                            Console.WriteLine("\nИзменения успешно внесены\n");
                            break;
                        }
                    case 6:
                        {
                            end = true;
                            break;
                        }
                }
            }
            while (end==false);
        }
    }
}