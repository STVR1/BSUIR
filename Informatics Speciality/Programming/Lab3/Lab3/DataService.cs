using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    internal class DataService
    {
        private int AmountDays(int day, int month, int year)
        {
            int inputdays = (year - 1) * 365 + (year - 1) / 4;
            for (int i = 1; i < month; i++)
            {
                if (i == 4 || i == 6 || i == 9 || i == 11) inputdays += 30;
                else if (i == 2)
                {
                    if (year % 4 == 0) inputdays += 29;
                    else inputdays += 28;
                }
                else inputdays += 31;
            }
           
            return inputdays += day;
        }

        public string GetDay(string date)
        {
            int day = Convert.ToInt32(date[0].ToString() + date[1].ToString());
            int month=Convert.ToInt32(date[3].ToString() + date[4].ToString());

            if (month == 4 || month == 7) month = 0;
            else if (month == 1 || month == 10) month = 1;
            else if (month == 5) month = 2;
            else if (month == 8) month = 3;
            else if (month == 2 || month == 3 || month == 11) month = 4;
            else if (month == 6) month = 5;
            else if (month == 12 || month == 9) month = 6;

            int year= Convert.ToInt32(date[6].ToString() + date[7].ToString());
            switch(year%4)
            {
                case 0:
                    {
                        year = 6;
                        break;
                    }
                case 1:
                    {
                        year = 4;
                        break;
                    }
                case 2: 
                    {
                        year = 2;
                        break;
                    }
                case 3:
                    {
                        year = 0;
                        break;
                    }
            }
            year = (year + Convert.ToInt32(date[8].ToString() + date[9].ToString()) + Convert.ToInt32(date[8].ToString() + date[9].ToString()) / 4) % 7;
          
            day = (day + month + year) % 7;
            switch(day)
            {
                case 0:
                    {
                        return "Суббота";
                    }
                case 1:
                    {
                        return "Воскресенье";
                    }
                case 2:
                    {
                        return "Понедельник";
                    }
                case 3:
                    {
                        return "Вторник";
                    }
                case 4:
                    {
                        return "Среда";
                    }
                case 5:
                    {
                        return "Четверг";
                    }
                case 6:
                    {
                        return "Пятница";
                    }
            }
            return "";
        }

        public int GetDaysSpan(int day, int month, int year)
        {
            int extraday = Convert.ToInt32(DateTime.Today.ToString()[0].ToString() + DateTime.Today.ToString()[1].ToString());
            int extramonth = Convert.ToInt32(DateTime.Today.ToString()[3].ToString() + DateTime.Today.ToString()[4].ToString());
            int extrayear = Convert.ToInt32(DateTime.Today.ToString()[6].ToString() + DateTime.Today.ToString()[7].ToString()+ DateTime.Today.ToString()[8].ToString() + DateTime.Today.ToString()[9].ToString());
            return Math.Abs(AmountDays(day, month, year) - AmountDays(extraday, extramonth, extrayear));
        }

    }
}
