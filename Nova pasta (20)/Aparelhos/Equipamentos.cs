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
using InterfacesAuditoria;
using MinhasExceptionsLib;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Aparelhos
{

    /// <summary>
    /// Esta Classe representa uma instancia de Eqipamentos 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>
    [Serializable]
    public class Equipamentos : IVerification, IProcura
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *equipamentos - Criação de uma lista do tipo Equipamento
        /// *qtdEquipamentos - Quantidade de equipamentos que existe na lista
        /// </summary>
        List<Equipamento> equipamentos;
        int qtdEquipamentos;
        #endregion


        #region Construtor
        /// <summary>
        /// Cria uma instancia de equipamentos
        /// </summary>
        public Equipamentos()
        {
            equipamentos = new List<Equipamento>();
            qtdEquipamentos = 0;
        }


        #endregion

        #region Propriedades
        public int QtdEquipamentos
        {
            get { return qtdEquipamentos; }
        }
        #endregion

        #region Metodos

        #region Insercao
        /// <summary>
        /// Insere um equipamento na lista, caso já exista retorna false
        /// </summary>
        /// <param name="equipamento"> equipamento</param>
        /// <returns>bool</returns>
        public bool InserirEquipamento(Equipamento equipamento)
        {
            int indice = Procura(equipamento.Codigo);
            if (indice == -1)
            {
                qtdEquipamentos++;
                equipamento.Codigo = qtdEquipamentos;
                equipamentos.Add(equipamento);
                return true;
            }
            return false;
        }


        #endregion

        #region Busca
        /// <summary>
        /// Recebe o id do equipamento e devolve o seu indice no array
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <returns>int</returns>
        public int Procura(int id)
        {
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    return i;
                }
            }
            return -1;
        }


        #endregion

        #region Edicão
        /// <summary>
        /// Muda o nome do modelo do equipamento caso seja encontrado
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <param name="modelo">Novo modelo</param>
        /// <returns>bool</returns>
        public bool EditarModelo(int id, string modelo)
        {
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    equipamentos[i].Modelo = modelo;
                    return true;
                }
            }
            return false;
        }
        /// <summary>
        /// Muda a marca do equipamento caso seja encontrado
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <param name="marca">Nova marca</param>
        /// <returns>bool</returns>
        public bool EditarMarca(int id, string marca)
        {
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    equipamentos[i].Marca = marca;
                    return true;
                }
            }
            return false;
        }
       
        /// <summary>
        /// Muda a data de aquisição do equipamento caso seja encontrado
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <param name="marca">Nova data</param>
        /// <returns>bool</returns>
        public bool EditarDataAquisicao(int id, DateTime data)
        {
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    equipamentos[i].Aquisicao = data;
                    return true;
                }
            }
            return false;
        }
        /// <summary>
        /// Muda o estado do quipamento caso seja encontrado
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <returns>bool</returns>
        public bool Remove(int id)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                equipamentos[indice].Estado = false;
                return true;
            }
            return false;

        }

        #endregion

        #region Listagem
        /// <summary>
        /// Mostra todos os equipamentos pertencentes a lista
        /// </summary>
        /// <returns>string</returns>
        public string ListarEquipamentos()
        {
            string txt = "";
            foreach(Equipamento e in equipamentos)
            {
                txt += e.MostraDados()+"\n";
            }
            return txt;
        }

        public string ShowEquipment(int id)
        {
            string txt = "";
            foreach(Equipamento e in equipamentos)
            {
                if (e.Codigo == id) 
                txt = e.MostraDados();
            }
            return txt;
        }
                
        #endregion

        #region Verificaçao
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
            catch(Exception ee)
            {
                throw new Exception("Erro:" + ee.Message);
            }
            return result;
        }
        #endregion

        #region Save/salvar
        /// <summary>
        /// Metodo Para guardar os dados dos equipamentos em dados binarios
        /// </summary>
        /// <returns></returns>
        public bool SaveEquipamentos()
        {
            if (File.Exists("Equipamentos"))
            {
                try
                {
                    Stream stream = File.Open("Equipamentos", FileMode.Create);
                    BinaryFormatter bin = new BinaryFormatter();
                    bin.Serialize(stream, equipamentos);
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
        /// Metodo que faz o carregamento dos dados de equipamntos para o programa.
        /// </summary>
        /// <returns></returns>
        public bool LoadEquipamentos()
        {
            if (File.Exists("Funcionarios"))
            {
                try
                {
                    Stream stream = File.Open("Funcionarios", FileMode.Open);
                    BinaryFormatter bin = new BinaryFormatter();
                    equipamentos = (List<Equipamento>)bin.Deserialize(stream);
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
