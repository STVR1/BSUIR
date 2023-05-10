using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
     public class Client
     {

        // Fields

        private Rate rate;

        private int amount;

        private double paidMoney;

        private string name;
        
        // Constructor

        public Client(string name, Rate rate)
        {
            this.name = name;
            this.rate = rate;
            this.paidMoney = Convert.ToInt32(rate.Access) - 0.1;
            this.amount = 0;
        }

        // Properties

        public string Name 
        {
            get { return name; }
            set { name = value; }
        }

        public int Amount
        {
            get { return amount; }
            set { amount = value; }
        }

        public Rate Rate { get { return rate; } }

        // Method

        public double PaidMoney
        { get { return paidMoney; } 
          set { paidMoney = value; } 
        }

        // Destructor

        ~Client(){ }

    }
}