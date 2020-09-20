using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Ticketeadora
    {

        public static bool ImprimirTicket(Cartuchera<Goma> c)
        {
            bool retorno = false;

            try
            {
                using (StreamWriter sw = new StreamWriter(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) +  @"\tickets.log", true))
                {
                    sw.WriteLine(DateTime.Now);
                    sw.WriteLine("Total: $" + c.PrecioTotal);
                    retorno = true;
                }
            }
            catch (Exception e)
            {

                throw new Exception(e.Message + " No pudo crearse el .log");
            }

            return retorno;
        }


    }
}
