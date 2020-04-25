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

namespace Auditorias
{

    /// <summary>
    /// Esta Classe representa uma instancia de Eqipamentos 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>

    class Equipamentos : IMetodosGenericos
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

        /// <summary>
        /// Cria 
        /// </summary>
        #region Construtor
        public Equipamentos()
        {
            equipamentos = new List<Equipamento>();
            qtdEquipamentos = 0;
        }


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
        #endregion

        #region Metodos

        public int Procura(int id)
        {
            for(int i = 0; i < qtdEquipamentos; i++)
            {
                if (equipamentos[i].Codigo == id)
                {
                    return i;
                }
            }
            return -1;
        }

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



    }
}
