using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Sacapunta :Utiles
    {
        public bool deMetal;

        public override bool PreciosCuidados
        {

            get { return false; }

        }

        public Sacapunta(bool deMetal, double precio, string marca): base(marca,precio)
        {
            this.deMetal = deMetal;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat(base.UtilesToString());
            sb.AppendFormat("De metal: {0}\r\n", this.deMetal);
            sb.AppendFormat("Precios cuidados: {0}\r\n", this.PreciosCuidados);

            return sb.ToString();
        }


    }
}
