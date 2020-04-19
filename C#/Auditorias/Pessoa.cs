//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
//-----------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Auditorias
{
    /// <summary>
    /// 
    /// </summary>
    class Pessoa
    {

        #region Atributos
        string bi;
        string nome;
        int nContribuinte;
        string morada;
        int contacto;
        #endregion

        #region Construtor
        public Pessoa()
        {

        }
        public Pessoa(string numeroBi, string nome, int contrinuinte)
        {
            bi = numeroBi;
            this.nome = nome;
            nContribuinte = contrinuinte;
        }
        #endregion

        #region Propriedades
        public string Bi
        {
            get { return bi; }
            set { bi = value; }
        }

        public string Nome
        {
            get { return nome; }
            set { nome = value; }
        }

        public int NContribuinte
        {
            get { return nContribuinte; }
            set { nContribuinte = value; }
        }

        public string Morada
        {
            get { return morada; }
            set { morada = value; }
        }

        public int Contacto
        {
            get { return contacto; }
            set { contacto = value; }
        }

        #endregion

        #region Metodos

        #endregion

    }
}
