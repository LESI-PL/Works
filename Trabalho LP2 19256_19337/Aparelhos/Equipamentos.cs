//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
using MinhasInterfaces;
using System;
using System.Collections.Generic;

namespace Aparelhos
{

    /// <summary>
    /// Esta Classe representa uma instancia de Eqipamentos 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>

    public class Equipamentos : IMetodosGenericos
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

        #region Metodos

        #region Insercao
        /// <summary>
        /// Insere um equipamento na lista
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

        #region Edicao
        /// <summary>
        /// Muda o nome do modelo do equipamento caso seja encontrado
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <param name="modelo">Novo modelo</param>
        /// <returns>bool</returns>
        public bool Editar(int id, string modelo)
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
        /// Muda o codigo do equipamento caso seja encontrado
        /// </summary>
        /// <param name="id">id do equipamento</param>
        /// <param name="marca">Novo codigo</param>
        /// <returns>bool</returns>
        public bool Editar(int id, int numero)
        {
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    equipamentos[i].Codigo = numero;
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
        public bool Editar(int id, DateTime data)
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
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    equipamentos[i].Estado = false;
                    return true;
                }
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
            for (int i = 0; i < qtdEquipamentos; i++)
            {
                //if(funcionarios[i].Estado)
                txt += equipamentos[i].ToString() + "\n";
            }
            return txt;
        }


        #endregion


        #endregion



    }
}
