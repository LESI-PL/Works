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

namespace Pessoas
{
    /// <summary>
    /// Interface IPessoa contém atributos e métodos essenciais para uma pessoa
    /// </summary>
    public interface IPessoa
    {
        /// <summary>
        /// Obtém ou ajusta o componente bilhete de identidade
        /// <code>type: string</code>
        /// </summary>
        string BI
        {
            get;set;
        }
        /// <summary>
        /// Obtém ou ajusta o componente nome
        /// <code>type: string</code>
        /// </summary>
        string Nome
        {
            get;set;
        }
        /// <summary>
        /// Obtém ou ajusta o componente numero contribuinte
        /// <code>type: int</code>
        /// </summary>
        int NContribuinte
        {
            get;set;
        }
        /// <summary>
        /// Obtém ou ajusta o componente morada
        /// <code>type: string</code>
        /// </summary>
        string Morada
        {
            get;set;
        }
        /// <summary>
        /// Obtém ou ajusta o componente contacto
        /// <code>type: int</code>
        /// </summary>
        int Contacto
        {
            get;set;
        }
        /// <summary>
        /// <code> ShowDados </code>
        /// Descricao: Este metodo mostra é abstrato, sua funcionalidade é para mostrar os dados de uma pessoa
        /// <code>Return: string </code>
        /// </summary>
        string ShowDados();

    }
}
