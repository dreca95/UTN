using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{

    public static class GuardaString
    {
        public static bool Guardar(this string texto, string archivo)
        {
            string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\DRecanatesi";

            if (!System.IO.File.Exists(path))
            { 
                System.IO.Directory.CreateDirectory(path);
            }

            try
            {
                using (StreamWriter sw = new StreamWriter(path + @"\" + archivo + ".txt", true))
                {



                    sw.Write(string.Format("[{0}]\n{1}\n", DateTime.Now.ToString(), texto));

                    sw.Close();
                    return true;
                    
                }
            }
            catch
            {
                return false;
                throw new Exception("No pudo guardarse el archivo"); //fijar
                
            }
           
         
        }
    }
}

