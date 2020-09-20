using System;
using EntidadesAbstractas;
using EntidadesInstanciables;
using Excepciones;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace TestUnitarios
{
    [TestClass]
    public class TestExcepciones
    {
        [TestMethod]
        [ExpectedException(typeof(AlumnoRepetidoException))]

        public void TestAlumnoRepetidoException()
        {

            Alumno alumno = new Alumno(10, "Marcel", "Proust", "99999995", Persona.ENacionalidad.Extranjero, Universidad.EClases.SPD, Alumno.EEstadoCuenta.AlDia);
            Alumno alumnoII = new Alumno(11, "Bertolt", "Brecht", "99999995", Persona.ENacionalidad.Extranjero, Universidad.EClases.Programacion, Alumno.EEstadoCuenta.Becado);

            Universidad universidadTest = new Universidad();
            universidadTest += alumno;
            universidadTest += alumnoII;
        }

        [TestMethod]
        [ExpectedException(typeof(SinProfesorException))]
        public void TestSinProfesorException()
        {
            Universidad universidad = new Universidad();
            universidad += Universidad.EClases.Laboratorio;
        }


        [TestMethod]
        [ExpectedException(typeof(DniInvalidoException))]
        public void TestDniInvalidoException()
        {
           
           Profesor profesor= new Profesor(22, "Abelardo", "Castillo", "7777q", Persona.ENacionalidad.Argentino);
        }

        [TestMethod]
        [ExpectedException(typeof(NacionalidadInvalidaException))]

        public void TestNacionalidadInvalidaException()
        {

            Alumno alumno = new Alumno(10, "Marcel", "Proust", "99999995", Persona.ENacionalidad.Argentino, Universidad.EClases.SPD, Alumno.EEstadoCuenta.AlDia);
          
        }


    }
}

