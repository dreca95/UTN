using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace MiCalculadora
{
    public partial class LaCalculadora : Form
    {
        public LaCalculadora()
        {
            InitializeComponent();


        }

        private void LaCalculadora_Load(object sender, EventArgs e)
        {

            this.cmbOperador.Items.Add("+");
            this.cmbOperador.Items.Add("-");
            this.cmbOperador.Items.Add("*");
            this.cmbOperador.Items.Add("/");
            this.cmbOperador.SelectedItem="+";
            
        }


        /// <summary>
        /// Llama al metodo Operar y muestra el resultado en lblResultado.
        /// </summary>
        private void btnOperar_Click(object sender, EventArgs e)
        {
            double resultado = Operar(this.txtNumero1.Text, 
                this.txtNumero2.Text, this.cmbOperador.Text);

            this.lblResultado.Text = resultado.ToString();


            double aux;

           txtNumero1.Text = (Double.TryParse(txtNumero1.Text, out aux)) ? txtNumero1.Text : "0";                
                txtNumero2.Text = (Double.TryParse(txtNumero2.Text, out aux)) ? txtNumero2.Text : "0";

            if (this.cmbOperador.Text != "+" && this.cmbOperador.Text != "-" &&
                this.cmbOperador.Text != "*" && this.cmbOperador.Text!= "/") {

               this.cmbOperador.Text = "+";
            
            }

            btnConvertirADecimal.Enabled = false;
            btnConvertirABinario.Enabled = true;

        }

        /// <summary>
        /// Llama al método limpiar
        /// </summary>
        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            this.Limpiar();
            
        }

        /// <summary>
        /// Cierra la calculadora
        /// </summary>
        private void btnCerrar_Click(object sender, EventArgs e)
        {
           
            this.Dispose();
        }


        /// <summary>
        /// Convierte el resultado decimal a numero binario.
        /// </summary>
        private void btnConvertirABinario_Click(object sender, EventArgs e)
        {
            Numero resultadoBin = new Numero(this.lblResultado.Text);
            this.lblResultado.Text = resultadoBin.DecimalBinario(this.lblResultado.Text);
            btnConvertirABinario.Enabled = false;
            btnConvertirADecimal.Enabled = true;
        }


        /// <summary>
        /// Convierte el resultado expresado en número binario a decimal .
        /// </summary>
        private void btnConvertirADecimal_Click(object sender, EventArgs e)
        {
            Numero resultadoDec = new Numero(this.lblResultado.Text);
            this.lblResultado.Text = resultadoDec.BinarioDecimal(this.lblResultado.Text);
            btnConvertirABinario.Enabled = true;
            btnConvertirADecimal.Enabled = false;
        }


        /// <summary>
        /// Borra los datos de los TextBox, ComboBox y Label de la pantalla.
        /// </summary>
        private void Limpiar() {

            lblResultado.Text = "";
            txtNumero1.Text = "";
            txtNumero2.Text = "";
            cmbOperador.Text = "";


        }


        /// <summary>
        /// Realiza la operación con los dos operadores y el operador
        /// </summary>
        /// <param name="numero1">Primer operando.</param>
        /// <param name="numero2">Segundo operando</param>
        /// <param name="operador">Operador</param>
        /// <returns>Resultado</returns>
        private static double Operar(string numero1, string numero2, string operador)
        {
            Numero num1 = new Numero(numero1);
            Numero num2 = new Numero(numero2);
            double retorno = Calculadora.Operar(num1, num2, operador);
            return retorno;
        }



    }




}
