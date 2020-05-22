//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <author>João Figueiredo</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>

using Aparelhos;
using AuditoriaLib;
using Defeitos;
using MinhasExceptionsLib;
using OcorrenciaLib;
using Pessoas;
using System;
using System.IO;
using System.Windows.Forms;

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
            f = new Funcionario();
            fs = new Funcionarios();
            es = new Equipamentos();
            vs = new Vulnerabilidades();
            audis = new Auditorias();
            os = new Ocorrencias();
            LoadAll();
            

        }
        public static Form1 Start()
        {
            Form1 form = new Form1();
            
            return form;
        }

        public bool UpdateLists(ListView[] listasIn,out ListView[] listasOut)
        {
            ListView[] lists = new ListView[3];
            lists[0] = fs.GetList(listasIn[0]);
            lists[1] = fs.GetList(listasIn[1]);
            lists[2] = fs.GetList(listasIn[2]);
            listasOut = lists;

            if (lists[0] != null && lists[1] != null && lists[2] != null) { return true; }
            return false;
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
        
        public bool EditarFuncionario(string id,string numeroBi, string nome, string contribuinte, string cargo, string morada, string contacto)
        {
            return fs.Editar(id, numeroBi, nome, contribuinte, cargo, morada, contacto);
        }

        public ListView ListaFuncionarios(ListView lv)
        {
            return fs.GetList(lv);
            
        }

        public bool SaveAll()
        {
            string path = Path.GetFullPath("./SavedFiles/funcio.bin");
            try
            {
                //if (fs.SaveFuncionarios(@"C:\Users\Yuri Lemos\Desktop\Nova pasta (20)\SavedFiles\funcio.bin"))
                if (fs.SaveFuncionarios(@path))
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
            string path = Path.GetFullPath("./SavedFiles/funcio.bin");
            try
            {
                //if (fs.LoadFuncionarios(@"C:\Users\Yuri Lemos\Desktop\Nova pasta (20)\SavedFiles\funcio.bin"))
                
                if (fs.LoadFuncionarios(@path))
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

        public static string[] GetSelectedItem(ListView lv)
        {
            string[] dados = new string[8];
            try
            {
                //
                for (int i = 0; i < lv.SelectedItems[0].SubItems.Count; i++)
                {
                    dados[i] = lv.SelectedItems[0].SubItems[i].Text;
                }

                return dados;
                //return lv.SelectedItems[0].SubItems[0].Text;

            }
            catch (Exception ee)
            {
                throw new Exception(ee.Message);
            }

        }
    }
}
