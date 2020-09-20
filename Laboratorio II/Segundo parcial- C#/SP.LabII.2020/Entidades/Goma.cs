using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Goma :Utiles
    {

        public bool soloLapiz;

        public override bool PreciosCuidados {
            
            
            get { return true; } 
        
        
        }

        public Goma(bool soloLapiz, string marca, double precio)
            : base(marca, precio)
        {
            this.soloLapiz = soloLapiz;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat(base.UtilesToString());
            sb.AppendFormat("Solo Lápiz: {0}\r\n", this.soloLapiz);
            sb.AppendFormat("Precios cuidados: {0}\r\n", this.PreciosCuidados);

            return sb.ToString();
        }

    }
}
