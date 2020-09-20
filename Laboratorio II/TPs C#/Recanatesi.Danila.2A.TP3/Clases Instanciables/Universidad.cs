using Archivos;
using Clases_Instanciables;
using Excepciones;
using System;
using System.Collections.Generic;
using System.Text;

namespace EntidadesInstanciables
{
    public class Universidad
    {
        #region Enumerados
        /// <summary>
        /// Enumerado de clases.
        /// </summary>
        public enum EClases
        {

            Programacion,
            Laboratorio,
            Legislacion,
            SPD

        }
        #endregion

        #region Atributos
        List<Alumno> alumnos;
        List<Jornada> jornada;
        List<Profesor> profesores;
        #endregion

        #region Constructores
        public Universidad()
        {
            this.Alumnos = new List<Alumno>();
            this.Jornadas = new List<Jornada>();
            this.Instructores = new List<Profesor>();
        }

        #endregion




        #region Propiedades


        /// <summary>
        /// Asigna y obtiene valores de la lista de alumnos.
        /// </summary>
        public List<Alumno> Alumnos
        {
            set { this.alumnos = value; }
            get { return this.alumnos; }

        }

        /// <summary>
        /// Asigna y obtiene valores de la lista de jornadas.
        /// </summary>
        public List<Jornada> Jornadas
        {
            set { this.jornada = value; }
            get { return this.jornada; }

        }

        /// <summary>
        /// Asigna y obtiene valores de la lista de profesores.
        /// </summary>
        public List<Profesor> Instructores
        {
            set { this.profesores = value; }
            get { return this.profesores; }

        }

        #endregion

        #region Indexador
        /// <summary>
        /// Asigna y obtiene valores de la lista de jornadas a partir de un indice.
        /// </summary>
        /// <param name="i">Indice</param>
        /// <returns></returns>
        public Jornada this[int i]
        {

            set
            {
                try
                {
                    if (i >= 0 && i < this.Jornadas.Count)
                    {
                        this.Jornadas[i] = value;
                    }
                    else if (i == this.Jornadas.Count)
                    {
                        this.Jornadas.Add(value);
                    }
                    else
                    {

                        throw new Exception("El índice ingresado no se encuentra en el rango");

                    }
                }
                catch (Exception e)
                {

                    Console.WriteLine(e.Message);

                }
            }


            get
            {
                try
                {
                    if (i >= 0 && i < this.Jornadas.Count)
                    {
                        return this.Jornadas[i];
                    }
                    throw new Exception("El índice ingresado no se encuentra en el rango");

                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    return null;
                }
            }
        }
        #endregion


        #region Metodos

        /// <summary>
        /// Retorna datos de universidad.
        /// </summary>
        /// <returns>String que contiene datos de universidad.</returns>
        private static string MostrarDatos(Universidad uni)
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("JORNADA:");

            foreach (Jornada item in uni.Jornadas)
            {
                sb.Append(item.ToString());
                sb.AppendLine("<------------------------------------>");
            }


            return sb.ToString();
        }


        /// <summary>
        /// Guarda los datos de una universidad en un archivo .xlm ubicado en el escritorio
        /// </summary>
        /// <param name="u">Universidad a guardar.</param>
        /// <returns>True si se guardo exitosamente, sino false.</returns>
        public static bool Guardar(Universidad u)
        {
            try
            {
                Xml<Universidad> t = new Xml<Universidad>();


                string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\DRecanatesi";

                System.IO.Directory.CreateDirectory(path);


                path += @"\Universidad.xml";

                return t.Guardar(path, u);
            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
                return false;
            }
        }
        /// <summary>
        /// Lee los datos en xml y los retorna en un objeto Universidad.
        /// </summary>
        /// <returns>Universidad setada en base a datos leídos.</returns>
        public static Universidad Leer()
        {
            try
            {
                Universidad uni = new Universidad();
                Xml<Universidad> u = new Xml<Universidad>();
                u.Leer(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\DRecanatesi\Universidad.xml", out  uni);

                return uni;

            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
                return null;

            }
        }

        #endregion


        #region Operadores


        /// <summary>
        /// Verifica si pertenece a una universidad.
        /// </summary>
        /// <param name="g">Universidad.</param>
        /// <param name="a">Alumno.</param>
        /// <returns>True si el alumno pertenece, False si no pertenece.</returns>
        public static bool operator ==(Universidad g, Alumno a)
        {

            bool retorno = false;

            if (!object.Equals(g, null))
            {

                foreach (Alumno item in g.Alumnos)
                {


                    if (item == a)
                    {
                        retorno = true;
                        break;

                    }
                }
            }
            return retorno;
        }

        /// <summary>
        /// Verifica si no pertenece a una universidad.
        /// </summary>
        /// <param name="g">Universidad.</param>
        /// <param name="a">Alumno.</param>
        /// <returns>True si el alumno no pertenece y False si pertenece.</returns>
        public static bool operator !=(Universidad g, Alumno a)
        {
            return !(g == a);
        }

        /// <summary>
        /// Verifica si un profesor pertenece a una universidad.
        /// </summary>
        /// <param name="g">Universidad.</param>
        /// <param name="i">Profesor.</param>
        /// <returns>True si el profesor pertenece, False si no pertenece.</returns>
        public static bool operator ==(Universidad g, Profesor i)
        {

            bool retorno = false;

            foreach (Profesor item in g.Instructores)
            {


                if (item == i)
                {
                    retorno = true;
                    break;

                }
            }

            return retorno;
        }

        /// <summary>
        /// Verifica si un profesor no pertenece a una universidad.
        /// </summary>
        /// <param name="g">Universidad.</param>
        /// <param name="i">Profesor.</param>
        /// <returns>True si el profesor no pertenece, False si pertenece.</returns>
        public static bool operator !=(Universidad g, Profesor i)
        {
            return !(g == i);
        }

        /// <summary>
        /// Retorna al primer profesor que encuentre que sea capaz de dar la clase indicada  por parámetro.
        /// </summary>
        /// <param name="u">Universidad</param>
        /// <param name="clase">Clase</param>
        /// <returns>Profesor que datrá la clase.</returns>
        public static Profesor operator ==(Universidad u, EClases clase)
        {
            foreach (Profesor item in u.profesores)
            {
                if (item == clase)
                {
                    return item;
                }
            }
            throw new SinProfesorException();
        }

        /// <summary>
        /// Retorna al primer profesor que encuentre que no sea capaz de dar la clase indicada  por parámetro.
        /// </summary>
        /// <param name="u">Universidad</param>
        /// <param name="clase">Clase</param>
        /// <returns>Profesor que no dará la clase.</returns>
        public static Profesor operator !=(Universidad u, EClases clase)
        {
            Profesor profesor = null;

            foreach (Profesor item in u.profesores)
            {
                if (item != clase)
                {
                    profesor = item;
                }
            }

            return profesor;
        }


        /// <summary>
        /// Agrega un alumno a la unniversidad, en caso de que ya no se encuentre agregado previamente.
        /// </summary>
        /// <param name="u">Universidad</param>
        /// <param name="a">Alumno</param>
        /// <returns>Universidad con o sin alumno agregado.</returns>
        public static Universidad operator +(Universidad u, Alumno a)
        {
            if (!(u == a))
            {
                u.alumnos.Add(a);
            }
            else
            {
                throw new AlumnoRepetidoException();
            }
            return u;
        }
        /// <summary>
        /// Agrega un Profesor a la Universidad en caso de que no se encuentre en la lista previamente.
        /// </summary>
        /// <param name="universidad">Instancia de Universidad.</param>
        /// <param name="instructor">Instancia de Profesor.</param>
        /// <returns> Universidad con o sin profesor agregado.</returns>
        public static Universidad operator +(Universidad u, Profesor i)
        {
            if (u != i)
            {
                u.profesores.Add(i);
            }
            return u;
        }

        /// <summary>
        /// Agrega una Clase a la Universidad.
        /// </summary>
        /// <param name="g">Instancia de Universidad.</param>
        /// <param name="clase">Instancia de Clase</param>
        /// <returns>Devuelvo una universidad si se encuentra instructor para esa clase, caso contrario
        /// lanzo una excepción.</returns>
        public static Universidad operator +(Universidad g, EClases clase)
        {
            try
            {
                Profesor profesor = g == clase;

                Jornada jornada = new Jornada(clase, profesor);
                for (int i = 0; i < g.Alumnos.Count; i++)
                {
                    if (g.Alumnos[i] == clase)
                    {
                        jornada.Alumnos.Add(g.Alumnos[i]);
                    }
                }
                g.Jornadas.Add(jornada);
            }
            catch (SinProfesorException e)
            {
                throw e;
            }
            return g;
        }

        public override string ToString()
        {
            return MostrarDatos(this);
        }

        #endregion


    }
}