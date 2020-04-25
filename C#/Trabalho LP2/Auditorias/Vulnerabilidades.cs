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
using MinhasInterfaces;
namespace Auditorias
{
    /// <summary>
    /// 
    /// </summary>
    class Vulnerabilidades: IMetodosGenericos
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

        public bool Editar(int id, string nome)
        {
            throw new NotImplementedException();
        }

        public bool Editar(int id, int numero)
        {
            throw new NotImplementedException();
        }

        public bool Editar(int id, DateTime data)
        {
            throw new NotImplementedException();
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

        public int Procura(int id)
        {
            throw new System.NotImplementedException();
        }

        public bool Remove(int id)
        {
            throw new System.NotImplementedException();
        }
        #endregion
    }
}
