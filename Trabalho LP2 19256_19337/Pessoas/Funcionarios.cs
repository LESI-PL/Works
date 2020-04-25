//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>

using MinhasInterfaces;
using System;
using System.Collections.Generic;

namespace Pessoas
{
    /// <summary>
    /// Esta Classe representa uma instancia de Funcionarios 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>

    public class Funcionarios : IMetodosGenericos
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *funcionarios - Criação de uma lista do tipo Funcionarios
        /// *qtdFuncionarios - Quantidade de funcionarios que existe na lista
        /// </summary>
        List<Funcionario> funcionarios;
        int qtdFuncionarios;
        #endregion

        #region Construtor
        ///<summary>
        ///Inicializa uma nova instancia de Funcionarios
        ///</summary>
        public Funcionarios()
        {
            funcionarios = new List<Funcionario>();
            qtdFuncionarios = 0;
        }
        #endregion

        #region Propriedades
        /// <summary>
        /// Obtém ou ajusta o componente quantidade de Funcionarios
        /// <code>type: int</code>
        /// </summary>
        public int QtdFuncionario
        {
            get { return qtdFuncionarios; }
            set { qtdFuncionarios = value; }
        }
        #endregion

        #region Metodos

        #region Metodos Inserção
        /// <summary>
        /// Insere um funcionario na lista
        /// </summary>
        /// <param name="funcionario"></param>
        /// <returns></returns>
        public bool InserirFuncionario(Funcionario funcionario)
        {
            int indice = Procura(funcionario.IdFuncionario);
            if (indice == -1)
            {
                qtdFuncionarios++;
                funcionario.IdFuncionario = qtdFuncionarios;
                funcionarios.Add(funcionario);
                return true;
            }
            return false;
        }

        #endregion

        #region Metodos Busca
        /// <summary>
        /// Recebe um id de funcionario e devolve o seu indice no array
        /// </summary>
        /// <param name="id">id do funcionario</param>
        /// <returns>int</returns>
        public int Procura(int id)
        {
            for (int i = 0; i < qtdFuncionarios; i++)
            {
                if (funcionarios[i].IdFuncionario == id) return i;
            }

            return -1;
        }

        #endregion

        #region Metodos Edicao
        /// <summary>
        /// Muda o nome do funcionario caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <param name="nome">Novo nome</param>
        /// <returns>bool</returns>
        public bool Editar(int id, string nome)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                funcionarios[indice].Nome = nome;
                return true;
            }
            return false;
        }
        /// <summary>
        /// Muda a id do funcionario caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <param name="newId">Novo id</param>
        /// <returns></returns>
        public bool Editar(int id, int newId)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                funcionarios[indice].IdFuncionario = newId;
                return true;
            }
            return false;
        }
        /// <summary>
        /// Muda a data de admissão do funcionario na empresa caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <param name="data">Nova data</param>
        /// <returns>bool</returns>
        public bool Editar(int id, DateTime data)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                funcionarios[indice].DataAdmissao = data;
                return true;
            }
            return false;
        }
        /// <summary>
        /// Muda o estado do funcionario na empresa caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <returns>bool</returns>
        public bool Remove(int id)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                funcionarios[indice].Estado = false;
                return true;
            }
            return false;
        }

        #endregion

        #region Metodos Listagem
        /// <summary>
        /// Mostra todos os Funcionarios pertencentes a lista
        /// </summary>
        /// <returns>string</returns>
        public string ListarFuncionarios()
        {
            string txt = "";
            for (int i = 0; i < qtdFuncionarios; i++)
            {
                //if(funcionarios[i].Estado)
                txt += funcionarios[i].MostraDados() + "\n";
            }
            return txt;
        }

        #endregion

        #endregion

    }
}
