using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Moto: Vehiculo
    {

        #region Constructor
        /// <summary>
        /// Inicializa atributos marca, chasis y color con los datos pasados por parámetro.
        /// </summary>
        /// <param name="marca"></param>
        /// <param name="chasis"></param>
        /// <param name="color"></param>
        public Moto(EMarca marca, string chasis, ConsoleColor color) : base (chasis, marca,color)
        {
        }

        #endregion

        #region Propiedades
        /// <summary>
        /// Las motos son chicas
        /// </summary>
        /// <returns> ETamanio </returns>
        protected override ETamanio Tamanio
        {
            get
            {
                return ETamanio.Chico;
            }
        }
        #endregion

        #region Metodos

        /// <summary>
        /// Publica todos los datos de la moto.
        /// </summary>
        /// <returns> string </returns>
        public override sealed string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("MOTO");
            sb.AppendLine(base.Mostrar());
            sb.AppendFormat("TAMAÑO : {0}\r\n", this.Tamanio);
            sb.AppendLine("---------------------");

            return sb.ToString();
        }

        #endregion
    }

}
