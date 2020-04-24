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
        ///Inicializa uma nova instancia de Funcionarios</summary>
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
        public bool InserirFuncionario(Funcionario funcionario)
        {
            qtdFuncionarios++;
            funcionario.IdFuncionario = qtdFuncionarios;
            funcionarios.Add(funcionario);
            return true;
        }

        public int Procura(int id)
        {
            for (int i = 0; i < qtdFuncionarios; i++)
            {
                if (funcionarios[i].IdFuncionario == id) return i;
            }

            return -1;
        }

        public bool Editar(int id, Funcionario func)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                func.IdFuncionario = funcionarios[indice].IdFuncionario;
                funcionarios[indice] = func;
                return true;
            }
            return false;
        }

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

    }
}
