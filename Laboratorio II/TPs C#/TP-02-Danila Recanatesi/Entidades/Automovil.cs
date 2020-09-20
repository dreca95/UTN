using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;

namespace Entidades
{
   public class Automovil : Vehiculo
    {
        #region Enumerados
        public enum ETipo { 
            Monovolumen, 
            Sedan 
        }
        #endregion

        #region Atributos
        ETipo tipo;
        #endregion

        #region Constructores
        /// <summary>
        /// Por defecto, TIPO será Monovolumen. 
        ///  Inicializa atributos marca, chasis y color con los datos pasados por parámetro  
        /// </summary>
        /// <param name="marca"></param>
        /// <param name="chasis"></param>
        /// <param name="color"></param>
        public Automovil(EMarca marca, string chasis, ConsoleColor color)
            : base(chasis, marca, color)
        {
            this.tipo = ETipo.Monovolumen;
        }

        /// <summary>
        ///  Inicializa atributos marca, chasis y color con los datos pasados por parámetro  
        /// </summary>
        /// <param name="marca"></param>
        /// <param name="chasis"></param>
        /// <param name="color"></param>
        /// <param name="tipo"></param>
        public Automovil(EMarca marca, string chasis, ConsoleColor color, ETipo tipo)
         : this(marca, chasis, color)
        {
           this.tipo=tipo;
        }
#endregion

        #region Propiedades
        /// <summary>
        /// Los automoviles son medianos
        /// </summary>
        /// <returns> ETamanio </returns>
        protected override ETamanio Tamanio
        {
            get
            {
                return ETamanio.Mediano;
            }
        }

#endregion
        #region Métodos
        /// <summary>
        /// Publica todos los datos del automovil.
        /// </summary>
        /// <returns> string </returns>
        public override sealed string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("AUTOMOVIL");
            sb.AppendLine(base.Mostrar());
            sb.AppendFormat("TAMAÑO : {0} ", this.Tamanio);
            sb.AppendFormat("TIPO : {0}\r\n", this.tipo);
            sb.AppendLine("---------------------");

            return sb.ToString();
        }

        #endregion
    }
}
