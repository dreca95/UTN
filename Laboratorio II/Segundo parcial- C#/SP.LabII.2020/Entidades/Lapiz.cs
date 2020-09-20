using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Entidades
{
  public class Lapiz : Utiles,ISerializa,IDeserializa
    {

        


        public ConsoleColor color;
        public ETipoTrazo trazo;

        public override bool PreciosCuidados { 
            
            get { return true; }
        
        }

        public Lapiz()
            : this(ConsoleColor.Black, ETipoTrazo.Fino, "-", 0)
        {
        }

        public Lapiz(ConsoleColor color, ETipoTrazo trazo, string marca, double precio)
            : base(marca, precio)
        {
            this.color = color;
            this.trazo = trazo;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat(base.UtilesToString());
            sb.AppendFormat("Color: {0}\r\n", this.color);
            sb.AppendFormat("Trazo: {0}\r\n", this.trazo);
            sb.AppendFormat("Precios cuidados: {0}\r\n", this.PreciosCuidados);

            return sb.ToString();
        }


        public bool Xml()
        {
            bool retorno = false;

            try
            {
                XmlSerializer s = new XmlSerializer(typeof(Lapiz));

                using (StreamWriter sw = new StreamWriter(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\" + this.Path))
                {
                    s.Serialize(sw, this);
                    retorno = true;
                }
            }
            catch (Exception e)
            {
               
                throw new Exception(e.Message+ " No se pudo serializar");
            }

            return retorno;
        }

        bool IDeserializa.Xml(out Lapiz lapiz)
        {
            bool retorno = false;
            lapiz = null;

            try
            {
                XmlSerializer s = new XmlSerializer(typeof(Lapiz));

                using (StreamReader sr = new StreamReader(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\" + this.Path))
                {
                    lapiz = (Lapiz)s.Deserialize(sr);

                    retorno = true;
                }
            }
            catch (Exception e)
            {

                throw new Exception(e.Message + " No se pudo deserializar");
            }

       
            return retorno;
        }

        public string Path { 
            
            
            get { return "recanatesi.danila.lapiz.xml"; }
        
        }

    }
}
