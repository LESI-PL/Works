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
    class Funcionarios
    {

        #region Atributos

        List<Funcionario> funcionarios;
        int qtdFuncionarios;
        #endregion

        #region Construtor
        public Funcionarios()
        {
            funcionarios = new List<Funcionario>();
            qtdFuncionarios = 0;
        }
        #endregion

        #region Propriedades
        public int QtdFuncionario
        {
            get { return qtdFuncionarios; }
            set { qtdFuncionarios = value; }
        }
        #endregion

        #region Metodos
        public bool InserirFuncionario(Funcionario funcionario)
        {
            qtdFuncionarios++;
            funcionarios.Add(funcionario);
            return true;
        }

        public override string ToString()
        {
            string txt = "";
            for(int i = 0; i < qtdFuncionarios; i++)
            {
                txt += "Nome: " + funcionarios[i].Nome+"\n";
            }
            return txt;
        }
        #endregion

    }
}
