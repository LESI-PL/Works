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
            view.TabListarListView = fs.GetList(view.TabListarListView);
            view.TabRemoveListView = fs.GetList(view.TabRemoveListView);
        }

       
        public bool InsereFuncionario()
        {
            bool estadoCheck,estadoInsert;
            Funcionario f = new Funcionario();
            estadoCheck = verif.CheckDados(out f);
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
             
            UpdateAllLists();
            return estadoCheck;
        }
        
        public bool EditarFuncionario(Funcionario f)
        {
            return fs.Editar(f);
        }

        public bool RemoveFuncionario(Funcionario f)
        {
            return fs.Remove(f);
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
            }catch(System.Runtime.Serialization.SerializationException se)
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
