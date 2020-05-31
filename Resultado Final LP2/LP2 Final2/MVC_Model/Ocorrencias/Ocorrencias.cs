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
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace MVC_Model
{
    /// <summary>
    /// Esta classe representa uma instâcia de ocorrencias
    /// </summary>
    [Serializable]
    public class Ocorrencias
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

        public Ocorrencias(List<Ocorrencia> list)
        {
            ocorrencias = new List<Ocorrencia>();
            ocorrencias = list;
            qtdOcorrencias = 0;
        }
        
        #endregion

        #region Propriedades
        public List<Ocorrencia> ListOcorrencias
        {
            get { return ocorrencias; }
            set { ocorrencias = value; }
        }

        public int QtdOcorrencias
        {
            get { return qtdOcorrencias; }
            set { qtdOcorrencias = value; }
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
                    QtdOcorrencias++;
                    ocorrencia.IdOcorrencia = QtdOcorrencias;
                    ocorrencias.Add(ocorrencia);
                    message = "Ocorrencia Inserida!";
                    return true;
                }
            }
            return false;
        }

        #region Save/salvar
        /// <summary>
        /// Metodo Para guardar os dados das ocorrencias em dados binarios
        /// </summary>
        /// <returns></returns>
        public bool SaveOcorrencias()
        {
            if (File.Exists("Ocorrencias"))
            {
                try
                {
                    Stream stream = File.Open("Ocorrencias", FileMode.Create);
                    BinaryFormatter bin = new BinaryFormatter();
                    bin.Serialize(stream, ocorrencias);
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
        /// Metodo que faz o carregamento dos dados de ocorrencias para o programa.
        /// </summary>
        /// <returns></returns>
        public bool LoadOcorrencias()
        {
            if (File.Exists("Ocorrencias"))
            {
                try
                {
                    Stream stream = File.Open("Auditorias", FileMode.Open);
                    BinaryFormatter bin = new BinaryFormatter();
                    ocorrencias = (List<Ocorrencia>)bin.Deserialize(stream);
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
