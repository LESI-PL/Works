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
namespace Defeitos
{
    /// <summary>
    /// Esta Classe representa uma instancia de Vulnerabilidades 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>
    public class Vulnerabilidades: IMetodosGenericos
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
        ///<summary>
        ///Inicializa uma nova instancia de Vulnerabilidades
        ///<return> Uma lista </return>
        ///</summary>
        public Vulnerabilidades()
        {
            vulnerabilidades = new List<Vulnerabilidade>();
            qtdVulnerabilidades = 0;
        }
        #endregion

        #region Propriedades
        /// <summary>
        /// Obtém ou ajusta o componente a lista de Vulnerabilidades
        /// </summary>
        public List<Vulnerabilidade> ListaVulnerabilidades
        {
            get { return vulnerabilidades; }
        }

        
        
        #endregion

        #region Metodos

        #region Inserção
        /// <summary>
        /// Insere uma vulnerabildade na lista de vulnerabilidades
        /// </summary>
        public bool InsereVulnerabilidade(Vulnerabilidade vulnerabilidade)
        {
            qtdVulnerabilidades++;
            vulnerabilidades.Add(vulnerabilidade);
            return true;
        }
        #endregion

        #region Listagem
        /// <summary>
        /// Mostra os dados referentes a uma lista de vulnerabildades
        /// </summary>
        public string MostrarDados()
        {
            string texto = "";
            for (int i = 0; i < qtdVulnerabilidades; i++)
            {
                texto += "Codigo: " + vulnerabilidades[i].Codigo + "Descrição: " +vulnerabilidades[i].Descricao +
                    "Nivel de Impacto: "+vulnerabilidades[i].NivelImpacto + "\n\n";

            }


            return texto;
        }

        #endregion

        #region Busca
        /// <summary>
        /// Procura uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade
        /// </summary>
        public int Procura(int id)
        {
            throw new System.NotImplementedException();
        }
        #endregion

        #region Edição
        /// <summary>
        /// Edita uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade e muda a descrição da vulnerabilidade
        /// </summary>
        public bool Editar(int id, string descricao)
        {
            // Para fazer na versao 2.0
            return true;
        }

        /// <summary>
        /// Edita uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade e muda o codigo da vulnerabilidade
        /// </summary>
        public bool Editar(int id, int numero)
        {
            // Para fazer na versao 2.0
            return true;
        }
         /// <summary>
        /// Edita uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade e muda a data da vulnerabilidade
        /// </summary>
        public bool Editar(int id, DateTime data)
        {
            // Para fazer na versao 2.0
            return true;
        }

        /// <summary>
        /// Edita uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade e muda o estado da vulnerabildade
        /// </summary>
        public bool Remove(int id)
        {
            // Para fazer na versao 2.0
            return true;
        }

        #endregion
        #endregion
    }
}
