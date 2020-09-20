using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public static class CartucheraLlenaExtension
    {
        public static string InformarNovedad(this CartucheraLlenaException excepcion)
        {
            return excepcion.Message;
        }


    }
}
