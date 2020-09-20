using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Runtime.CompilerServices;
using System.CodeDom;

namespace Entidades
{
    public static class PaqueteDAO
    {
        #region Atributos
        private static SqlCommand comando;
        private static SqlConnection conexion;
        #endregion

        static PaqueteDAO()
        {
            PaqueteDAO.conexion = new SqlConnection(Recanatesi.Danila._2A.TP4.Properties.Settings.Default.conexionBD);
        }

        public static bool Insertar(Paquete p)
        {
            try
            {
                PaqueteDAO.comando = new SqlCommand();
     
                PaqueteDAO.comando.CommandType = CommandType.Text;
                PaqueteDAO.comando.Connection = PaqueteDAO.conexion;
               

                string sql = "INSERT INTO Paquetes (direccionEntrega,trackingID,alumno) VALUES (@direccionEntrega, @trackingID, @alumno)";



                PaqueteDAO.comando.Parameters.AddWithValue("@direccionEntrega", p.DireccionEntrega);
                PaqueteDAO.comando.Parameters.AddWithValue("@trackingID", p.TrackingID);
                PaqueteDAO.comando.Parameters.AddWithValue("@alumno", "Danila Recanatesi");

                PaqueteDAO.comando.CommandText = sql;

                PaqueteDAO.conexion.Open();

                PaqueteDAO.comando.ExecuteNonQuery();

                   
                
                
                return true;
               


            }
            catch (Exception)
            {


                return false;

            }
            finally {

                if (conexion.State == ConnectionState.Open)
                {
                    conexion.Close();
                }
            }
                

                 

                
             

            
           
            
        }
    }
}

