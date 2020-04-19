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
            
            Funcionario f = new Funcionario("2534AE3", "Antonio Pereira", 24875986, 1, "Tecnico Informatica", new DateTime(2200, 8, 21));
            Funcionario f2 = new Funcionario("564EZ64", "Pedrinho Pereira", 24875986, 1, "Engenheiro Informatico", new DateTime(2001, 12, 20));
            Funcionarios fs = new Funcionarios();

            Auditoria a = new Auditoria(1, new DateTime(2019, 8, 19),3);
            
            a.InserirFuncionario(f);
            a.InserirFuncionario(f2);
            a.InserirFuncionario(new Funcionario("fdtfd", "Malaquias", 23453, 123, "Paneleiro", new DateTime(2019, 9, 27)));
            //Console.WriteLine("Qtd Auditores:" + a.QtdAuditores);
            Console.WriteLine("" + a.ToString());

            //Console.WriteLine("Nome:" + f.Nome +"\nB.I:"+f.Bi +"\nEstado:" + f.CheckEstado()+"\n");
            Console.ReadKey();

        }
    }
}
