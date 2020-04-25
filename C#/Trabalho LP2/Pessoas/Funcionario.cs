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
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pessoas
{
    /// <summary>
    /// Esta Classe representa uma instancia de Funcionario 
    /// <code>Herança: Pessoa</code>
    /// </summary>
    public class Funcionario : Pessoa
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *idFuncionario - Numero de identificação do funcionario na empresa
        /// *cargo - Qual o cargo ou função que ocupa
        /// *dataAdmissao - A data em que foi admitido na empresa
        /// *estado - Estado da pessoa na empresa ( Se ainda trabalha para a empresa ou não)
        /// </summary>
        int idFuncionario;
        string cargo;
        DateTime dataAdmissao;
        bool estado;

        #endregion

        #region Construtor
        ///<summary>
        ///Inicializa uma nova instancia de Funcionario</summary>
        public Funcionario()
        {

        }
        ///<summary>Inicializa uma nova instancia de Funcionarios</summary>
        ///<param name="numeroBi"><c>string</c> Numero do bilhete de identidade</param>
        ///<param name="nome"><c>string</c> Nome da pessoa</param>
        ///<param name="contribuinte"><c>int</c> Numero de contribuinte</param>
        ///<param name="dataAdmissao"><c>DateTime</c> A data de admissão na empresa</param>
        ///<param name="cargo"><c>string</c> Qual o cargo que irá ocupar</param>
        public Funcionario(string numeroBi, string nome, int contribuinte, string cargo, DateTime dataAdmissao)
        {
            base.Bi = numeroBi;
            base.Nome = nome;
            base.NContribuinte = contribuinte;
            this.cargo = cargo;
            this.dataAdmissao = dataAdmissao;
            estado = true;

        }

        #endregion

        #region Propriedades


        /// <summary>
        /// Obtém ou ajusta o componente id funcionario
        /// <code>type: int</code>
        /// </summary>
        public int IdFuncionario
        {
            get { return idFuncionario; }
            set { idFuncionario = value; }
        }


        /// <summary>
        /// Obtém ou ajusta o componente cargo do funcionario
        /// <code>type: string</code>
        /// </summary>
        public string Cargo
        {
            get { return cargo; }
            set { cargo = value; }
        }


        /// <summary>
        /// Obtém ou ajusta o componente data de admissão do funcionario
        /// <code>type: DateTime</code>
        /// </summary>
        public DateTime DataAdmissao
        {
            get { return dataAdmissao; }
            set { dataAdmissao = value; }
        }


        /// <summary>
        /// Obtém ou ajusta o componente estado do funcionario
        /// <code>type: bool</code>
        /// </summary>
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

        public override string MostraDados()
        {
            string txt = "";
            txt += "Nome Colaborador:" + Nome
                  + "\nNº B.I:" + Bi
                  + "\nNº Interno:" + IdFuncionario
                  + "\nCargo:" + Cargo
                  + "\nData Admissão: " + DataAdmissao.Day + "/" + DataAdmissao.Month + "/" + DataAdmissao.Year + "\n";
            txt += "Estado: " + CheckEstado() + "\n";
            return txt; ;
        }

        #endregion

    }
}
