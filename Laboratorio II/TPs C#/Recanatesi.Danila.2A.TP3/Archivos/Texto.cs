using Excepciones;
using System;
using System.IO;
using System.Text;

namespace Archivos
{
	public class Texto : IArchivo<string>
	{/// <summary>
	 /// Guarda un string en un archivo
	 /// </summary>
	 /// <param name="archivo">Path del archivo.</param>
	 /// <param name="datos">String con datos a guardar.</param>
	 /// <returns>Retorna true si la cadena se guardó, si no se produce una excepción.</returns>
		public bool Guardar(string archivo, string datos)
		{
			try
			{
				using (StreamWriter textArch = new StreamWriter(archivo, false, Encoding.UTF8))
				{
					textArch.WriteLine(datos);
					return true;
				}
			}
			catch (Exception e)
			{
				throw new ArchivosException(e);
			}

		}
		/// <summary>
		///Lee string de archivo y lo guarda en la variable correspondiente
		/// </summary>
		/// <param name="archivo">Path del archivo.</param>
		/// <param name="datos">Stringque guarda datos.</param>
		/// <returns>Retorna true si el archivo fue leído, de otra manera se produce una excepción.</returns>
		public bool Leer(string archivo, out string datos)
		{
			datos = "";
			try
			{
				using (StreamReader textArch = new StreamReader(archivo))
				{
					datos = textArch.ReadToEnd();
					return true;
				}
			}
			catch (Exception e)
			{
				throw new ArchivosException(e);
			}

		}
	}
}
