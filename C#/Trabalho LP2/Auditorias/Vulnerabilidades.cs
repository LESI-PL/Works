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
    class Vulnerabilidades
    {

        /*
         * Vulnerabilidades Contém:
         *      - Uma lista de vulnerabilidades
         *      - Quantidade de vulnerabilidades
         */
        #region Atributos
        List<Vulnerabilidade> vulnerabilidades;
        int qtdVulnerabilidades;
        #endregion

        #region Construtor
        public Vulnerabilidades()
        {
            vulnerabilidades = new List<Vulnerabilidade>();
            qtdVulnerabilidades = 0;
        }
        #endregion

        #region Propriedades
        public List<Vulnerabilidade> ListaVulnerabilidades
        {
            get { return vulnerabilidades; }
        }
        #endregion

        #region Metodos
        public bool InsereVulnerabilidade(Vulnerabilidade vulnerabilidade)
        {
            qtdVulnerabilidades++;
            vulnerabilidades.Add(vulnerabilidade);
            return true;
        }

        public string MostrarDados()
        {
            string texto = "";
            for (int i = 0; i < qtdVulnerabilidades; i++)
            {
                texto += "Codigo: " + vulnerabilidades[i].Codigo + "\n\n";

            }


            return texto;
        }
        #endregion
    }
}
