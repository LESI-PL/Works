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
using MinhasExceptionsLib;
using InterfacesAuditoria;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Defeitos
{
    /// <summary>
    /// Esta Classe representa uma instancia de Vulnerabilidades 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>
    [Serializable]
    public class Vulnerabilidades : IVerification
    {

        /*
         * Vulnerabilidades Contém:
         *      - Uma lista de vulnerabilidades
         *      - Quantidade de vulnerabilidades
         */
        #region Atributos
        List<Vulnerabilidade> vulnerabilidades;
        int id;
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
            id = 0;
        }
        #endregion

        #region Propriedades
        /// <summary>
        /// Obtém ou ajusta o componente a lista de Vulnerabilidades
        /// </summary>
        public int QtdVulnerabilidades
        {
            get { return qtdVulnerabilidades; }
        }



        #endregion

        #region Metodos

        #region Inserção
        /// <summary>
        /// Insere uma vulnerabildade na lista de vulnerabilidades
        /// </summary>
        public bool InserirVulnerabilidade(Vulnerabilidade vulnerabilidade)
        {
            qtdVulnerabilidades++;
            id++;
            vulnerabilidade.Codigo = id;
            vulnerabilidades.Add(vulnerabilidade);
            return true;
        }
        #endregion

        #region Listagem
        /// <summary>
        /// Mostra os dados referentes a uma lista de vulnerabildades
        /// </summary>
        public string MostrarDados(int id)
        {
            string txt = "";
            foreach (Vulnerabilidade v in vulnerabilidades)
            {
                if (v.Codigo == id)
                    txt = v.MostraVulnerabilidade();
            }
            return txt;
        }

        public string ListarVulnerabilidades()
        {
            string txt = "";
            foreach (Vulnerabilidade v in vulnerabilidades)
            {
                txt += v.MostraVulnerabilidade() + "\n";
            }
            return txt;
        }

        #endregion

        #region Busca
        /// <summary>
        /// Procura uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade
        /// </summary>
        public int Procura(int codigoVulnerabilidade)
        {
            for (int i = 0; i < qtdVulnerabilidades; i++)
            {
                if (vulnerabilidades[i].Codigo == codigoVulnerabilidade) return i;
            }
            return -1;
        }
        #endregion

        #region Edição
        /// <summary>
        /// Edita uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade e muda a descrição da vulnerabilidade
        /// </summary>
        public bool EditarDescricao(int id, string descricao)
        {
            int pos = Procura(id);
            if (pos != -1)
            {
                vulnerabilidades[pos].Descricao = descricao;
                return true;
            }
            return false;

        }


        public bool EditarImpacto(int id, string impacto)
        {
            int pos = Procura(id);
            if (pos != -1)
            {
                vulnerabilidades[pos].NivelImpacto = impacto;
                return true;
            }
            return false;
        }

        /// <summary>
        /// Edita uma vulnerabilidade numa lista de vulnerabilidades, recebe o id da Vulnerabilidade e muda o estado da vulnerabildade
        /// </summary>
        public bool Remove(int id)
        {
            int indice = Procura(id);

            if (indice >= 0)
            {
                vulnerabilidades.RemoveAt(indice);
                qtdVulnerabilidades--;
                return true;
            }
            return false;
        }
        #endregion

        #region VerificaID
        public bool VerificaId(string codigo, out int id)
        {
            bool result = false;
            try
            {
                result = Int32.TryParse(codigo, out id);
            }
            catch (ValoresExceptions e)
            {
                throw new ValoresExceptions("Erro: Valor errado", e);
            }
            return result;
        }
        #endregion


        #region Save/salvar
        /// <summary>
        /// Metodo Para guardar os dados dos vulnerabilidades em dados binarios
        /// </summary>
        /// <returns></returns>
        public bool SaveVulnerabilidades()
        {
            if (File.Exists("Vulnerabilidades"))
            {
                try
                {
                    Stream stream = File.Open("Vulnerabilidades", FileMode.Create);
                    BinaryFormatter bin = new BinaryFormatter();
                    bin.Serialize(stream, vulnerabilidades);
                    stream.Close();
                    return true;
                }
                catch (IOException e)
                {
                    throw e;
                }
            }
            return false;
        }
        #endregion

        #region Load/carregamento
        /// <summary>
        /// Metodo que faz o carregamento dos dados de vulnerabilidades para o programa.
        /// </summary>
        /// <returns></returns>
        public bool LoadVulnerabilidades()
        {
            if (File.Exists("Vulnerabilidades"))
            {
                try
                {
                    Stream stream = File.Open("Vulnerabilidades", FileMode.Open);
                    BinaryFormatter bin = new BinaryFormatter();
                    vulnerabilidades = (List<Vulnerabilidade>)bin.Deserialize(stream);
                    stream.Close();
                    return true;
                }
                catch (IOException e)
                {

                    throw e;
                }
            }
            return false;
        }
        #endregion

        #endregion
    }
}
