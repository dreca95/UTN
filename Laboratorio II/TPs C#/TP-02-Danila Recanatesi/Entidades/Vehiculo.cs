using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    /// <summary>
    /// La clase Vehiculo no deberá permitir que se instancien elementos de este tipo.
    /// </summary>

        #region Enumerados
    public abstract class Vehiculo
    {
        public enum EMarca
        {
            Chevrolet,
            Ford,
            Renault, 
            Toyota,
            BMW,
            Honda
        }
       public enum ETamanio
        {
            Chico, 
            Mediano,
            Grande
        }

        #endregion

        #region Atributos

        EMarca marca;
        string chasis;
        ConsoleColor color;

        #endregion

        #region Constructores

        /// <summary>
        /// Inicializa atributos chasis, marca y color con los datos pasados por parámetro.
        /// </summary>
        /// <param name="chasis"></param>
        /// <param name="marca"></param>
        /// <param name="color"></param>
        public Vehiculo(string chasis, EMarca marca, ConsoleColor color) {

            this.chasis = chasis;
            this.marca = marca;
            this.color = color;
        
        }
        #endregion

        #region Propiedades
        /// <summary>
        /// ReadOnly: Retornará el tamaño
        /// </summary>
        /// <returns> ETamanio </returns>
        protected abstract ETamanio Tamanio
        {

            get;

        }

        #endregion

        #region Metodos
        /// <summary>
        /// Publica todos los datos del Vehiculo.
        /// </summary>
        /// <returns> string </returns>
        public virtual string Mostrar()
        {
            return (string)this;
        }

        #endregion

        # region Sobrecargas

        /// <summary>
        /// Dos vehiculos son iguales si comparten el mismo chasis
        /// </summary>
        /// <param name="v1"></param>
        /// <param name="v2"></param>
        /// <returns> bool </returns>
        public static bool operator ==(Vehiculo v1, Vehiculo v2)
        {
            
            return v1.chasis == v2.chasis;
        }
        /// <summary>
        /// Dos vehiculos son distintos si su chasis es distinto
        /// </summary>
        /// <param name="v1"></param>
        /// <param name="v2"></param>
        /// <returns>bool</returns>
        public static bool operator !=(Vehiculo v1, Vehiculo v2)
        {
            return !(v1.chasis == v2.chasis);
        }

        /// <summary>
        /// Conversor explícito a string. El string es la información del vehículo.
        /// </summary>
        /// <param name="p"></param>
        /// <returns>string</returns>
        public static explicit operator string(Vehiculo p)
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("CHASIS: {0}\r\n", p.chasis);
            sb.AppendFormat("MARCA : {0}\r\n", p.marca.ToString());
            sb.AppendFormat("COLOR : {0}\r\n", p.color.ToString());
            sb.AppendLine("---------------------");

            return sb.ToString();
        }
        #endregion



    }
}
