using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab5
{
    public class Operator
    {

        // Fields

        private List<Client> clients;

        private string operatorName;

        private static Operator singleOperator;

        // Singletones

        public static Operator GetSingleOperator(string operatorName)
        {
            if (singleOperator == null) singleOperator = new Operator(operatorName);
            return singleOperator;
        }

        public static Operator GetSingleOperator()
        {
            if (singleOperator == null) singleOperator = new Operator();
            return singleOperator;
        }

        // Constructors

        private Operator(string operatorName)
        {
            this.operatorName = operatorName;
            clients = new List<Client>();
        }

        private Operator()
        {
            this.operatorName = "Unknown";
            clients = new List<Client>();
        }

        // Property

        public string OperatorName
        {
            get { return this.operatorName; }
            set { this.operatorName = value; }
        }

        // Methods to work with clients

        public bool Register(string name, Access access)
        {

            Client client = new Client(name, new Rate(access));
            clients.Sort((left, right) => left.Name.CompareTo(right.Name));
            int index = clients.FindIndex(r => r.Name.Equals(client.Name));

            if (index == -1)
            {
                clients.Add(client);
                clients.Sort((left, right) => left.Name.CompareTo(right.Name));
                return true;
            }
            return false;
        }

        public bool Delete(string name)
        {
            int index= clients.FindIndex(r => r.Name.Equals(name));
            if (index == -1) return false;
            else clients.Remove(clients[index]);
            return true;
        }

        public double AllTrafficAmount()
        {
            double amount = 0;

            for(int i=0;i<clients.Count;i++)
            {
                amount += Convert.ToDouble(clients[i].Amount);
            }

            return amount*0.01;
        }

        public Client MaxPaidMoney()
        {
            if (clients.Count == 0) return null;
            clients.Sort((left, right) => left.Amount.CompareTo(right.Amount));
            Client searched =clients[clients.Count - 1];
            return searched;
        }

        public bool SetTrafficAmount(string name, int amount)
        {
            int index = clients.FindIndex(r => r.Name.Equals(name));
            if (index != -1)
            {
                clients[index].Amount = amount;
                return true;
            }
            return false;
        }

        public int GetTrafficAmount(string name)
        {
            int index = clients.FindIndex(r=>r.Name.Equals(name));
            if (index != -1) return clients[index].Amount;
            return -1;
        }

        public bool SetPaidMoney(string name) 
        {

            int index = clients.FindIndex(r => r.Name.Equals(name));

            if (index == -1) return false;
            else clients[index].PaidMoney += Convert.ToDouble(clients[index].Rate.Access) - 0.1;
            
            return true;

        }

        public Client GetClient(string name)
        {
            if (clients.Count == 0) return null;
            int index = clients.FindIndex(r => r.Name.Equals(name));
            if (index == -1) return null;
            else return clients[index];
        }

        // Destructor

        ~Operator() { }

    }
}