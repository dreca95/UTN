using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public  class Cartuchera<T> where T: Utiles
    {
        protected int capacidad;
        protected List<T> elementos;
   public delegate void DelegadoPrecio(object sender, EventArgs e);
   public event DelegadoPrecio EventoPrecio;

        public List<T> Elementos { 
            
            
            get { return this.elementos; }
        
        
        }

        public double PrecioTotal
        {
            get
            {
                double total = 0;

                foreach (T item in this.Elementos)
                {
                    total += item.precio;
                }

                return total;
            }
        }

        public Cartuchera()
        {
            this.elementos = new List<T>();
        }

        public Cartuchera(int capacidad)
            : this()
        {
            this.capacidad = capacidad;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Tipo de cartuchera: {0} \r\n", typeof(T).Name);
            sb.AppendFormat("Capacidad de cartuchera: {0}\r\n", this.capacidad);
            sb.AppendFormat("Cantidad actual de elementos: {0}\r\n",this.Elementos.Count);
            sb.AppendFormat("Precio total: ${0}\r\n", this.PrecioTotal);
            sb.AppendLine("Listado de elementos:\n");
            foreach (T elemento in this.Elementos)
            {
                sb.AppendLine(elemento.ToString());
            }

            return sb.ToString();
        }

        public static Cartuchera<T> operator +(Cartuchera<T> c, T elemento)
        {
            if (c.capacidad > c.Elementos.Count)
            {
                c.Elementos.Add(elemento);

                if (c is Cartuchera<Goma>)
                {

                    if (c.PrecioTotal > 85)
                    {
                        c.EventoPrecio(c, new EventArgs());
                    }
                }
            }
            else
            {
                throw new CartucheraLlenaException();
            }

            return c;
        }
    }

}
