//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>

namespace Defeitos
{
    /// <summary>
    /// 
    /// </summary>
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
 
         ///<summary>Inicializa uma nova instancia de Vulnerabilidade</summary>
        ///<param name="cod"><c>int</c> Codigo da Vulnerabilidade</param>
        ///<param name="descr"><c>string</c> Descrição da Vulnerabilidade</param>
        ///<param name="impacto"><c>string</c> Nivel de impacto da Vulnerabilidade</param>

        public Vulnerabilidade(int cod, string descr, string impacto)
        {
            codigo = cod;
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

        #endregion

    }
}
