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
using System.Windows.Forms;
using Aparelhos;
using Defeitos;
using MinhasExceptionsLib;
using Pessoas;
using System.IO;
using AuditoriaLib;
using OcorrenciaLib;

namespace MyWindow.Controller
{
    /// <summary>
    /// 
    /// </summary>
    class MainController
    {

        private Funcionario f;
        private Funcionarios fs;
        private Equipamentos es;
        private Vulnerabilidades vs;
        private Auditorias audis;
        private Ocorrencias os;
       

        public MainController()
        {

            fs = new Funcionarios();

        }

        public bool InsereFuncionario(string numeroBi, string nome, string contribuinte, string cargo, DateTime dataAdmissao, string morada, string contacto)
        {
            int ncontri, contac;
            try
            {
                Int32.TryParse(contacto, out contac);
                Int32.TryParse(contribuinte, out ncontri);
                f = new Funcionario(numeroBi, nome, ncontri, cargo, dataAdmissao, morada, contac);
                return fs.InserirFuncionario(f);
            }
            catch (ValoresExceptions ve)
            {
                throw new ValoresExceptions("Erro" + ve);
            }
        }
        public ListView ListaFuncionarios(ListView lv)
        {

            #region Como inserir numa ListView
            List<Funcionario> funcionarios = fs.GetList();
            lv.Items.Clear();
            foreach (Funcionario func in funcionarios)
            {
                string[] row = { func.IdFuncionario.ToString(), func.Nome, func.Cargo, func.Contacto.ToString() };
                ListViewItem lvi = new ListViewItem(row);
                lvi.Tag = func;

                lv.Items.Add(lvi);
            }
            #endregion
            return lv;
        }

        public bool VariosOut(int i, out int numero, out int numero2)
        {
            numero = numero2 = i;
            return true;
        }

        public bool SaveAll()
        {
            try
            {
                if (fs.SaveFuncionarios() &&
                es.SaveEquipamentos() &&
                vs.SaveVulnerabilidades() && audis.SaveAuditorias() && os.SaveOcorrencias())
                {
                    return true;
                }
            }
            catch (IOException e)
            {
                throw e;
            }


            return false;
        }

        public bool LoadAll()
        {
            try
            {
                if (fs.LoadFuncionarios() && es.LoadEquipamentos() && vs.LoadVulnerabilidades() && audis.LoadAuditorias() && os.LoadOcorrencias()) 
                {
                    return true;
                }
            }
            catch (IOException e)
            {
                throw e;
            }
            return false;
        }

        public string GetSelectedItem(ListView lv)
        {
            try
            {

                return lv.SelectedItems[0].SubItems[0].Text;

            }
            catch (Exception ee)
            {
                throw new Exception(ee.Message);
            }

        }
    }
}
