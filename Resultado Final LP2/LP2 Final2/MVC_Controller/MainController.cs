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
using System.IO;
using System.Windows.Forms;
using MVC_Model;

namespace MVC_Controller
{
    /// <summary>
    /// 
    /// </summary>
    public class MainController
    {
        IMainView view;
        private Funcionarios fs;
        private Verificador verif;


        public MainController(IMainView view)
        {
            this.view = view;
            fs = new Funcionarios();
            verif = new Verificador(this.view, this);
            view.SetController(this);
            LoadAll();
            UpdateAllLists();
        }

        public void UpdateAllLists()
        {
            view.TabListarListView = fs.GetListAtivos(view.TabListarListView);
            view.TabRemoveListView = fs.GetListAtivos(view.TabRemoveListView);
            view.TabEditarListView = fs.GetListAtivos(view.TabEditarListView);
        }

        public bool EditFuncionarioSelected()
        {
            view.PreencheCampoTabEdit();
           
            return true;
        }
        public bool RemoveFuncionarioSelected()
        {
         
            view.PreencheCampoTabRemove();
            return true;
        }
        public bool InsereFuncionario()
        {
            bool estadoCheck, estadoInsert;
            Funcionario f = new Funcionario();
            estadoCheck = verif.CheckDadosInsert(out f);
            if (estadoCheck && f != null)
            {
                estadoInsert = fs.InserirFuncionario(f);
                if (estadoInsert)
                {
                    MessageBox.Show("Dados Inseridos!");

                }
                else
                {
                    MessageBox.Show("Falha ao inserir o funcionario!");
                }
            }
            view.LimpaTodosCampos();
            UpdateAllLists();
            return estadoCheck;
        }

        public bool EditarFuncionario()
        {
            bool estadoCheck, estadoInsert;
            Funcionario f = new Funcionario();
            estadoCheck = verif.CheckDadosEdit(out f);
            if (estadoCheck && f != null)
            {
                estadoInsert = fs.Editar(f);
                if (estadoInsert)
                {
                    MessageBox.Show("Dados Editados!");

                }
                else
                {
                    MessageBox.Show("Falha ao editar o funcionario!");
                }
            }
            view.LimpaTodosCampos();
            UpdateAllLists();
            return estadoCheck;
        }

        public bool RemoverFuncionario()
        {
            bool estadoCheck, estadoInsert;
            Funcionario f = new Funcionario();
            estadoCheck = verif.CheckDadosRemover(out f);
            if (estadoCheck && f != null)
            {
                estadoInsert = fs.Remove(f);
                if (estadoInsert)
                {
                    MessageBox.Show("Funcionario Removido!");

                }
                else
                {
                    MessageBox.Show("Falha ao remover o funcionario!");
                }
            }
            view.LimpaTodosCampos();
            UpdateAllLists();
            return estadoCheck;
        }

        public bool SaveAll()
        {

            try
            {
                if (fs.SaveFuncionarios())
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
                if (fs.LoadFuncionarios())
                {
                    return true;
                }
            }
            catch (System.Runtime.Serialization.SerializationException se)
            {
                throw se;
            }
            catch (IOException e)
            {
                throw e;
            }
            return false;
        }




    }
}
