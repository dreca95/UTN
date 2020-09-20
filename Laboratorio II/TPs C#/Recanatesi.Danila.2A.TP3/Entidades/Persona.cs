using Excepciones;
using System;
using System.Text;
using System.Text.RegularExpressions;

namespace EntidadesAbstractas
{


    public abstract class Persona
    {
        #region Enumerado
        /// <summary>
        /// Enumerado de nacionalidad.
        /// </summary>
        public enum ENacionalidad
        {

            Argentino,
            Extranjero
        }
        #endregion

        #region Atributos
        string apellido;
        int dni;
        ENacionalidad nacionalidad;
        string nombre;
        #endregion

        #region Propiedades

        /// <summary>
        /// Permite asignar apellido con su respectiv validación, y obtener apellido.
        /// </summary>
        public string Apellido
        {
            set
            {

                try
                {
                    this.apellido = this.ValidarNombreApellido(value);


                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);

                }
            }
            get { return this.apellido; }

        }


        /// <summary>
        /// Permite asignar DNI con su respectiv validación, y obtener DNI.
        /// </summary>
        public int DNI
        {

            set
            {

               
                    this.dni = this.ValidarDni(this.Nacionalidad, value);

             
            }
            get { return this.dni; }

        }

        /// <summary>
        /// Permite asignar Nacionalidad con su respectiva validación en relación al DNI, y obtener nacionalidad.
        /// </summary>
        public ENacionalidad Nacionalidad
        {
            set
            {

                this.nacionalidad = value;




            }
            get { return this.nacionalidad; }

        }


        /// <summary>
        /// Permite asignar nombre con su respectiv validación, y obtener nombre.
        /// </summary>
        public string Nombre
        {
            set
            {
              
                this.nombre = this.ValidarNombreApellido(value);
             
            }
            get { return this.nombre; }

        }


        /// <summary>
        /// Permite asignar DNI desde un string, con su respectiva validación.
        /// </summary>
        public string StringToDNI
        {
            set
            {

              
                {
                    this.dni = this.ValidarDni(this.nacionalidad, value);
                }
              
            }
        }

        #endregion


        #region Validaciones

        /// <summary>
        /// Valida que el DNI coincida con la nacionalidad
        /// </summary>
        /// <param name="nacionalidad">Nacionalidad.</param>
        /// <param name="dato">Numero de documento.</param>
        /// <returns>El numero de documento validado.</returns>
        private int ValidarDni(ENacionalidad nacionalidad, int dato)
        {
            
            if ((nacionalidad == ENacionalidad.Argentino && (dato >= 1 && dato <= 89999999)) || (nacionalidad == ENacionalidad.Extranjero && (dato >= 90000000 && dato <= 99999999)))
                {
                    return dato;

                }
                else if (dato < 1 || dato > 99999999)
                {

                    throw new DniInvalidoException("El DNI debe estar compuesto solo por números del 1 al 99999999.");

                }
                else { throw new NacionalidadInvalidaException(); }


         
        }


        /// <summary>
        /// Valida que el DNI coincida con la nacionalidad
        /// </summary>
        /// <param name="nacionalidad">Nacionalidad.</param>
        /// <param name="dato">Numero de documento.</param>
        /// <returns>El numero de documento validado.</returns>
        private int ValidarDni(ENacionalidad nacionalidad, string dato)
        {
            try
            {
                if (dato != null && int.TryParse(dato, out dni))
                {
                    return this.ValidarDni(nacionalidad, dni);

                }
                else { throw new DniInvalidoException("El DNI debe estar compuesto solo por números."); }
            }
            catch (DniInvalidoException e)
            {

                throw e;
            }

        }

        /// <summary>
        /// Valida que el nombre o apellido esté compuesto por letras o espacios. 
        /// </summary>
        /// <param name="dato">String a validar.</param>
        /// <returns>nombtre o apellido validado, o cadena vacia sino pudo validarse.</returns>
        private string ValidarNombreApellido(string dato)
        {
            String retorno = "";

            if (dato != null)
            {
                Regex regex = new Regex(@"[a-zA-Z\\s]*");

                Match match = regex.Match(dato);

                if (match.Success)
                {
                    retorno = match.Value;
                }
            }
            return retorno;
        }
        #endregion

        #region Constructores

        public Persona()
        {
        }

        public Persona(string nombre, string apellido, ENacionalidad nacionalidad) : this()
        {
            this.Nombre = nombre;
            this.Apellido = apellido;
            this.Nacionalidad = nacionalidad;
        }

        public Persona(string nombre, string apellido, int dni, ENacionalidad nacionalidad) : this(nombre, apellido, dni.ToString(), nacionalidad)
        {
        }
        public Persona(string nombre, string apellido, string dni, ENacionalidad nacionalidad) : this(nombre, apellido, nacionalidad)
        {
            this.StringToDNI = dni;
        }

        #endregion


        /// <summary>
        /// Retorna datos de persona
        /// </summary>
        /// <returns>Datos de la persona.</returns>
        #region toString
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("NOMBRE COMPLETO: {0}, {1}\r\n", this.Apellido, this.Nombre);
            sb.AppendFormat("NACIONALIDAD: {0}\r\n", this.Nacionalidad.ToString());
            //sb.AppendFormat("DNI: {0}\r\n", this.DNI);

            return sb.ToString();
        }
        #endregion
    }
}
