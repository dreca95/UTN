
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Entidades
{
    public class Correo : IMostrar<List<Paquete>>
    {
        #region Atributos
        List<Thread> mockPaquetes;
        List<Paquete> paquetes;
        #endregion

        public Correo()
        {
            this.mockPaquetes = new List<Thread>();
            this.paquetes = new List<Paquete>();
        }

        public List<Paquete> Paquetes
        {
            set{this.paquetes = value;}
            get{return this.paquetes;}
            
        }

        public string MostrarDatos(IMostrar<List<Paquete>> elemento)
        {
            string sb = "";

            foreach (Paquete p in ((Correo)elemento).Paquetes)
            {
                sb+=string.Format("{0} para {1} ({2})\n\r", p.TrackingID, p.DireccionEntrega, p.Estado.ToString());
             
            }
            return sb;
        }

     

        public static Correo operator +(Correo c, Paquete p)
        {

           
                Thread hilo = new Thread(p.MockCicloDeVida);

                foreach (Paquete item in c.Paquetes)
                {
                    if (item == p)
                    {
                        throw new TrackingIdRepetidoException("El Tracking ID " + item.TrackingID + " ya figura en la lista de envíos");
                    }
                }

                c.Paquetes.Add(p);

                c.mockPaquetes.Add(hilo);

                hilo.Start();

                return c;


        }
        public void FinEntregas()
        {
            foreach (Thread item in this.mockPaquetes)
                if (item.IsAlive)
                {
                    item.Abort();
                }
        }

    }
}
