using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{

    // Enumeration

    public enum Access { Drive5=13, Drive20=18, Giga30=22, Giga100=25, UnlimitedXS=30 } 

    public class Rate
    {

        // Field

        private Access access;

        // Constructor

        public Rate(Access access)
        {
            this.access = access;   
        }

        // Property

        public  Access Access
        {
            get { return access; }
            set { access = value; }
        }

        // Destructor

        ~Rate() { }

    }

}