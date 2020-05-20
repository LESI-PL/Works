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
    class Ocorrencias
    {

        #region Atributos
        List<Ocorrencia> ocorrencias;
        int qtdOcorrencias;
        #endregion

        #region Construtor
        public Ocorrencias()
        {
            ocorrencias = new List<Ocorrencia>();
            qtdOcorrencias = 0;
        }
        
        #endregion

        #region Propriedades
        public List<Ocorrencia> ListOcorrencias
        {
            get { return ocorrencias; }
        }

        public int QtdOcorrencias
        {
            get { return qtdOcorrencias; }
        }
        #endregion

        #region Metodos
        public bool ProcuraOcorrencia(int id, out int id2)
        {
            id2 = 0;
            for (int i = 0; i < qtdOcorrencias; i++)
            {
                if(id == ocorrencias[i].IdOcorrencia)
                {
                    id2 = i;
                    return true;
                }
            }
            return false;
        }

        public bool InsertOcorrencia(Ocorrencia ocorrencia, out string message)
        {
            message = "Não foi possivel fazer a inserção";
            foreach(Ocorrencia o in ocorrencias)
            {
                if(ocorrencia.CodEquipamento == o.CodEquipamento && ocorrencia.CodVulnerabilidade == o.CodVulnerabilidade && o.Estado == false)
                {
                    o.Estado = true;
                    message = "Estado alterado!";
                    return true;
                }
                if (!ocorrencia.Equals(o))
                {
                    ocorrencias.Add(ocorrencia);
                    message = "Ocorrencia Inserida!";
                    return true;
                }
            }
            return false;
        }
        #endregion

    }
}
