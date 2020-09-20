using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public static class Calculadora
    {

        /// <summary>
        /// Realiza las operaciones aritmeticas.
        /// </summary>
        /// <param name="num1">Primer operando.</param>
        /// <param name="num2">Segundo operando</param>
        /// <param name="operador">Operador</param>
        /// <returns>Resultado de la operacion</returns>
        public static double Operar(Numero num1, Numero num2, string operador) {

            string aux;
            aux= Calculadora.ValidarOperador(operador);
            double resultado=0;

            switch (aux) {

                case "+":
                    resultado = num1 + num2;
                    break;

                case "-":
                    resultado = num1 - num2;
                    break;

                case "*":
                    resultado = num1 * num2;
                    break;

                case "/":
                    resultado = num1 / num2;
                    break;
            }

            return resultado;

        }



        /// <summary>
        /// Valida que el operador recibido sea +, -, / o *. Caso contrario retornará +
        /// </summary>
        /// <param name="operador">Operador a validar</param>
        /// <returns>Operador que se utilizará</returns>
        private static string ValidarOperador(string operador)
        {
            string retorno;

            if (operador == "-" || operador == "/" || operador == "*")
            {
                retorno= operador;

            }
            else
            {
                retorno = "+";

            }


            return retorno;
        }

    }
}
