//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>

using Pessoas;
using System;
using System.Collections.Generic;

namespace Auditorias
{
    /// <summary>
    /// 
    /// </summary>
    class Auditoria
    {
        /*
         * Auditoria contém:
         *          - Codigo da Auditoria
         *          - Data da auditoria
         *          - Funcionario que fez a auditoria
         *          - Quantidade de vulnerabilidades
         *          - Lista das vulnerabilidades
         */
        #region Atributos
        int codigoAuditoria;
        DateTime data;
        Funcionario auditor;
        int qtdVulnerablidades;
        List<Vulnerabilidade> vulnerabilidades;


        #endregion

        #region Construtor
        public Auditoria()
        {

        }

        public Auditoria(int codigo, DateTime dataAuditoria, Funcionario funcionario)
        {
            codigoAuditoria = codigo;
            data = dataAuditoria;
            auditor = funcionario;
            qtdVulnerablidades = 0;
            vulnerabilidades = new List<Vulnerabilidade>();
            
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

        public Funcionario Auditor
        {
            get { return auditor; }
            set { auditor = value; }
        }
        
        #endregion

        #region Metodos
        public bool InserirVulnerabilidade(Vulnerabilidade vulnerabilidade)
        {
            qtdVulnerablidades++;
            vulnerabilidades.Add(vulnerabilidade);
            return true;
        }
        public bool InserirVulnerabilidades(List<Vulnerabilidade> vulnerabilidades)
        {
            qtdVulnerablidades += vulnerabilidades.Count;
            this.vulnerabilidades = vulnerabilidades;
            return true;
        }
        public override string ToString()
        {
            string texto = "";
            texto += "Nome: " + auditor.Nome + "\nB.I: " + auditor.Bi + "\n\n"+vulnerabilidades[0].Descricao;

            return texto;
        }
        #endregion

    }
}
