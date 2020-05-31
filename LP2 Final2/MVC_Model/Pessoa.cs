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
    /// Esta classe representa uma Pessoa
    /// <code>Type: Classe Abstrata</code>
    /// </summary>
    [Serializable]
    public abstract class Pessoa : IPessoa
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *BI - Numero do bilhete de identidade
        /// *Nome - Nome da pessoa
        /// *nContribuinte - Nº Contribuinte
        /// *morada - Morada da pessoa
        /// *contacto - Contacto da pessoa
        /// </summary>
        string bi;
        string nome;
        int nContribuinte;
        string morada;
        int contacto;
        #endregion

        #region Propriedades        
        public string BI { get => bi; set => bi = value; }

        public string Nome { get => nome; set => nome = value; }

        public int NContribuinte { get => nContribuinte; set => nContribuinte = value; }

        public string Morada { get => morada; set => morada = value; }

        public int Contacto { get => contacto; set => contacto = value; }
        #endregion

        #region Metodos        
        public virtual string ShowDados()
        {
            string txt = "";
            txt += "Nome:" + Nome
                + "\nBI:" + BI
                + "\nContribuinte:" + NContribuinte
                + "\nMorada:" + Morada
                + "\nContacto:" + Contacto;
            return txt;
        }
        #endregion

    }
}
