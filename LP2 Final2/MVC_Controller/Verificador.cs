﻿//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
//-----------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MVC_Controller;
using MVC_Model;
using System.Windows.Forms;
namespace MVC_Controller
{
    /// <summary>
    /// 
    /// </summary>
    public class Verificador
    {
        
        MainController controller;
        IMainView view;
        public Verificador(IMainView v, MainController controlr)
        {
            view = v;
            controller = controlr;
        }

        public bool CheckDados(out Funcionario f)
        {
            Funcionario func = new Funcionario();
            int contrib, contato;
            try
            {               
                Int32.TryParse(view.TabInsertContribuinte, out contrib);
                Int32.TryParse(view.TabInsertContribuinte, out contato);
                if(contrib == 0 || contato == 0)
                {
                    MessageBox.Show("Erro nos valores inseridos!\nVerifique os campos do contribuinte e contacto");
                }
                else
                {
                    func.Nome = view.TabInsertNome;
                    func.NContribuinte = contrib;
                    func.Contacto = contato;
                    func.Morada = view.TabInsertMorada;
                    func.BI = view.TabInsertBi;
                    func.Cargo = view.TabInsertCargo;
                    func.DataAdmissao = view.TabInsertDataAdmissao;
                    f = func;
                    return true;
                }
            }
            catch(Exception e)
            {
                throw new Exception(e.Message);
            }
            f = null;
            return false;
        }
    }
}
