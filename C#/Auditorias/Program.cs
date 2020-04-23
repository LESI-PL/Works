using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Auditorias
{
    class Program
    {
        static void Main(string[] args)
        {
            bool exit = false;
            char op,opFuncionarios;
            Menus menus = new Menus();
            Funcionarios lista = new Funcionarios();
            
            while(exit == false)
            {
                menus.MenuPrincipal(); /*Mostra o menu principal*/
                op = Console.ReadKey().KeyChar;
                switch (op)
                {
                    case '1':
                        /**/
                        menus.MenuAuditoria(); // Mostra o menu de gestão de auditorias
                        Console.ReadKey();
                        break;
                    case '2':
                        /**/
                        menus.MenuFuncionario(); // Mostra o menu de gestão de funcionarios
                        opFuncionarios = Console.ReadKey().KeyChar;
                        switch (opFuncionarios)
                        {
                            case '1':
                                Console.Clear();
                                Funcionario f = new Funcionario();
                                Console.WriteLine("Insira o nome: ");
                                f.Nome = Console.ReadLine();
                                f.IdFuncionario = lista.QtdFuncionario + 1;
                                lista.InserirFuncionario(f);
                                break;
                            case '4':
                                Console.Clear();
                                Console.WriteLine("" + lista.ToString());
                                break;
                        }
                        Console.ReadKey();
                        break;
                    case '3':
                        /**/
                        break;
                    case '4':
                        /**/
                        break;
                    case 's':
                    case 'S':
                        exit = true;
                        break;
                    default:
                        break;
                }
            }
        }

    }
}
