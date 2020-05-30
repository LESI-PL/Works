//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
using System;

namespace MVC_Model
{
    /// <summary>
    /// Esta Classe representa uma instancia de Equipamento 
    /// </summary>
    [Serializable]
    public class Equipamento
    {
        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *codigoEqui - Numero de identificação do equipamento na empresa
        /// *tipo - Qual a categoria do equipamento (Eg: Impressora, Portatil, etc...)
        /// *marca - Qual a marca do equipamento da empresa
        /// *modelo - Qual o modelo do equipamento
        /// *aquisisao - Data de compra do equipamento pela Empresa
        /// *estado - Qual a situação d o equipamento na empresa (se foi para o lixo)
        /// </summary>
    
        int codigoEqui;
        string tipo;
        string marca;
        string modelo;
        DateTime aquisisao;
        bool estado;
        #endregion


        #region Construtor
        /// <summary>
        /// Inicializa uma nova instancia de Equipamento
        /// </summary>
        public Equipamento()
        {

        }
        /// <summary>
        /// Inicializa uma nova instancia de Equipamento
        /// </summary>
        /// <param name="numero"><c>int</c> Numero do Equipamento na Empresa </param>
        /// <param name="type"><c>string</c> Tipo do equipamento </param>
        /// <param name="brand"><c>string</c> Marca do Equipamento </param>
        /// <param name="model"><c>string</c> Modelo do Equipamento </param>
        /// <param name="comprado"><c>DateTime</c> Data de aquisição do equipamento pela empresa </param>
        public Equipamento( string type, string brand, string model, DateTime comprado)
        {
        
            tipo = type;
            marca = brand;
            modelo = model;
            aquisisao = comprado;
            estado = true;
        }

        #endregion

        #region Propriedades 

        /// <summary>
        /// Obtém ou ajusta o componente codigo do Equipamento
        /// <code>type: int</code>
        /// </summary>
        public int Codigo
        {

            get { return codigoEqui; }
            set { codigoEqui = value; }
       
        }


        /// <summary>
        /// Obtém ou ajusta o componente Tipo do Equipamento
        /// <code>type: string </code>
        /// </summary>
        public string Tipo
        {
            get { return tipo; }
            set { tipo = value; }

        }

        /// <summary>
        /// Obtém ou ajusta o componente Marca do Equipamento
        /// <code>type: string </code>
        /// </summary>
        public string Marca
        {
            get { return marca; }
            set { marca = value; }

        }
        /// <summary>
        /// Obtém ou ajusta o componente Modelo do Equipamento
        /// <code>type: string </code>
        /// </summary>
        public string Modelo
        {
            get { return modelo; }
            set { modelo = value; }

        }

        /// <summary>
        /// Obtém ou ajusta a componente data de aquisição do equipamento
        /// <code>type: Datetime </code>
        /// </summary>
        public DateTime Aquisicao
        {
            get { return aquisisao; }
            set { aquisisao = value; }
        }

        /// <summary>
        /// Obtém ou ajusta a componente estado do equipamento
        /// <code>type: Datetime </code>
        /// </summary>
        public bool Estado
        {
            get { return estado; }
            set { estado = value; }
        }

        #endregion


        #region Metodos
        /// <summary>
        /// Override do to string para mostrar apenas um equipamento
        /// </summary>
        /// <returns></returns>
        public string MostraDados()
        {
            string txt = "";
            txt += "Codigo:"+codigoEqui+
                   "\nMarca: "+ Marca +
                   "\nModelo: "+ Modelo+
                   "\nData: "+Aquisicao.ToShortDateString()+
                   "\nEstado: "+Estado+"\n\n";
            return txt;

        }

        #endregion
    }
}



