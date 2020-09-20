using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Entidades;

namespace Test
{
    [TestClass]
    public class TestsUnitarios
    {
        [TestMethod]
        public void InstanciarListaDePaquetes()
        {
            Correo c = new Correo();
            Assert.IsNotNull(c.Paquetes);
        }
        [TestMethod]
        [ExpectedException(typeof(TrackingIdRepetidoException))]
        public void AgregarAListaDosPaquetesIguales()
        {
            Correo c = new Correo();
            Paquete p1 = new Paquete("José Saer", "9999999999");
            Paquete p2 = new Paquete("Franz Kakfa", "9999999999");
            
            c += p1;
            c += p2;
        }
    }
}
