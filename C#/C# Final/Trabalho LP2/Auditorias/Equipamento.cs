using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Auditorias
{
    class Equipamento
    {
        #region Atributos
        int codigo;
        string tipo;
        string marca;
        string modelo;
        DateTime aquisisao;
        #endregion


        #region Construtor
        /// <summary>
        /// Construtor por padrao
        /// </summary>
        public Equipamento()
        {

        }
        /// <summary>
        /// Construtor por valores indicados
        /// </summary>
        /// <param codigo="numero"></param>
        /// <param tipo="type"></param>
        /// <param marca="brand"></param>
        /// <param modelo="model"></param>
        /// <param data de aquisicao="comprado"></param>
        public Equipamento(int numero, string type, string brand, string model, DateTime comprado)
        {
            codigo = numero;
            tipo = type;
            marca = brand;
            modelo = model;
            aquisisao = comprado;
        }

        #endregion

        #region Propriedades 

        public int Codigo
        {

            get { return codigo; }
            set { codigo = value; }
        }

        public string Tipo
        {
            get { return tipo; }
            set { tipo = value; }

        }

        public string Marca
        {
            get { return marca; }
            set { marca = value; }

        }
        public string Modelo
        {
            get { return modelo; }
            set { modelo = value; }

        }
        public DateTime Aquisicao
        {
            get { return aquisisao; }
            set { aquisisao = value; }
        }

        #endregion


        #region Metodos

        public override string ToString()
        {
            return "Equipamento" + this.marca + this.modelo + this.tipo;

        }

        #endregion
    }
}



