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
    /// Esta classe representa uma instâcia de ocorrencia 
    /// </summary>
    class Ocorrencia
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *codAuditoria - Codigo de identificação da Auditoria na empresa
        /// *codVulnerabilidade - Codigo de identificação da Vulnerabilidade 
        /// *codEquipamento - Codigo de identificação do Equipamento
        /// *estado - Estado da Vulnerabildade 
        /// </summary>
        int codAuditoria;
        int codVulnerabilidade;
        int codEquipamento;
        bool estado;

        #endregion

        #region Construtor
        ///<summary>
        ///Inicializa uma nova instancia de Ocorrencia</summary>
        public Ocorrencia()
        {

        }

        ///<summary>
        ///Inicializa uma nova instancia de Ocorrencia com parametros</summary>
        public Ocorrencia(int codAuditoria, int codVulnerabilidade, int codEquipamento)
        {
            this.codAuditoria = codAuditoria;
            this.codVulnerabilidade = codVulnerabilidade;
            this.codEquipamento = codEquipamento;
            estado = true;
        }
        #endregion

        #region Propriedades
        /// <summary>
        /// Obtém ou ajusta o componente do codigo da auditoria
        /// <code>type: int</code>
        /// </summary>
        public int CodAuditoria
        {
            get { return codAuditoria; }
            set { codAuditoria = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente do codigo da vulnerabilidade
        /// <code>type: int</code>
        /// </summary>
        public int CodVulnerabilidade
        {
            get { return codVulnerabilidade; }
            set { codVulnerabilidade = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente do codigo do equipamento
        /// <code>type: int</code>
        /// </summary>
        public int CodEquipamento
        {
            get { return codEquipamento; }
            set { codEquipamento = value; }
        }
        /// <summary>
        /// Obtém ou ajusta o componente estado da vulnerabilidade
        /// <code>type: bool</code>
        /// </summary>
        public bool Estado
        {
            get { return estado; }
            set { estado = value; }
        }
        #endregion

        #region Metodos
        /// <summary>
        /// Metodo para listar a  ocorrencias
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return base.ToString();
        }
        #endregion

    }
}
