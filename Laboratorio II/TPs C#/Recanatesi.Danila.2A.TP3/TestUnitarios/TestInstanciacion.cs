using System;
using Clases_Instanciables;
using EntidadesAbstractas;
using EntidadesInstanciables;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace TestUnitarios
{
    [TestClass]
    public class TestInstanciacion
    {
        [TestMethod]
        public void TestUniversidadInstanciacionListaProfesor()
        {
            Universidad u = new Universidad();
            Profesor profesora = new Profesor(15,"Alfonsina","Storni","33369",Persona.ENacionalidad.Argentino);
            Profesor profesor = new Profesor(20, "Rodolfo", "Walsh", "87654",Persona.ENacionalidad.Argentino);
            u += profesora;
            u += profesor;
            Assert.AreEqual(2, u.Instructores.Count);
        }


        [TestMethod]
        public void TestUniversidadInstanciacionListaAlumno()
        {

            Universidad u = new Universidad();
            Alumno alumno = new Alumno(21, "Lev", "Tolstoi", "99999988", Persona.ENacionalidad.Extranjero,
            Universidad.EClases.Legislacion, Alumno.EEstadoCuenta.AlDia);
            u += alumno;
            Assert.IsNotNull(u.Alumnos);
    
        }


        [TestMethod]
        public void TestJornadaInstanciacion()
        {

            Universidad u = new Universidad();
            Profesor p = new Profesor(21, "Jose", "Donoso", "99999997", Persona.ENacionalidad.Extranjero);
            Jornada j = new Jornada(Universidad.EClases.Programacion, p);
            Assert.IsNotNull(j);

        }

    }
}
