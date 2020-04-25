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

namespace MinhasInterfaces
{
    /// <summary>
    /// Isso é uma interface com métodos genéricos
    /// </summary>
    public interface IMetodosGenericos
    {

        int Procura(int id);

        bool Remove(int id);

        bool Editar(int id, string nome);
        bool Editar(int id, int numero);
        bool Editar(int id, DateTime data);


    }
}
