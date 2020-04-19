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

namespace Auditorias
{
    /// <summary>
    /// 
    /// </summary>
    class Auditoria
    {

        #region Atributos
        int codigoAuditoria;
        DateTime data;
        Funcionario[] auditores;
        int qtdAuditores;


        #endregion

        #region Construtor
        public Auditoria()
        {

        }

        public Auditoria(int codigo, DateTime dataAuditoria, int totalAuditores)
        {
            codigoAuditoria = codigo;
            data = dataAuditoria;
            auditores = new Funcionario[totalAuditores];
            qtdAuditores = 0;
        }
        #endregion

        #region Propriedades
        public int CodigoAuditoria
        {
            get { return codigoAuditoria; }
            set { codigoAuditoria = value; }
        }

        public DateTime Data
        {
            get { return data; }
            set { data = value; }
        }

        public int QtdAuditores
        {
            get { return qtdAuditores; }
        }
        #endregion

        #region Metodos
        public bool InserirFuncionario(Funcionario funcionario)
        {
            if(qtdAuditores == auditores.Length)
            {
                return false;
            }
            else
            {
                auditores[qtdAuditores] = funcionario;
                if(qtdAuditores < auditores.Length)
                {
                    qtdAuditores++;
                }
                
            }
            return true;
        }

        public override string ToString()
        {
            string texto = "";
            for(int i=0;i<qtdAuditores;i++)
            {
                texto += "Nome: " + auditores[i].Nome+"\nB.I: "+auditores[i].Bi+"\n\n";
            }
            return texto;
        }
        #endregion

    }
}
