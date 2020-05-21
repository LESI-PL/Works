//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
//-----------------------------------------------------------------------

using Pessoas;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Auditorias.Controller
{
    /// <summary>
    /// 
    /// </summary>
    class MeuController
    {

        private Funcionario f;
        private Funcionarios fs;

        public MeuController()
        {
            
            fs = new Funcionarios();
            
        }

        public bool InsereFuncionario(string numeroBi, string nome, int contribuinte, string cargo, DateTime dataAdmissao)
        {
            f = new Funcionario(numeroBi, nome, contribuinte, cargo, dataAdmissao);
            return fs.InserirFuncionario(f);
        }

        
    }
}
