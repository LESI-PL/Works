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

namespace MinhasExceptionsLib
{
    /// <summary>
    /// 
    /// </summary>
    public class ValoresExceptions : ApplicationException
    {
        public ValoresExceptions() : base("Valor Inserido Errado") { }

        public ValoresExceptions(string s) : base(s) { }

        public ValoresExceptions(string s, Exception e)
        {
            throw new ValoresExceptions(e.Message + " - " + s);
        }
        

    }
}
