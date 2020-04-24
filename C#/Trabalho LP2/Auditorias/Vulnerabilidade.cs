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
    class Vulnerabilidade
    {
        /*
         * Vulnerabilidades Contém:
         *         - Código da vulnerabilidade
         *         - Descrição
         *         - Nivel de impacto que são eles:
         *                  + Elevado
         *                  + Médio
         *                  + Baixo
         */
        #region Atributos
        int codigo;
        string descricao;
        string nivelImpacto;

        #endregion

        #region Construtor
        public Vulnerabilidade()
        {

        }
        public Vulnerabilidade(int cod, string descr, string impacto)
        {
            codigo = cod;
            descricao = descr;
            nivelImpacto = impacto;
        }
        #endregion

        #region Propriedades
        public int Codigo
        {
            get { return codigo; }
            set { codigo = value; }
        }
        public string Descricao
        {
            get { return descricao; }
            set { descricao = value; }
        }
        public string NivelImpacto
        {
            get { return nivelImpacto; }
            set { nivelImpacto = value; }
        }
        #endregion

        #region Metodos

        #endregion

    }
}
