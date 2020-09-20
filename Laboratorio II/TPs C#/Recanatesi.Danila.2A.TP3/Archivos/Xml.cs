using Excepciones;
using System;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace Archivos
{
	public class Xml<T> : IArchivo<T>
	{
		/// <summary>
		/// Guarda datos en un archivo xml
		/// </summary>
		/// <param name="archivo">Path del archivo.</param>
		/// <param name="datos">Datos a guardar.</param>
		/// <returns>Retorna true si los datos se guardaron, si no se produce una excepción.</returns>
		public bool Guardar(string archivo, T datos)
		{
			try
			{
				using (XmlTextWriter xmlTextWriter = new XmlTextWriter(archivo, Encoding.UTF8))
				{
					XmlSerializer ser = new XmlSerializer(typeof(T));
					ser.Serialize(xmlTextWriter, datos);
					xmlTextWriter.Close();
					return true;

				}
			}
			catch (Exception e)
			{
				throw new ArchivosException(e);
			}

		}
		/// <summary>
		///Lee datos de un archivo y lo guarda en la variable correspondiente
		/// </summary>
		/// <param name="archivo">Path del archivo.</param>
		/// <param name="datos">Variable que guarda datos.</param>
		/// <returns>Retorna true si el archivo fue leído, de otra manera se produce una excepción.</returns>
		public bool Leer(string archivo, out T datos)
		{
			try
			{
				using (XmlTextReader xmlTextReader = new XmlTextReader(archivo))
				{
					XmlSerializer deserializer = new XmlSerializer(typeof(T));
					datos = (T)deserializer.Deserialize(xmlTextReader);
					xmlTextReader.Close();
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
