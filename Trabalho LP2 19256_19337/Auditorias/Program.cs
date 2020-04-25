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
using Pessoas; // Blibliotecas Externas
using Aparelhos;
using Defeitos;


namespace Auditorias
{
    class Program
    {
        static void Main(string[] args)
        {
            bool exit = true;
            int id; // Id para procura de qualquer objeto





            /**
             * Criação de instancias das classes Funcionario e Funcionarios
             */

            Funcionario f1 = new Funcionario("Abf2886392", "José António", 123423, "Eng.Informático", new DateTime(2001, 08, 18));
            Funcionario f2 = new Funcionario("QUSD7282", "Pedro Henriques", 1878924, "Técnico Informático", new DateTime(2005, 07, 28));

            Equipamento e1 = new Equipamento("Laptop", "HP", "Omen", new DateTime(2019, 02, 12));
            Equipamento e2 = new Equipamento("Laptop", "Lenovo", "IdeaPad", new DateTime(2019, 9, 20));

            Vulnerabilidade v1 = new Vulnerabilidade(1, "Virus", "Elevado");
            Vulnerabilidade v2 = new Vulnerabilidade(2, "Trojan", "Elevado");



            Funcionarios listaFuncionarios = new Funcionarios();

            Equipamentos listaEquipamnetos = new Equipamentos();

            Vulnerabilidades listaVulnerabilidades = new Vulnerabilidades();

            //Inserção de elementos nas respectivas listas
            listaFuncionarios.InserirFuncionario(f1);
            listaEquipamnetos.InserirEquipamento(e1);
            listaVulnerabilidades.InsereVulnerabilidade(v1);


            while (exit)
            {

                switch (Menus.MenuPrincipal())/*Mostra o menu principal*/
                {
                    #region Gerir Colaboradores
                    case '1':
                        // Gerir Colaboradores
                        while (exit)
                        {
                            switch (Menus.MenuFuncionario())
                            {
                                case '1'://Inserir Funcionario
                                    Console.Clear();
                                    listaFuncionarios.InserirFuncionario(f2);
                                    break;
                                case '2': // Remover Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Id do funcionario:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (listaFuncionarios.Procura(id) >= 0)
                                    {
                                        listaFuncionarios.Remove(id);
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Este Funcionario não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '3':// Editar Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Id do funcionario:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (listaFuncionarios.Procura(id) >= 0)
                                    {
                                        listaFuncionarios.Editar(id, 4);
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Este Funcionario não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '4':// Listar
                                    Console.Clear();
                                    Console.WriteLine(listaFuncionarios.ListarFuncionarios());
                                    Console.ReadKey();
                                    break;
                                case 's':
                                case 'S':
                                    exit = false;
                                    break;
                            }
                        }
                        exit = true;
                        break;
                    #endregion

                    #region Gerir Equipamentos
                    case '2':
                        // Gerir Equipamentos
                        Menus.MenuEquipamentos();
                        while (exit)
                        {
                            switch (Menus.MenuFuncionario())
                            {
                                case '1'://Inserir Funcionario
                                    Console.Clear();
                                    listaEquipamnetos.InserirEquipamento(e2);
                                    break;
                                case '2': // Remover Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Id do funcionario:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (listaEquipamnetos.Procura(id) >= 0)
                                    {
                                        listaEquipamnetos.Remove(id);
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Este Equipamento não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '3':// Editar Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Codigo do Equipamento:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (listaEquipamnetos.Procura(id) >= 0)
                                    {
                                        listaEquipamnetos.Editar(id, 4);
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Este Equipamento não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '4':// Listar
                                    Console.Clear();
                                    Console.WriteLine(listaEquipamnetos.ListarEquipamentos());
                                    Console.ReadKey();
                                    break;
                                case 's':
                                case 'S':
                                    exit = false;
                                    break;
                            }
                        }
                        exit = true;
                        break;
                    #endregion

                    #region Gerir Vulnerabilidades
                    case '3':
                        //Gerir Vulnerabilidades
                        Menus.MenuVulnerabilidades();
                        while (exit)
                        {
                            switch (Menus.MenuFuncionario())
                            {
                                case '1'://Inserir Funcionario
                                    Console.Clear();
                                    listaVulnerabilidades.InsereVulnerabilidade(v2);
                                    break;
                                case '2': // Remover Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Codigo da Vulnerabilidade:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (listaVulnerabilidades.Procura(id) >= 0)
                                    {
                                        listaVulnerabilidades.Remove(id);
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Esta Vulnerabilidade não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '3':// Editar Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Codigo da Vulnerabilidade:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (listaVulnerabilidades.Procura(id) >= 0)
                                    {
                                        listaVulnerabilidades.Editar(id, 4);
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Esta Vulnerabilidade não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '4':// Listar
                                    Console.Clear();
                                    Console.WriteLine(listaVulnerabilidades.MostrarDados());
                                    Console.ReadKey();
                                    break;
                                case 's':
                                case 'S':
                                    exit = false;
                                    break;
                            }
                        }
                        exit = true;
                        break;
                    #endregion

                    #region Gerir Auditorias
                    case '4':
                        //Gerir Auditorias
                        Menus.MenuAuditoria();
                        break;
                    #endregion

                    #region Sair do programa
                    case 's':
                    case 'S':
                        exit = false;
                        break;
                    default:
                        break;
                        #endregion
                }
            }
        }

    }
}
