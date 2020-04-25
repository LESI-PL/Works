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

namespace Auditorias
{
    /// <summary>
    /// Esta Classe contém todos os menus existentes no programa
    /// </summary>
    static class Menus
    {
        #region Menu Principal
        /// <summary>
        /// <code> MenuPrincipal </code>
        /// Descricao: Este metodo mostra o menu principal e aguarda o input de escolha do utilizador, 
        ///            depois de recebido o input devolve o char referente a este input
        /// <code>Return: char </code>
        /// </summary>
        /// <return>char</return>
        public static char MenuPrincipal()
        {
            Console.Clear();
            Console.WriteLine("             Gestor De Auditorias\n\n");
            Console.WriteLine("1-Gerir Colaboradores          2-Gerir Equipamentos");
            Console.WriteLine("3-Gerir Vulnerabilidades       4-Gerir Auditorias");
            Console.WriteLine("                  S - Sair");
            return Console.ReadKey().KeyChar;
        }
        #endregion


        #region Menu Auditorias
        /// <summary>
        /// <code> MenuAuditoria </code>
        /// Descricao: Este metodo mostra o menu de gestão de auditorias e aguarda o input de escolha do utilizador, 
        ///            depois de recebido o input devolve o char referente a este input
        /// <code>Return: char </code>
        /// </summary>
        /// <return>char</return>
        public static char MenuAuditoria()
        {
            Console.Clear();
            Console.WriteLine("            Gestão de Auditorias\n\n");
            Console.WriteLine("1-Nova Auditoria          2-Remover Auditoria");
            Console.WriteLine("3-Editar Auditoria        4-Listar Auditorias");
            Console.WriteLine("                  S - Sair");
            return Console.ReadKey().KeyChar;
        }
        #endregion


        #region Menu Funcionarios
        /// <summary>
        /// <code> MenuFuncionario </code>
        /// Descricao: Este metodo mostra o menu de gestão de funcionarios e aguarda o input de escolha do utilizador, 
        ///            depois de recebido o input devolve o char referente a este input
        /// <code>Return: char </code>
        /// </summary>
        /// <return>char</return>
        public static char MenuFuncionario()
        {
            Console.Clear();
            Console.WriteLine("            Gestão de  Funcionarios\n\n");
            Console.WriteLine("1-Novo Funcionario          2-Remover Funcionario");
            Console.WriteLine("3-Editar Funcionario        4-Listar Funcionarios");
            Console.WriteLine("                  S - Sair");
            return Console.ReadKey().KeyChar;
        }
        #endregion


        #region Menu Equipamentos
        /// <summary>
        /// <code> MenuEquipamentos </code>
        /// Descricao: Este metodo mostra o menu de gestão de equipamentos e aguarda o input de escolha do utilizador, 
        ///            depois de recebido o input devolve o char referente a este input
        /// <code>Return: char </code>
        /// </summary>
        /// <return>char</return>
        public static char MenuEquipamentos()
        {
            Console.Clear();
            Console.WriteLine("            Gestão de  Equipamentos\n\n");
            Console.WriteLine("1-Novo Equipamentos          2-Remover Equipamentos");
            Console.WriteLine("3-Editar Equipamentos        4-Listar Equipamentos");
            Console.WriteLine("                  S - Sair");
            return Console.ReadKey().KeyChar;
        }
        #endregion


        #region Menu Vulnerabilidades
        /// <summary>
        /// <code> MenuVulnerabilidades </code>
        /// Descricao: Este metodo mostra o menu de gestão de vulnerabilidades e aguarda o input de escolha do utilizador, 
        ///           depois de recebido o input devolve o char referente a este input
        /// <code>Return: char </code>
        /// </summary>
        /// <return>char</return>
        public static char MenuVulnerabilidades()
        {
            Console.Clear();
            Console.WriteLine("            Gestão de  Vulnerabilidades\n\n");
            Console.WriteLine("1-Nova Vulnerabilidade          2-Remover Vulnerabilidade");
            Console.WriteLine("3-Editar Vulnerabilidade        4-Listar Vulnerabilidades");
            Console.WriteLine("                  S - Sair");
            return Console.ReadKey().KeyChar;
        }
        #endregion
    }
}
