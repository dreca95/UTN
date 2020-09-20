using Archivos;
using EntidadesInstanciables;
using Excepciones;
using System;
using System.Collections.Generic;
using System.Text;
using static EntidadesInstanciables.Universidad;

namespace Clases_Instanciables
{
    public class Jornada
    {
        #region Atributos
        private List<Alumno> alumnos;
        private EClases clase;
        private Profesor instructor;
        #endregion

        #region Constructores
        private Jornada()
        {
            this.Alumnos = new List<Alumno>();
        }

        public Jornada(Universidad.EClases clase, Profesor instructor) : this()
        {
            this.Clase = clase;
            this.Instructor = instructor;
        }

        #endregion

        #region Propiedades


        /// <summary>
        /// Permite asignar valor a la lista de alumnos u obtenerlo.
        /// </summary>
        public List<Alumno> Alumnos
        {

            set
            { this.alumnos = value; }
            get
            { return this.alumnos; }
        }


        /// <summary>
        /// Permite asignar valor al atributo clase u obtenerlo.
        /// </summary>
        public EClases Clase
        {
            set { this.clase = value; }
            get { return this.clase; }

        }

        /// <summary>
        /// Permite asignar valor al atributo profesor u obtenerlo.Se valida que el profesor pueda participar en la clase.
        /// </summary>
        public Profesor Instructor
        {
            set
            {
                try
                {
                    if (value == this.clase)
                    {
                        this.instructor = value;
                    }
                    else
                    {
                        throw new SinProfesorException();
                    }
                }
                catch (Exception e)
                {

                    Console.WriteLine(e.Message);

                }
            }
            get { return this.instructor; }
        }

        #endregion


        #region Operadores

        /// <summary>
        /// Verifica si un alumno participa en la clase de la jornada.Verifica que ni la jornada ni el alumno sean nulos.
        /// </summary>
        /// <param name="j">jornada</param>
        /// <param name="a">alumno</param>
        /// <returns>True si el alumno participa, false si no participa.</returns>
        public static bool operator ==(Jornada j, Alumno a)
        {
            return !object.Equals(j, null) && !object.Equals(a, null) && a == j.Clase;
        }

        /// <summary>
        /// Verifica si un alumno no participa en la clase de la jornada.Verifica que ni la jornada ni el alumno sean nulos.
        /// </summary>
        /// <param name="j">jornada</param>
        /// <param name="a">alumno</param>
        /// <returns>True si el alumno no participa, false si participa.</returns>
        public static bool operator !=(Jornada j, Alumno a)
        {
            return !(j == a);
        }


        /// <summary>
        /// Verifica que el alumno participe en la clase, si el alumno participa y aun no esta en la lista, lo agrega.
        /// </summary>
        /// <param name="j">Jornada</param>
        /// <param name="a">Alumno</param>
        /// <returns>Retora la jornada con o sin el alumno agregado.</returns>
        public static Jornada operator +(Jornada j, Alumno a)
        {
            bool alumnoAgregadoAntes = false;

            if (j != a)
            {

                foreach (Alumno item in j.Alumnos)
                {
                    if (item.Equals(a))
                    {
                        alumnoAgregadoAntes = true;
                        break;
                    }
                }

                if (!alumnoAgregadoAntes)
                {
                    j.Alumnos.Add(a);
                }
            }
            return j;

        }
        #endregion

        #region ToString

        /// <summary>
        /// Retorna string con los datos de la jornada
        /// </summary>
        /// <returns>String con datos de jornada.</returns>
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
  
            sb.AppendFormat("CLASE DE {0} POR {1}", this.Clase.ToString(), this.Instructor.ToString());
            sb.AppendLine("ALUMNOS:");

            foreach (Alumno item in this.Alumnos)
            {
                sb.Append(item.ToString());
            }

            return sb.ToString();
        }
        #endregion

        /// <summary>
        /// Guarda los datos de una jornada en un archivo .txt ubicado en la carpeta DRecanatesi en el escritorio
        /// </summary>
        /// <param name="u">Universidad a guardar.</param>
        /// <returns>True si se guardo exitosamente, sino false.</returns>
        public static bool Guardar(Jornada jornada)
        {
            try
            {
                Texto t = new Texto();
                string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\DRecanatesi";

                System.IO.Directory.CreateDirectory(path);


                path += @"\Jornada.txt";
                return t.Guardar(path, jornada.ToString());

            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
                return false;

            }

        }
        /// <summary>
        /// Lee los datos en.txt ubicado en la carpeta DRecanatesi en el escritorio y los retorna en un string.
        /// </summary>
        /// <returns>String en base a datos leídos.</returns>
        public static string Leer()
        {
            Texto t = new Texto();

            try
            {
                t.Leer(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\DRecanatesi\Jornada.txt", out string retorno);
                return retorno;
            }
            catch (Exception e)
            {


                Console.WriteLine(e.Message);
                return null;

            }



        }


    }
}
