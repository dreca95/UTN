namespace Archivos
{
    public interface IArchivo<T>
    {   /// <summary>
        /// Guarda cualquier tipo de dato en el archivo señalado.
        /// </summary>
        /// <param name="archivo">Path del archivo.</param>
        /// <param name="datos">Dato genérico a guardar.</param>
        /// <returns>Retorna true si se guardó exitosamente.</returns>
        bool Guardar(string archivo, T datos);

        /// <summary>
		/// Lee cualquier tipo de dato que esté en el archivo selalado.
		/// </summary>
		/// <param name="archivo">Path del archivo.</param>
		/// <param name="datos">Parámetro de salida para almacenar datos.</param>
		/// <returns>Retorna true si se elyó el archivo exitosamente.</returns>
        bool Leer(string archivo, out T datos);

    }
}
