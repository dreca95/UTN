using Entidades;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FrmPpal
{
    public partial class FrmPPal : Form
    {
        private Correo correo;
        public FrmPPal()
        {
            InitializeComponent();
            this.correo = new Correo();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
           

        }
        public void ActualizarEstados()
        {
            lstEstadoIngresado.Items.Clear();
            lstEstadoEnViaje.Items.Clear();
            lstEstadoEntregado.Items.Clear();

            foreach (Paquete item in correo.Paquetes)
            {

                switch (item.Estado)
                {
                    case Paquete.EEstado.Ingresado:
                        lstEstadoIngresado.Items.Add(item);
                        break;

                    case Paquete.EEstado.EnViaje:
                        lstEstadoEnViaje.Items.Add(item);
                        break;

                    default:
                        lstEstadoEntregado.Items.Add(item);
                        break;
                }
            }
        }

        private void paq_InformaEstado(object sender, EventArgs e)
        {
            if (this.InvokeRequired)
            {
                Paquete.DelegadoEstado d = new Paquete.DelegadoEstado(paq_InformaEstado);
                this.Invoke(d, new object[] { sender, e });
            }
            else
            {
               
                this.ActualizarEstados();
            }
        }

        private void paq_InformaError()
        {
            MessageBox.Show("No pudo guardarse la información en la base de datos", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }



        private void btnAgregar_Click(object sender, EventArgs e)
        {
            Paquete p = new Paquete(this.txtDireccion.Text, this.mtxtTrackingID.Text);
            p.InformaEstado += this.paq_InformaEstado;
           p.BD += this.paq_InformaError;

            try
            {
                this.correo += p;
            }
            catch (TrackingIdRepetidoException ex)
            {
                MessageBox.Show(ex.Message, "Paquete repetido", MessageBoxButtons.OK, MessageBoxIcon.Question);
            }
         
            finally
            {

                this.ActualizarEstados();

            }
        }

        private void MostrarInformacion<T>(IMostrar<T> elemento)
        {
          
           if (elemento != null)
            {

                this.rtbMostrar.Clear();
                this.rtbMostrar.Text = elemento.MostrarDatos(elemento);
               elemento.MostrarDatos(elemento).Guardar("salida");
            }
        }
        private void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion<List<Paquete>>((IMostrar<List<Paquete>>)correo);
        }

        private void mostrarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion<Paquete>((IMostrar<Paquete>)lstEstadoEntregado.SelectedItem);

        }


        private void FrmPpal_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.correo.FinEntregas();
        }

    
    }
}
