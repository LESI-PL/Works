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
    /// Esta classe representa uma instâcia de Auditorias
    /// </summary>
    class Auditoria
    {
        /*
         * Auditoria contém:
         *          - Codigo da Auditoria
         *          - Data da auditoria
         *          - Id Auditor (Id Funcionario)
         *          - Nome Auditor ( Nome Funcionario)
         *          - Funcionario que fez a auditoria
         *          - Quantidade de Ocorrencias
         */
        #region Atributos
        int codigoAuditoria;
        DateTime data;
        int idAuditor;
        string nomeAuditor;
        int qtdOcorrencias;
        //Ocorrencias ocorrencias;       Será implementado na versão 2.0


        #endregion

        #region Construtor
        public Auditoria()
        {

        }

        public Auditoria(DateTime dataAuditoria, int idAuditor, string nome)
        {
            //ocorrencias = new Ocorrencias();
            data = dataAuditoria;
            this.idAuditor = idAuditor;
            nomeAuditor = nome;
            qtdOcorrencias = 0;


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

        public int IdAuditor
        {
            get { return idAuditor; }
            set { idAuditor = value; }
        }

        public string NomeAuditor
        {
            get { return nomeAuditor; }
            set { nomeAuditor = value; }
        }

        public int QtdOcorrencias
        {
            get { return qtdOcorrencias; }
            set { qtdOcorrencias = value; }
        }
        #endregion

        #region Metodos


        public override string ToString()
        {
            string texto = "";
            texto += "Codigo Auditoria" + CodigoAuditoria
                    + "Nome auditor:" + NomeAuditor
                    + "Data:" + Data + "\n";

            return texto;
        }
        #endregion

    }
}
