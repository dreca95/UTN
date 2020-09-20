using System;

namespace Excepciones
{
    public class DniInvalidoException : Exception
    {

        private static string mensajeBase = "Formato incorrecto.";



        public DniInvalidoException()
            : this("")
        {

        }
        public DniInvalidoException(string message)
            : this(message, null)
        {

        }
        public DniInvalidoException(Exception e)
            : this("", e)
        {

        }
        public DniInvalidoException(string message, Exception e)
            : base(mensajeBase + " " + message, e)
        {

        }


    }
}
