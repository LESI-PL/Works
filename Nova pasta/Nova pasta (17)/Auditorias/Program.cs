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
using MinhasExceptionsLib;


namespace Auditorias
{
    class Program
    {
        static void Main(string[] args)
        {
            int id=5; // Id para procura de qualquer objeto





            /**
             * Criação de instancias das classes Funcionario e Funcionarios
             */
            #region Criação Dados
            Funcionario f1 = new Funcionario("Abf2886392", "José António", 123423, "Eng.Informático", new DateTime(2001, 08, 18));
            Funcionario f2 = new Funcionario("QUSD7282", "Pedro Henriques", 1234231, "Técnico Informático", new DateTime(2005, 07, 28));
            Equipamento e1 = new Equipamento("Laptop", "HP", "Omen", new DateTime(2019, 02, 12));
            Equipamento e2 = new Equipamento("Laptop", "Lenovo", "IdeaPad", new DateTime(2019, 9, 20));
            Vulnerabilidade v1 = new Vulnerabilidade(1, "Virus", "Elevado");
            Vulnerabilidade v2 = new Vulnerabilidade(2, "Trojan", "Elevado");
            Funcionarios listaFuncionarios = new Funcionarios();
            Equipamentos listaEquipamentos = new Equipamentos();
            Vulnerabilidades listaVulnerabilidades = new Vulnerabilidades();
            #endregion

            #region Inserção de elementos nas respectivas listas
            listaFuncionarios.InserirFuncionario(f1);           // Insere 1 funcionario na lista de funcionarios
            listaEquipamentos.InserirEquipamento(e1);           // Insere 1 equipamento na lista de equipamentos
            listaVulnerabilidades.InsereVulnerabilidade(v1);    // Insere 1 vulnerabilidade na lista de vulnerabilidades
            #endregion

            /**
             * Tenta remover Funcionario se o Id estiver certo
             * Tenta inserir Funcionario se o Nº Contribuinte for diferente
             */
            #region Insere Funcionario
            //Console.WriteLine("\n\nAntes:\n\n" + listaFuncionarios.ListarFuncionarios()); Console.ReadKey();
            //listaFuncionarios.InserirFuncionario(f2);
            //Console.WriteLine("Depois:\n" + listaFuncionarios.ListarFuncionarios());
            #endregion

            #region Remove Funcionario
            //Console.WriteLine("Digite um ID");
            //try
            //{                
            //    if (listaFuncionarios.VerificaId(Console.ReadLine(), out id)) { listaFuncionarios.Remove(id); }
            //    else { Console.WriteLine("Este ID não existe!"); }
            //}catch(ValoresExceptions e)
            //{
            //    throw new ValoresExceptions();
            //}catch(Exception e)
            //{
            //    throw new Exception();
            //}
            #endregion

            #region Edita Dados Funcionario
            //Console.WriteLine("Digite um ID");

            //try
            //{
            //    if (listaFuncionarios.VerificaId(Console.ReadLine(), out id)) { listaFuncionarios.Editar(id, "Pedrinho"); }
            //    else { Console.WriteLine("Funcionario não encontrado!"); }

            //}catch(ValoresExceptions ee)
            //{
            //    Console.WriteLine(ee);
            //}catch(Exception e)
            //{
            //    Console.WriteLine(e);
            //}
            //Console.WriteLine(listaFuncionarios.ListarFuncionarios());
            #endregion

            #region Mostra Funcionarios, Qtd Funcionarios Total
            //Console.WriteLine(listaFuncionarios.ListarFuncionarios());
            //Console.WriteLine("Na empresa há: {0} funcionario(s)",listaFuncionarios.QtdFuncionario);
            #endregion


            /**
             * Tenta remover um equipamento se o ID estiver certo
             * Tenta inserir um equipamento se o ID for diferente
             */
            #region Insere Equipamento
            Console.WriteLine("\n\nAntes:\n\n" + listaFuncionarios.ListarFuncionarios()); Console.ReadKey();
            if (listaEquipamentos.Procura(e2.Codigo) != -1) { listaEquipamentos.InserirEquipamento(e2); }
            else { Console.WriteLine("Este equipamento já existe no sistema!"); }
            
            #endregion
            Console.ReadKey();
        }

    }
}
