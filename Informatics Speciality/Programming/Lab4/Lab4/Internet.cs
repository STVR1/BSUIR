using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    class Internet
    {

        // Fields

        private List<Rate> users;

        private string operatorName;

        private static Internet instance;

        // Constructor (with parameter)

        private Internet(string operatorName) 
        {
            this.operatorName = operatorName;
            users = new List<Rate>();
        }

        // Constructor (with no parameters)

        private Internet()
        {
            this.operatorName = "Unknown";
        }

        // Singletone (with parameter)

        public static Internet GetInstance(string operatorName)
        {
            if (instance == null) instance = new Internet(operatorName);
            return instance;
        }

        // Singletone (with no parameter)

        public static Internet GetInstance()
        {
            if (instance == null) instance = new Internet();
            return instance;
        }


        // Property (set/get) for the name of operator

        public string OperatorName
        {
            get { return operatorName; }
            set { operatorName = value; }
        }


        // Property (set/get) for the users

        public  List<Rate> Users
        {
            get { return users; }
            set { users.AddRange(value); }
        }

        // Method to get full income

        public double Income()
        {
            double sum=0;
            for (int i = 0; i < users.Count; i++) sum += users[i].Cost;
            return sum;
        }

        // Overload methods

        // Method to change rate

        public void ChangeRate(double oldcost, double newcost)
        {
            for (int i = 0; i < users.Count; i++)
                if (oldcost==users[i].Cost) users[i].Cost=newcost;
        }

        // Method to change rate

        public void ChangeRate(double value)
        {
            if (value <= 0)
            {
                for (int i = 0; i < users.Count; i++) users[i].Decrease(value);
            }
            else for (int i = 0; i < users.Count; i++) users[i].Increase(value);
        }

        // Destructor

        ~Internet()
        {
            users.Clear();
        }

    }

     class Rate
     {

        // Field

        private double cost;

        // Property (get/set)

        public double Cost
        {
            get { return cost; }
            set { cost = value; }
        }

        // Methods to change cost

        public void Increase(double value)
        {
            Cost += value;
        }

        public void Decrease(double value)
        {
            Cost -= value;
        }

        // Constructor

        public Rate(double cost)
        {
            this.cost = cost;
        }

        // Destructor

        ~Rate()
        {

        }

    }

}