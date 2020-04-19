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
    class Funcionario : Pessoa
    {

        #region Atributos
        int idFuncionario;
        string cargo;
        DateTime dataAdmissao;
        bool estado;

        #endregion

        #region Construtor
        public Funcionario()
        {

        }

        public Funcionario(string numeroBi,string nome,int contribuinte,int id, string cargo, DateTime dataAdmissao) : base (numeroBi,nome,contribuinte)
        {
            idFuncionario = id;
            this.cargo = cargo;
            this.dataAdmissao = dataAdmissao;
            estado = true;

        }

        #endregion

        #region Propriedades

        public int IdFuncionario
        {
            get { return idFuncionario; }
            set { idFuncionario = value; }
        }

        public string Cargo
        {
            get { return cargo; }
            set { cargo = value; }
        }

        public DateTime DataAdmissao
        {
            get { return dataAdmissao; }
            set { dataAdmissao = value; }
        }

        public bool Estado
        {
            get { return estado; }
            set { estado = value; }
        }


        #endregion

        #region Metodos
        public string CheckEstado()
        {
            if (estado) return "Ativo";
            return "Não Ativo";
        }
        

        #endregion

    }
}
