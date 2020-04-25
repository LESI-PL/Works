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

namespace Auditorias
{
    class Equipamentos : IMetodosGenericos
    {
        #region Atributos
        Equipamento[] equipamentos;
        int totalEquipamento=0;
        #endregion

        #region Construtor
        public Equipamentos()
        {
            equipamentos = new Equipamento[20];
        }

        public bool Editar(int id, Equipamento obj)
        {
            throw new System.NotImplementedException();
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
        public bool InserirEquipamento(Equipamento equipamento)
        {
            if (totalEquipamento == equipamentos.Length)
            {
                return false;
            }
            else
            {
                equipamentos[totalEquipamento] = equipamento;
                if (totalEquipamento < equipamentos.Length)
                {
                    totalEquipamento++;
                }

            }
            return true;
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
