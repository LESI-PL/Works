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
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pessoas
{
    /// <summary>
    /// Esta classe representa uma Pessoa
    /// <code>Type: Classe Abstrata</code>
    /// </summary>
    public abstract class Pessoa
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
        /// <summary>
        /// Obtém ou ajusta o componente bilhete de identidade
        /// <code>type: string</code>
        /// </summary>
        public string Bi
        {
            get { return bi; }
            set { bi = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente nome
        /// <code>type: string</code>
        /// </summary>
        public string Nome
        {
            get { return nome; }
            set { nome = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente numero contribuinte
        /// <code>type: int</code>
        /// </summary>
        public int NContribuinte
        {
            get { return nContribuinte; }
            set { nContribuinte = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente morada
        /// <code>type: string</code>
        /// </summary>
        public string Morada
        {
            get { return morada; }
            set { morada = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente contacto
        /// <code>type: int</code>
        /// </summary>
        public int Contacto
        {
            get { return contacto; }
            set { contacto = value; }
        }

        #endregion

        #region Metodos
        /// <summary>
        /// <code> MostraDados </code>
        /// Descricao: Este metodo mostra é abstrato, sua funcionalidade é para mostrar os dados de uma pessoa
        /// <code>Return: string </code>
        /// </summary>
        public abstract string MostraDados();
        #endregion

    }
}
