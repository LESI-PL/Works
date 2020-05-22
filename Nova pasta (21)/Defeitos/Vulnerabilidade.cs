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

namespace Defeitos
{
    /// <summary>
    /// Esta Classe representa uma instancia de Vulnerabilidade 
    /// </summary>
    [Serializable]
    public class Vulnerabilidade
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

        ///<summary>
        ///Inicializa uma nova instancia de Vulnerabilidade
        ///</summary>
        public Vulnerabilidade()
        {

        }

        ///<summary>Inicializa uma nova instancia de Vulnerabilidade
        ///<code><param name="cod"><c>int</c> Codigo da Vulnerabilidade</param></code>
        ///<code><param name="descr"><c>string</c> Descrição da Vulnerabilidade</param></code>
        ///<code><param name="impacto"><c>string</c> Nivel de impacto da Vulnerabilidade</param></code>
        ///</summary>
        public Vulnerabilidade(string descr, string impacto)
        {
            descricao = descr;
            nivelImpacto = impacto;
        }
        #endregion

        #region Propriedades
        /// <summary>
        /// Obtém ou ajusta o componente codigo da vulnerabilidade
        /// <code>type: int</code>
        /// </summary>
        public int Codigo
        {
            get { return codigo; }
            set { codigo = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente descricao da vulnerabilidade
        /// <code>type: string</code>
        /// </summary>
        public string Descricao
        {
            get { return descricao; }
            set { descricao = value; }
        }

        /// <summary>
        /// Obtém ou ajusta o componente nivel de impacto da vulnerabilidade
        /// <code>type: string</code>
        /// </summary>
        public string NivelImpacto
        {
            get { return nivelImpacto; }
            set { nivelImpacto = value; }
        }
        #endregion

        #region Metodos

     
        
        public string MostraVulnerabilidade()
        {
            string txt = "";
            txt += "Id Vulnerabilidade: " + Codigo
                  + "\nDescricao:" + Descricao
                  + "\nNivel de Impacto:" + NivelImpacto + "\n";
               
            return txt;
        }
        #endregion

    }
}
