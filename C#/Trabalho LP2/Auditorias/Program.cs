using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Pessoas; // Bliblioteca Externa

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
            Funcionarios lista = new Funcionarios();
            //Inserção de funcionarios na lista
            lista.InserirFuncionario(f1);
            lista.InserirFuncionario(f2);

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
                                    lista.InserirFuncionario(Funcionario.NovoFuncionario());
                                    Console.ReadKey();
                                    break;
                                case '2': // Remover Funcionario
                                    Console.Clear();
                                    Console.WriteLine("Id do funcionario:");
                                    id = Convert.ToInt32(Console.ReadLine());
                                    if (lista.Procura(id) >= 0)
                                    {
                                        lista.Remove(id);
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
                                    if (lista.Procura(id) >= 0)
                                    {
                                        lista.Editar(id, Funcionario.NovoFuncionario());
                                    }
                                    else
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Este Funcionario não existe!");
                                        Console.ReadKey();
                                    }
                                    break;
                                case '4':
                                    Console.Clear();
                                    Console.WriteLine(lista.ListarFuncionarios());
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
                        break;
                    #endregion

                    #region Gerir Vulnerabilidades
                    case '3':
                        //Gerir Vulnerabilidades
                        Menus.MenuVulnerabilidades();
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
