using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Utiles { 
   public string marca;
    public double precio;

    public abstract bool PreciosCuidados {
            get; 
        }

    public Utiles(string marca, double precio)
    {
        this.marca = marca;
        this.precio = precio;
    }

    protected virtual string UtilesToString()
    {
        StringBuilder sb = new StringBuilder();

        sb.AppendFormat("Marca: {0}\r\n", this.marca);
        sb.AppendFormat("Precio: {0}\r\n",this.precio);

        return sb.ToString();
    }

    public override string ToString()
    {
        return this.UtilesToString();
    }
}
}
