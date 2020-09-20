using System;

namespace Excepciones
{
    public class ArchivosException : Exception
    {



        /// <summary>
        ///Excepción con mensaje por defecto mas innerException
        /// </summary>
        /// <param name="innerException"></param>
        public ArchivosException(Exception innerException) : base("Error en el manejo del archivo.", innerException)
        {
        }


    }
}