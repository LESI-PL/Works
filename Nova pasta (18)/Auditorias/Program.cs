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
            int id=5; // Id para procura de qualquer objeto **TESTES**

            /**
             * Criação de instancias das classes Funcionario e Funcionarios
             */
            #region Criação Dados
            Funcionario f1 = new Funcionario("Abf2886392", "José António", 123423, "Eng.Informático", new DateTime(2001, 08, 18));
            f1.Morada = "Rua dos Periquitos Nº333";
            f1.Contacto = 92547893;
            Funcionario f2 = new Funcionario("QUSD7282", "Pedro Henriques", 1234231, "Técnico Informático", new DateTime(2005, 07, 28));
            Equipamento e1 = new Equipamento("Laptop", "HP", "Omen", new DateTime(2019, 02, 12));
            Equipamento e2 = new Equipamento("Laptop", "Lenovo", "IdeaPad", new DateTime(2019, 9, 20));
            Vulnerabilidade v1 = new Vulnerabilidade("Virus", "Elevado");
            Vulnerabilidade v2 = new Vulnerabilidade("Trojan", "Elevado");
            Ocorrencia o1 = new Ocorrencia(v1.Codigo, e1.Codigo);
            Ocorrencia o2 = new Ocorrencia(v2.Codigo, e2.Codigo);
 
            Auditoria a1 = new Auditoria(new DateTime(2009, 8, 20), f1.IdFuncionario, f1.Nome);
            Auditoria a2 = new Auditoria(new DateTime(2020, 5, 15), f2.IdFuncionario, f2.Nome);
            Funcionarios listaFuncionarios = new Funcionarios();
            Equipamentos listaEquipamentos = new Equipamentos();
            Vulnerabilidades listaVulnerabilidades = new Vulnerabilidades();

            #endregion

            #region Inserção de elementos nas respectivas listas
            listaFuncionarios.InserirFuncionario(f1);           // Insere 1 funcionario na lista de funcionarios
            listaEquipamentos.InserirEquipamento(e1);           // Insere 1 equipamento na lista de equipamentos
            listaVulnerabilidades.InserirVulnerabilidade(v1);    // Insere 1 vulnerabilidade na lista de vulnerabilidades
            #endregion


            #region FUNCIONARIOS
            /**
             * Tenta remover Funcionario se o Id estiver certo
             * Tenta inserir Funcionario se o Nº Contribuinte for diferente
             * Listagem de dados
             */
            #region Insere Funcionario  **TESTADO**
            //Console.WriteLine("\n\nAntes:\n\n" + listaFuncionarios.ListarFuncionarios()); Console.ReadKey();
            //listaFuncionarios.InserirFuncionario(f2);
            //Console.WriteLine("Depois:\n" + listaFuncionarios.ListarFuncionarios());
            #endregion

            #region Remove Funcionario  **TESTADO**
            //Console.WriteLine("Digite um ID");
            //try
            //{
            //    if (listaFuncionarios.VerificaId(Console.ReadLine(), out id))
            //    {
            //        if (listaFuncionarios.Procura(id) != -1) { listaFuncionarios.Remove(id); }
            //        else { Console.WriteLine("Este ID não existe!\n\n"); }

            //    }
            //    else { Console.WriteLine("Valores incorretos!"); }
            //    Console.WriteLine(listaFuncionarios.ListarFuncionarios());
            //}
            //catch (ValoresExceptions e)
            //{
            //    throw new ValoresExceptions();
            //}
            //catch (Exception e)
            //{
            //    throw new Exception();
            //}
            #endregion

            #region Edita Dados Funcionario  **TESTADO**
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

            #region Mostra Funcionarios, Qtd Funcionarios Total  **TESTADO**

            //Console.WriteLine("Mostra Essencial Empresa:\n{0}\n\n", listaFuncionarios.ListarFuncionarios());
            //Console.WriteLine("Mostra Dados Pessoais:\n\n{0}\n\n", listaFuncionarios.ListarFuncionariosDadosPessoais());
            //Console.WriteLine("Na empresa há: {0} funcionario(s)", listaFuncionarios.QtdFuncionario);
            //Console.WriteLine("Funcionario Completo:\n {0}", listaFuncionarios.ListarFuncionariosCompleto());
            #endregion
            #endregion


            #region EQUIPAMENTOS
            /**
             * Tenta remover um equipamento se o ID estiver certo
             * Tenta inserir um equipamento se o ID for diferente
             * Listagem de dados
             */
            #region Insere Equipamento **TESTADO**

            //Console.WriteLine("Antes:\n{0}", listaEquipamentos.ListarEquipamentos()); Console.ReadKey();
            //if (listaEquipamentos.InserirEquipamento(e2)) { Console.WriteLine("Equipamento inserido!"); }
            //else { Console.WriteLine("Equipamento já existe no sistema!"); }
            //Console.Clear();
            //Console.WriteLine("\n\nDepois:\n{0}", listaEquipamentos.ListarEquipamentos());

            #endregion

            #region Remove Equipamento **TESTADO**
            //Console.WriteLine("Digite um ID");
            //try
            //{
            //    if (listaEquipamentos.VerificaId(Console.ReadLine(), out id)) { listaEquipamentos.Remove(id); }
            //    else { Console.WriteLine("Este ID não existe!"); }
            //}
            //catch (ValoresExceptions e)
            //{
            //    throw new ValoresExceptions();
            //}
            //catch (Exception e)
            //{
            //    throw new Exception();
            //}
            //Console.WriteLine("Depois:\n\n"+listaEquipamentos.ListarEquipamentos());
            #endregion

            #region Edita Dados Equipamento **TESTADO**
            #region Edita Marca
            //Console.WriteLine("Digite um ID:");

            //try
            //{
            //    if (listaEquipamentos.VerificaId(Console.ReadLine(), out id)) { listaEquipamentos.EditarMarca(id, "Asus"); }
            //    else { Console.WriteLine("Equipamento não encontrado!"); }
            //    Console.Clear();
            //    Console.WriteLine(listaEquipamentos.ShowEquipment(id)); Console.ReadKey();
            //}
            //catch (ValoresExceptions ee)
            //{
            //    Console.WriteLine(ee);
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e);
            //}
            //Console.WriteLine(listaEquipamentos.ListarEquipamentos());
            #endregion
            #region Edita Modelo
            //Console.WriteLine("Digite um ID:");

            //try
            //{
            //    if (listaEquipamentos.VerificaId(Console.ReadLine(), out id)) { listaEquipamentos.EditarModelo(id, "XPTO2020"); }
            //    else { Console.WriteLine("Equipamento não encontrado!"); }
            //    Console.Clear();
            //    Console.WriteLine(listaEquipamentos.ShowEquipment(id)); Console.ReadKey();
            //}
            //catch (ValoresExceptions ee)
            //{
            //    Console.WriteLine(ee);
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e);
            //}
            //Console.WriteLine(listaEquipamentos.ListarEquipamentos());
            #endregion
            #region Edita Data Aquisição
            //Console.WriteLine("Digite um ID:");

            //try
            //{
            //    if (listaEquipamentos.VerificaId(Console.ReadLine(), out id)) { listaEquipamentos.EditarDataAquisicao(id, new DateTime(2001,8,8)); }
            //    else { Console.WriteLine("Equipamento não encontrado!"); }
            //    Console.Clear();
            //    Console.WriteLine(listaEquipamentos.ShowEquipment(id));
            //}
            //catch (ValoresExceptions ee)
            //{
            //    Console.WriteLine(ee);
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e);
            //}
            ////Console.WriteLine(listaEquipamentos.ListarEquipamentos());
            #endregion
            #endregion

            #region Mostra Equipamentos, Qtd Total **TESTADO**
            //Console.WriteLine("Usando o Metodo da Classe Equipamento:\n{0}\n",e1.MostraDados());
            //Console.WriteLine("Usando o Metodo de listagem geral da Classe Equipamentos:\n{0}\n",listaEquipamentos.ListarEquipamentos());
            //Console.WriteLine("Insira o ID do Equipamento:");
            //if(listaEquipamentos.VerificaId(Console.ReadLine(),out id)) {
            //Console.WriteLine("Usando o Metodo de busca da Classe Equipamento:\n{0}\n",listaEquipamentos.ShowEquipment(id)); 
            //}
            //else { Console.WriteLine("Equipamento não existe!"); }
            //Console.WriteLine("Total de equipamentos: {0}", listaEquipamentos.QtdEquipamentos);
            #endregion
            #endregion


            #region VULNERABILIDADES
            /**
             * Tenta remover uma vulnerabilidade se o ID estiver certo
             * Tenta inserir uma vulnerabilidade se o ID for diferente
             * Listagem de dados
             */
            #region Insere uma vulnerabilidade **TESTADO**
            //Console.WriteLine("\n\nAntes:\n\n" + listaVulnerabilidades.ListarVulnerabilidades()); Console.ReadKey();
            //listaVulnerabilidades.InserirVulnerabilidade(v2);
            //Console.WriteLine("Depois:\n" + listaVulnerabilidades.ListarVulnerabilidades());
            #endregion

            #region Remove uma vulnerabilidade **TESTADO**
            //Console.WriteLine("Digite um ID");
            //try
            //{
            //    if (listaVulnerabilidades.VerificaId(Console.ReadLine(), out id))
            //    {
            //        if (listaVulnerabilidades.Procura(id) != -1) { listaVulnerabilidades.Remove(id); }
            //        else { Console.WriteLine("Este ID não existe!\n\n"); }

            //    }
            //    else { Console.WriteLine("Valores incorretos!"); }
            //    Console.WriteLine(listaVulnerabilidades.ListarVulnerabilidades());
            //}
            //catch (ValoresExceptions ee)
            //{
            //    throw new ValoresExceptions(ee.Message);
            //}
            //catch (Exception e)
            //{
            //    throw new Exception(e.Message);
            //}
            #endregion

            #region Edita vulnerabilidade **TESTADO**

            #region Edita Descrição da Vulnerabilidade
            //Console.WriteLine("Digite um ID");

            //try
            //{
            //    if (listaVulnerabilidades.VerificaId(Console.ReadLine(), out id)) { listaVulnerabilidades.EditarDescricao(id, "Maquina Lenta"); }
            //    else { Console.WriteLine("Vulnerabilidade não encontrada!"); }

            //}
            //catch (ValoresExceptions ee)
            //{
            //    Console.WriteLine(ee);
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e);
            //}
            //Console.WriteLine(listaVulnerabilidades.ListarVulnerabilidades());
            #endregion

            #region Edita Imapcto da Vulnerabilidade
            //Console.WriteLine("Digite um ID");

            //try
            //{
            //if (listaVulnerabilidades.VerificaId(Console.ReadLine(), out id)) { listaVulnerabilidades.EditarImpacto(id, "Leve"); }
            //else { Console.WriteLine("Vulnerabilidade não encontrada!"); }

            //}
            //catch (ValoresExceptions ee)
            //{
            //    Console.WriteLine(ee);
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e);
            //}
            //Console.WriteLine(listaVulnerabilidades.ListarVulnerabilidades());
            #endregion

            #endregion

            #region Mostra vulnerabilidades, Qtd Total **TESTADO**
            //Console.WriteLine("Usando o Metodo da Classe Vulnerabilidade:\n\n\n{0}\n", v1.MostraVulnerabilidade());
            //Console.WriteLine("Usando o Metodo de listagem geral da Classe Vulnerabilidades:\n{0}\n", listaVulnerabilidades.ListarVulnerabilidades());
            //Console.WriteLine("Insira o ID da Vulnerabilidade:");
            //if (listaVulnerabilidades.VerificaId(Console.ReadLine(), out id))
            //{
            //    if(listaVulnerabilidades.Procura(id) != -1)
            //    {
            //        Console.WriteLine("Usando o Metodo de busca da Classe Vulnerabilidade:\n\n\n{0}\n", listaVulnerabilidades.MostrarDados(id));
            //    }
            //    else
            //    {
            //        Console.WriteLine("Equipamento não existe!");
            //    }

            //}
            //else { Console.WriteLine("Equipamento não existe!"); }
            //Console.WriteLine("Total de vulnerabilidades: {0}", listaVulnerabilidades.QtdVulnerabilidades);

            #endregion

            #endregion

            #region AUDITORIAS

            #endregion

            Console.WriteLine("\n\nFIM!");
            Console.ReadKey();
        }

    }
}
