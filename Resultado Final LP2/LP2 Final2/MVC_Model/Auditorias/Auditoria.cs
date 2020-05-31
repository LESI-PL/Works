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

namespace MVC_Model
{
    /// <summary>
    /// Esta classe representa uma instâcia de Auditorias
    /// </summary>
    [Serializable]
    public class Auditoria
    {
        /*
         * Auditoria contém:
         *          - Codigo da Auditoria
         *          - Data da auditoria
         *          - Id Auditor (Id Funcionario)
         *          - Nome Auditor ( Nome Funcionario)
         *          - Quantidade de Ocorrencias
         *          - Lista de ocorrencias
         */
        #region Atributos
        int codigoAuditoria;
        DateTime data;
        int idAuditor;
        string nomeAuditor;
        int qtdOcorrencias;
        List<Ocorrencia> ocorrencias;
        //Ocorrencias ocorrencias;       Será implementado na versão 2.0


        #endregion

        #region Construtor
        public Auditoria()
        {

        }

        public Auditoria(DateTime dataAuditoria, int idAuditor)
        {
            data = dataAuditoria;
            this.idAuditor = idAuditor;
            qtdOcorrencias = 0;
            ocorrencias = new List<Ocorrencia>();
        }
        public Auditoria(DateTime dataAuditoria, int idAuditor, string nome, Ocorrencias ocorrencias)
        {
            data = dataAuditoria;
            this.idAuditor = idAuditor;
            nomeAuditor = nome;
            qtdOcorrencias = ocorrencias.QtdOcorrencias;
            this.ocorrencias = ocorrencias.ListOcorrencias;
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
        

        public List<Ocorrencia> Ocorrencias
        {
            get { return ocorrencias; }
            set { ocorrencias = value; }

        }
        #endregion

        #region Metodos
        /// <summary>
        /// Procura por um id, caso encontre devolve o indice e true, caso contrario devolve zero e false;
        /// </summary>
        /// <param name="id"></param>
        /// <param name="id2"></param>
        /// <returns></returns>
        public bool ProcuraOcorrencia(int id, out int id2)
        {
            for(int i = 0; i < qtdOcorrencias; i++)
            {
                if (id == ocorrencias[i].IdOcorrencia)
                {
                    id2 = i;
                    return true;
                }
            }
            id2 = 0;
            return false;            
        }

        public bool InserirOcorrencia(Ocorrencia ocorrencia)
        {
            foreach(Ocorrencia o in ocorrencias)
            {
                if (!ocorrencia.Equals(o))
                {
                    ocorrencias.Add(ocorrencia);
                    return true;
                }                
            }
            return false;
        }
        public bool RemoveOcorrencia(int id)
        {
            int indice;
            if(ProcuraOcorrencia(id,out indice))
            {
                ocorrencias[indice].Estado = false;
                return true;
            }
            return false;
        }

        public string MostraDados()
        {
            string texto = "";
            texto += "Codigo Auditoria" + CodigoAuditoria
                    + "\nNome auditor:" + NomeAuditor
                    + "\nData:" + Data + "\n";

            return texto;
        }
        public string MostraOcorrencias()
        {
            string txt = "";
            foreach(Ocorrencia o in ocorrencias)
            {
                txt += "Codigo Vulnerabilidade:"+o.CodVulnerabilidade
                      +"\nCodigo Equipamento:"+ o.CodEquipamento
                      +"\nEstado da Ocorrencia:"+o.Estado;                
            }

            return txt;
        }
        #endregion

    }
}
