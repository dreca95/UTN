using EntidadesAbstractas;
using System;
using System.Collections.Generic;
using System.Text;
using static EntidadesInstanciables.Universidad;

namespace EntidadesInstanciables
{
    public class Profesor : Universitario
    {
        #region Atributos
        private Queue<EClases> clasesDelDia;
        private static Random random;

        #endregion

        #region Constructores
        public Profesor() : base()
        {
            this.clasesDelDia = new Queue<EClases>();
        }
        static Profesor()
        {
            Profesor.random = new Random();
        }

        public Profesor(int id, string nombre, string apellido, string dni, ENacionalidad nacionalidad) : base(id, nombre, apellido, dni, nacionalidad)
        {
            this.clasesDelDia = new Queue<EClases>();
            this._randomClases();
        }
        #endregion

        #region Metodos
        /// <summary>
        /// Asigna dos clases a un profesor.
        /// </summary>
        private void _randomClases()
        {
            while (this.clasesDelDia.Count < 2)
            {
                this.clasesDelDia.Enqueue((EClases)Profesor.random.Next(0, 4));
            }
        }


        /// <summary>
        ///Retorna las clases en las que participa el profesor en formato string.
        /// </summary>
        /// <returns>String de clases en las que participa el profesor.</returns>
        protected override string ParticiparEnClase()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("CLASES DEL DÍA:");

            foreach (EClases item in this.clasesDelDia)
            {
                sb.AppendLine(item.ToString());
            }

            sb.AppendLine("");

            return sb.ToString();
        }

        /// <summary>
        /// Retorna datos del profesor.
        /// </summary>
        /// <returns>String de datos del profesor.</returns>
        protected override string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.Append(base.MostrarDatos());
            sb.Append(this.ParticiparEnClase());

            return sb.ToString();
        }

        #endregion

        #region Operadores


        /// <summary>
        /// Verifica que el objeto profesor no sea nulo, y si no es nulo, si participa en la clase pasada por parámetro.
        /// </summary>
        /// <param name="i">Profesor.</param>
        /// <param name="clase">Clase.</param>
        /// <returns>True si el profesor participa, false si no participa.</returns>
        public static bool operator ==(Profesor i, EClases clase)
        {

            bool retorno = false;

            if (!object.Equals(i, null))
            {

                foreach (EClases item in i.clasesDelDia)
                {
                    if (item == clase)
                    {
                        retorno = true;
                        break;
                    }
                }

            }
            return retorno;
        }

        /// <summary>
        /// Verifica que el objeto profesor no sea nulo, y si no es nulo, si no participa en la clase pasada por parámetro.
        /// </summary>
        /// <param name="i">Profesor.</param>
        /// <param name="clase">Clase.</param>
        /// <returns>True si el profesor no participa, false si participa.</returns>
        public static bool operator !=(Profesor i, EClases clase)
        {
            return !(i == clase);
        }

        #endregion

        #region ToString


        /// <summary>
        /// Retorna datos del profesor.
        /// </summary>
        /// <returns>String de datos del profesor.</returns>
        public override string ToString()
        {
            return this.MostrarDatos();
        }
        #endregion
    }
}
