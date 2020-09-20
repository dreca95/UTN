using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Numero
    {
       private double numero;

        #region Constructores
        public Numero() {

            this.numero = 0;
        }

        public Numero(double numero) {

            this.numero = numero;
        }

        public Numero(string strNumero) {

            this.SetNumero=strNumero;

        }

        #endregion

        #region Propiedad de solo escritura
        private String SetNumero {

            set { this.numero = ValidarNumero(value); }
        
        }
        #endregion

        #region Validación

        /// <summary>
        /// ValidarNumero Verificará que la cadena recibida sea un número.
        /// </summary>
        /// <param name="strNumero"></param>
        /// <returns>Retornará cadena en formato doble. Si la cadena recibida no es un número retorna 0</returns>
        private double ValidarNumero(string strNumero) {

            double numero;


            if (!(double.TryParse(strNumero, out numero)) ) {

                numero = 0;

            }


            return numero;
        }

        #endregion


        #region Conversores


        /// <summary>
        ///  BinarioDecimal convierte a decimal un número binario.
        /// </summary>
        /// <param name="strBinario">Numero que se quiere convertir</param>
        /// <returns>Numero decimal, o "Valor Invalido" en caso de que no pueda convertirse </returns>
        public string BinarioDecimal(string strBinario) {
            
            string retorno = "";
            int numero = 0;
            int aux = 0;

            for (int i = 1; i <= strBinario.Length; i++)
            {
                if (int.TryParse(strBinario[i - 1].ToString(), out aux) && (aux == 1 || aux == 0))
                {
                    numero += aux * (int)Math.Pow(2, strBinario.Length - i);
                    retorno = numero.ToString();
                }
                else
                {
                    retorno = "Valor inválido";
                }
            }
            return retorno;

        }


        /// <summary>
        ///  DecimalBinario convierte a binario un número decimal.
        /// </summary>
        /// <param name="numero">Numero que se quiere convertir</param>
        /// <returns>Numero Binario, o "Valor Invalido" en caso de que no pueda convertirse </returns>

        public string DecimalBinario(double numero)
        {
          
            string resultado = "";
            int numeroEntero = (int)numero;
            do
            {
                double resto = numeroEntero % 2;
                
               int aux = (resto % 2 == 0) ? 0 : 1;
               
                resultado = aux.ToString() + resultado.ToString();
                
                numeroEntero = (int)(numeroEntero / 2);
            
            } while (numeroEntero != 1 && numeroEntero != 0);
         
            resultado = numeroEntero.ToString() + resultado.ToString();
            return resultado;

        }


        /// <summary>
        ///  DecimalBinario convierte a binario un número decimal.
        /// </summary>
        /// <param name="strNumero">Numero que se quiere convertir</param>
        /// <returns>Numero Binario, o "Valor Invalido" en caso de que no pueda convertirse </returns>
        public string DecimalBinario(string strNumero)
        {


            string retorno = "Valor inválido";

            double aux;

            if (Double.TryParse(strNumero, out aux))
            {
                retorno = DecimalBinario(aux);

            }

            return retorno;

        }


        #endregion


        #region Operadores

        /// <summary>
        /// Método que sobrecarga operador - para poder operar con el objeto Número
        /// </summary>
        /// <param name="n1">Primer operador de tipo Numero.</param>
        /// <param name="n2"> Segundo operador de tipo Numero.</param>
        /// <returns>Resultado de la operación</returns>

        public static double operator -(Numero n1, Numero n2) {

            return n1.numero - n2.numero;

        }

        /// <summary>
        /// Método que sobrecarga operador * para poder operar con el objeto Número
        /// </summary>
        /// <param name="n1">Primer operador de tipo Numero.</param>
        /// <param name="n2"> Segundo operador de tipo Numero.</param>
        /// <returns>Resultado de la operación</returns>
        public static double operator *(Numero n1, Numero n2)
        {

            return n1.numero * n2.numero;

        }

        /// <summary>
        /// Método que sobrecarga operador / para poder operar con el objeto Número.
        /// </summary>
        /// <param name="n1">Primer operador de tipo Numero.</param>
        /// <param name="n2"> Segundo operador de tipo Numero.</param>
        /// <returns>Resultado de la operación. En caso de que el segundo operando sea cero,
        /// se retornará el double más pequeño</returns>
        public static double operator /(Numero n1, Numero n2)
        {
            double retorno;

            if (n2.numero != 0) {

                retorno = n1.numero / n2.numero;
            } else {

                retorno = double.MinValue;
            
            }

            return retorno;

        }


        /// <summary>
        /// Método que sobrecarga operador + para poder operar con el objeto Número
        /// </summary>
        /// <param name="n1">Primer operador de tipo Numero.</param>
        /// <param name="n2"> Segundo operador de tipo Numero.</param>
        /// <returns>Resultado de la operación</returns>
        public static double operator +(Numero n1, Numero n2)
        {

            return n1.numero + n2.numero;

        }

        #endregion
    }
}
