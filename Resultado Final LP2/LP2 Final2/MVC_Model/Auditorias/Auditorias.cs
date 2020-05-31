//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;


namespace MVC_Model
{
    /// <summary>
    /// Esta Classe representa uma instancia de Auditorias
    /// </summary>
    public class Auditorias
    {
        #region Atributos
        List<Auditoria> auditorias;
        int qtdAuditorias;

        #endregion

        /// <summary>
        /// Default constructor of Auditorias
        /// </summary>
        #region Contrutor
        public Auditorias()
        {
            auditorias = new List<Auditoria>();
        }
        /// <summary>
        /// Inicializa uma nova intancia de Auditorias com parametros
        /// </summary>
        /// <param name="Code_colaborador"></param>
        public Auditorias(List<Auditoria> list)
        {
            auditorias = new List<Auditoria>();
            auditorias = list;
            qtdAuditorias = 0;
        }

        #endregion

        #region Propriedades
        public int QtdAuditorias
        {
            get { return qtdAuditorias; }
            set { qtdAuditorias = value; }
        }
        #endregion

        #region Metodos

        #region Mtodo de Insercao
        /// <summary>
        /// Insere uma Auditoria na lista. 
        /// </summary>
        /// <param name="funcionario"></param>
        /// <returns></returns>
        public bool InserirAuditoria(Auditoria auditoria)
        {
            QtdAuditorias++;
            auditoria.CodigoAuditoria = QtdAuditorias;
            auditorias.Add(auditoria);
            return true;
        }
        #endregion

        #region Metodos Busca
        /// <summary>
        /// Recebe um id de Auditoria e devolve o seu indice no array
        /// </summary>
        /// <param name="codigo">codigo da auditoria</param>
        /// <returns>int</returns>
        public int ProcuraAuditoria(int codigo)
        {
            for (int i = 0; i < qtdAuditorias; i++)
            {

                if (auditorias[i].CodigoAuditoria == codigo) return i;
            }

            return -1;
        }
        #endregion

        #region Metodos Adicionar Ocorrencia
       /// <summary>
       /// Adiciona uma nova vulnerabilidade num equipamneto numa auditoria
       /// </summary>
       /// <param name="codigo"> codigo da auditoria </param>
       /// <param name="codigo_vulnerabilidade">codigo da vulnerabilidade</param>
       /// <param name="codigo_equipamento">codigo do equipamento </param>
       /// <returns></returns>
        public bool AdicionarOcorrenciaAuditoria(int codigo, int codigo_vulnerabilidade, int codigo_equipamento)
        {
            int indice = ProcuraAuditoria(codigo);
            for(int i=0; i < QtdAuditorias; i++)
            {
                if(auditorias[indice].Ocorrencias[i].CodVulnerabilidade== codigo_vulnerabilidade && auditorias[indice].Ocorrencias[i].CodEquipamento == codigo_equipamento)
                {
                    return false;
                }
                
            }
            int pos = auditorias[indice].QtdOcorrencias;
            auditorias[indice].Ocorrencias[pos + 1].CodEquipamento = codigo_equipamento;
            auditorias[indice].Ocorrencias[pos + 1].CodVulnerabilidade = codigo_vulnerabilidade;
            auditorias[indice].Ocorrencias[pos + 1].Estado = true;
            auditorias[indice].QtdOcorrencias++;
            return true;

        }
        #endregion

        #region Metodos Adicionar Ocorrencia
        /// <summary>
        /// Remove uma nova vulnerabilidade num equipamneto numa auditoria
        /// </summary>
        /// <param name="codigo"> codigo da auditoria </param>
        /// <param name="codigo_vulnerabilidade">codigo da vulnerabilidade</param>
        /// <param name="codigo_equipamento">codigo do equipamento </param>
        /// <returns></returns>
        public bool RemoverOcorrenciaAuditoria(int codigo, int codigo_vulnerabilidade, int codigo_equipamento)
        {
            int indice = ProcuraAuditoria(codigo);
            for (int i = 0; i < QtdAuditorias; i++)
            {
                if (auditorias[indice].Ocorrencias[i].CodVulnerabilidade == codigo_vulnerabilidade && auditorias[indice].Ocorrencias[i].CodEquipamento == codigo_equipamento)
                {
            
                    auditorias[indice].Ocorrencias[i].CodEquipamento = codigo_equipamento;
                    auditorias[indice].Ocorrencias[i].CodVulnerabilidade = codigo_vulnerabilidade;
                    auditorias[indice].Ocorrencias[i].Estado = false;
                    //auditorias[indice].QtdOcorrencias++;
                }

            }
           
            return false;

        }
        #endregion

        #region Metodos Listagem
        /// <summary>
        /// Mostra todas os Ocorrencias de uma auditoria
        /// </summary>
        /// <returns>string</returns>
        public string ListarOcorrecias(int codigo)
        {
            int indice = ProcuraAuditoria(codigo);
            string txt = "";
            
            for(int i = 0; i < auditorias[indice].QtdOcorrencias; i++)
            {
                if (auditorias[indice].Ocorrencias[i].Estado == true)
                {
                    txt += "Vulnerabilida ID:" + "" + auditorias[indice].Ocorrencias[i].CodVulnerabilidade + ""
                        + "" + "Equipamento ID:" + "" + auditorias[indice].Ocorrencias[i].CodEquipamento;
                }
            }
            return txt;
        }
        #endregion

        #region Save/salvar
        /// <summary>
        /// Metodo Para guardar os dados dos auditorias em dados binarios
        /// </summary>
        /// <returns></returns>
        public bool SaveAuditorias()
        {
            if (File.Exists("Auditorias"))
            {
                try
                {
                    Stream stream = File.Open("Auditorias", FileMode.Create);
                    BinaryFormatter bin = new BinaryFormatter();
                    bin.Serialize(stream, auditorias);
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
        public bool LoadAuditorias()
        {
            if (File.Exists("Auditorias"))
            {
                try
                {
                    Stream stream = File.Open("Auditorias", FileMode.Open);
                    BinaryFormatter bin = new BinaryFormatter();
                    auditorias = (List<Auditoria>)bin.Deserialize(stream);
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
