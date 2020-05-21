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

namespace InterfacesAuditoria
{
    
    public interface IVerification
    {
        /// <summary>
        /// Este metodo converte uma string para int, caso o valor na string nao seja numeros o valor predefinido que sai no out é zero
        /// </summary>
        /// <param name="idString"></param>
        /// <param name="id"></param>
        /// <returns>true se for numero</returns>
        bool VerificaId(string codigo, out int id);
    }
}
