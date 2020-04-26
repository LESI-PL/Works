//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos </author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
//-----------------------------------------------------------------------

namespace Auditorias
{
    /// <summary>
    /// 
    /// </summary>
    class Ocorrencia
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *
        /// *dataAdmissao - A data em que foi admitido na empresa
        /// *estado - Estado da pessoa na empresa ( Se ainda trabalha para a empresa ou não)
        /// </summary>
        int codAuditoria;
        int codVulnerabilidade;
        int codEquipamento;
        bool estado;

        #endregion

        #region Construtor
        public Ocorrencia()
        {

        }

        public Ocorrencia(int codAuditoria, int codVulnerabilidade, int codEquipamento)
        {
            this.codAuditoria = codAuditoria;
            this.codVulnerabilidade = codVulnerabilidade;
            this.codEquipamento = codEquipamento;
            estado = true;
        }
        #endregion

        #region Propriedades
        public int CodAuditoria
        {
            get { return codAuditoria; }
            set { codAuditoria = value; }
        }
        public int CodVulnerabilidade
        {
            get { return codVulnerabilidade; }
            set { codVulnerabilidade = value; }
        }
        public int CodEquipamento
        {
            get { return codEquipamento; }
            set { codEquipamento = value; }
        }
        public bool Estado
        {
            get { return estado; }
            set { estado = value; }
        }
        #endregion

        #region Metodos
        public override string ToString()
        {
            return base.ToString();
        }
        #endregion

    }
}
