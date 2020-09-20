using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Entidades
{
    public class Paquete : IMostrar<Paquete>
    {

        public delegate void DelegadoEstado(object sender, EventArgs e);
        public delegate void DelegadoBD();
        public enum EEstado
        {
            Ingresado,
            EnViaje,
            Entregado
        }


        string direccionEntrega;
        EEstado estado;
        string trackingID;
        public event DelegadoEstado InformaEstado;
        public event DelegadoBD BD;

        #region Constructores

        public Paquete(string direccionEntrega, string trakingID)
        {
            this.TrackingID = trakingID;
            this.DireccionEntrega = direccionEntrega;
        }
        #endregion
        public string DireccionEntrega
        {
            set { this.direccionEntrega = value; }
            get { return this.direccionEntrega; }
        }


        public string TrackingID
        {
            set { this.trackingID = value; }
            get { return this.trackingID; }
        }

        public EEstado Estado
        {
            set { this.estado = value; }
            get { return this.estado; }

        }


        public void MockCicloDeVida()
        {

            while (this.Estado != EEstado.Entregado)
            {


                Thread.Sleep(4000);
                this.Estado++;
                this.InformaEstado.Invoke(null, null);

            }


            if (!PaqueteDAO.Insertar(this))
            {

                this.BD();
            }

        }
        public override string ToString()
        {
            return this.MostrarDatos(this);
        }

        public string MostrarDatos(IMostrar<Paquete> elemento)
        {
            return string.Format("{0} para {1}\r\n", ((Paquete)elemento).TrackingID, ((Paquete)elemento).DireccionEntrega);
        }




        public static bool operator ==(Paquete p1, Paquete p2)
        {
            return (p1.TrackingID == p2.TrackingID);
        }
        public static bool operator !=(Paquete p1, Paquete p2)
        {
            return !(p1 == p2);
        }

    }
}
