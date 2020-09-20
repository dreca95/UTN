using System.Text;

namespace EntidadesAbstractas
{
    public abstract class Universitario : Persona
    {
        #region Atributo
        int legajo;
        #endregion

        #region Constructores
        public Universitario() : base() { }

        public Universitario(int legajo, string nombre, string apellido, string dni, ENacionalidad nacionalidad)
            : base(nombre, apellido, dni, nacionalidad)
        {
            this.legajo = legajo;
        }

        #endregion

        #region Operadores


        /// <summary>
        /// Verifica si dos Universitarios son iguales, esto implica no ser nulos y tener el mismo DNI o Legajo.
        /// </summary>
        /// <param name="pg1">Primer universitario.</param>
        /// <param name="pg2">Segundo universitario.</param>
        /// <returns>true si tienen el mismo Legajo o DNI, sino false.</returns>
        public static bool operator ==(Universitario pg1, Universitario pg2)
        {
            bool retorno = false;

            if (!object.Equals(pg1, null) && !object.Equals(pg2, null) && (pg1.legajo == pg2.legajo || pg1.DNI == pg2.DNI))
            {

                retorno = true;
            }

            return retorno;
        }



        /// <summary>
        /// Verifica si dos Universitarios no son iguales, esto implica no ser nulos y no tener el mismo DNI o Legajo.
        /// </summary>
        /// <param name="pg1">Primer universitario.</param>
        /// <param name="pg2">Segundo universitario.</param>
        /// <returns>true si no tienen el mismo Legajo o DNI, sino false.</returns>
        public static bool operator !=(Universitario pg1, Universitario pg2)
        {
            return !(pg1 == pg2);
        }
        /// <summary>
        /// Verifica si el objeto  es de tipo Universitario y
        /// verifica si es igual en terminons del operador == .
        /// </summary>
        /// <param name="o">Objeto a comparar.</param>
        /// <returns>true si son iguales, false si no lo son.</returns>
        public override bool Equals(object o)
        {
            bool retorno = false;

            if (o is Universitario)
            {

                retorno = this == (Universitario)o;
            }

            return retorno;
        }

        #endregion

        #region Metodos
        protected abstract string ParticiparEnClase();



        /// <summary>
        /// Retorna datos del universitario.
        /// </summary>
        /// <returns>Datos de universitario.</returns>
        protected virtual string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.ToString());
            sb.AppendFormat("LEGAJO NÚMERO: {0}\r\n", this.legajo);

            return sb.ToString();
        }
        #endregion

    }
}
