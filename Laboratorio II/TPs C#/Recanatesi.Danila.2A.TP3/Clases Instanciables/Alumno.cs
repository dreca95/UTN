
using EntidadesAbstractas;
using System;
using System.Text;
using static EntidadesInstanciables.Universidad;

namespace EntidadesInstanciables
{
    public sealed class Alumno : Universitario
    {
        #region Enumerado

        /// <summary>
        /// Enumerado de estado de cuenta.
        /// </summary>
        public enum EEstadoCuenta
        {

            AlDia,
            Deudor,
            Becado
        }
        #endregion

        #region Atributos
        EClases claseQueToma;
        EEstadoCuenta estadoCuenta;

        public Alumno() : base()
        {


        }
        #endregion

        #region Constructores
        public Alumno(int id, string nombre, string apellido, string dni, ENacionalidad nacionalidad, EClases claseQueToma) : base(id, nombre, apellido, dni, nacionalidad)
        {
            this.claseQueToma = claseQueToma;

        }

        public Alumno(int id, string nombre, string apellido, string dni, ENacionalidad nacionalidad, EClases claseQueToma, EEstadoCuenta estadoCuenta) : this(id, nombre, apellido, dni, nacionalidad, claseQueToma)
        {
            this.estadoCuenta = estadoCuenta;

        }

        #endregion

        #region Metodos

        /// <summary>
        /// Retorna la clase que es atributo de alumno.
        /// </summary>
        /// <returns>String de la clase en la que el alumno participa.</returns>
        protected override string ParticiparEnClase()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("TOMA CLASE DE {0}", this.claseQueToma.ToString());

            return sb.ToString();
        }

        /// <summary>
        /// Retorna los datos de un alumno.
        /// </summary>
        /// <returns>String de datos del alumno.</returns>
        protected override string MostrarDatos()
        {
            String estadoCuenta;
            StringBuilder sb = new StringBuilder();

            if (this.estadoCuenta == EEstadoCuenta.AlDia)
            {

                estadoCuenta = "Cuota al día";
            }
            else
            {

                estadoCuenta = this.estadoCuenta.ToString();

            }

            sb.Append(base.MostrarDatos());
            sb.AppendFormat("ESTADO DE CUENTA: {0}\r\n", estadoCuenta);
            sb.AppendLine(this.ParticiparEnClase());


            return sb.ToString();
        }

        #endregion

        #region Operadores

        /// <summary>
        /// Verifica si el alumno no es nulo, no tiene estado d ecuenta deudor, y  toma una clase determinada pasada por parámetro.
        /// </summary>
        /// <param name="a">Alumno</param>
        /// <param name="clase">Clase</param>
        /// <returns>True si el alumno participa en la clase, false si no participa.</returns>
        public static bool operator ==(Alumno a, EClases clase)
        {

            bool retorno = false;

            if (!object.Equals(a, null) && a.claseQueToma == clase && a.estadoCuenta != EEstadoCuenta.Deudor)
            {

                retorno = true;
            }
            return retorno;
        }

        /// <summary>
        /// Verifica si el alumno no es nulo, y  toma una clase determinada pasada por parámetro.
        /// </summary>
        /// <param name="a">Alumno</param>
        /// <param name="clase">Clase</param>
        /// <returns>True si el alumno participa en la clase, false si no participa.</returns>
        public static bool operator !=(Alumno a, EClases clase)
        {
            bool retorno = false;

            if (!object.Equals(a, null) && a.claseQueToma != clase)
            {

                retorno = true;
            }
            return retorno;
        }

        #endregion

        #region ToString

        /// <summary>
        /// Retorna los datos de un alumno.
        /// </summary>
        /// <returns>String de datos del alumno.</returns>
        public override string ToString()
        {
            return this.MostrarDatos();
        }
        #endregion
    }
}