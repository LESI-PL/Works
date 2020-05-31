﻿//-----------------------------------------------------------------------
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
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using System.Data;
using System.Windows.Forms;

namespace MVC_Model
{
    /// <summary>
    /// Esta Classe representa uma instancia de Funcionarios 
    /// <code>Implementa: IMetodosGenericos</code>
    /// </summary>
    [Serializable]
    public class Funcionarios : IVerification, IProcura
    {

        #region Atributos
        /// <summary>
        /// Os valores recebidos aqui são:
        /// *funcionarios - Criação de uma lista do tipo Funcionarios
        /// *qtdFuncionarios - Quantidade de funcionarios que existe na lista
        /// </summary>
        List<Funcionario> funcionarios;
        int qtdFuncionarios;
        #endregion

        #region Construtor
        ///<summary>
        ///Inicializa uma nova instancia de Funcionarios
        ///</summary>
        public Funcionarios()
        {
            funcionarios = new List<Funcionario>();
            qtdFuncionarios = 0;
        }
        #endregion

        #region Propriedades
        /// <summary>
        /// Obtém ou ajusta o componente quantidade de Funcionarios
        /// <code>type: int</code>
        /// </summary>
        public int QtdFuncionario
        {
            get { return qtdFuncionarios; }
            set { qtdFuncionarios = value; }
        }
        #endregion

        #region Metodos

        #region Metodos Inserção
        /// <summary>
        /// Insere um funcionario na lista. Há uma verificação do contribuinte para nao repetir funcionarios
        /// </summary>
        /// <param name="funcionario"></param>
        /// <returns></returns>
        public bool InserirFuncionario(Funcionario funcionario)
        {
            int indice = ProcuraContribuinte(funcionario.NContribuinte);
            if (indice == -1)
            {
                qtdFuncionarios++;
                funcionario.IdFuncionario = qtdFuncionarios;
                funcionarios.Add(funcionario);
                return true;
            }
            return false;
        }

        #endregion
        
        #region Metodos Verificação
        public bool VerificaId(string idString, out int id)
        {
            bool result;
            try
            {
                result = Int32.TryParse(idString, out id);
            }catch(ValoresExceptions e)
            {
                throw new ValoresExceptions("Erro:", e);
            }
            
            return result;
        }
        #endregion

        #region Metodos Busca
        /// <summary>
        /// Recebe um id de funcionario e devolve o seu indice no array
        /// </summary>
        /// <param name="id">id do funcionario</param>
        /// <returns>int</returns>
        public int ProcuraContribuinte(int nContribuinte)
        {
            for (int i = 0; i < qtdFuncionarios; i++)
            {
                
                if (funcionarios[i].NContribuinte == nContribuinte) return i;
            }

            return -1;
        }

        public int Procura(int id) // Método da Interface
        {
            for (int i = 0; i < qtdFuncionarios; i++)
            {

                if (funcionarios[i].IdFuncionario == id) return i;
            }

            return -1;
        }
        
        public ListView GetListAtivos(ListView lista)
        {
            lista.Items.Clear();
            ListViewItem lvfinal = new ListViewItem();
            foreach (Funcionario func in funcionarios)
            {
                string[] row = { func.IdFuncionario.ToString(),
                                     func.BI,
                                     func.Nome,
                                     func.Morada,
                                     func.NContribuinte.ToString(),
                                     func.Contacto.ToString(),
                                     func.Cargo};
                if (func.Estado == true) {
                    ListViewItem lvi = new ListViewItem(row);
                    lvfinal = lvi;
                    lvfinal.Tag = func;
                    lista.Items.Add(lvi);
                }
               
            }            
            return lista;
        }
        public ListView GetListTodos(ListView lista)
        {
            lista.Items.Clear();
            ListViewItem lvfinal = new ListViewItem();
            foreach (Funcionario func in funcionarios)
            {
                string[] row = { func.IdFuncionario.ToString(),
                                     func.BI,
                                     func.Nome,
                                     func.Morada,
                                     func.NContribuinte.ToString(),
                                     func.Contacto.ToString(),
                                     func.Cargo};
                
                    ListViewItem lvi = new ListViewItem(row);
                    lvfinal = lvi;
                    lvfinal.Tag = func;
                    lista.Items.Add(lvi);
                

            }
            return lista;
        }
        #endregion

        #region Metodos Edicao
        /// <summary>
        /// Muda o nome do funcionario caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <param name="nome">Novo nome</param>
        /// <returns>bool</returns>
        public bool Editar(Funcionario f)
        {
            int indice;
            try
            {
                
                indice = Procura(f.IdFuncionario);
                
                if (indice >= 0)
                {

                    funcionarios[indice].BI = f.BI;
                    funcionarios[indice].Nome = f.Nome;
                    funcionarios[indice].NContribuinte = f.NContribuinte;
                    funcionarios[indice].Cargo = f.Cargo;
                    funcionarios[indice].Morada = f.Morada;
                    funcionarios[indice].Contacto = f.Contacto;
                    return true;
                }
            }
            catch (InvalidCastException ice)
            {
                throw ice;
            }
            catch (Exception e)
            {
                throw e;
            }
            return false;
        }
        /// <summary>
        /// Muda a id do funcionario caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <param name="newId">Novo id</param>
        /// <returns></returns>
        public bool Editar(int id, int newId)
        {
            int indice = Procura(id);
            if (indice >= 0)
            {
                funcionarios[indice].IdFuncionario = newId;
                return true;
            }
            return false;
        }
        /// <summary>
        /// Muda a data de admissão do funcionario na empresa caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <param name="data">Nova data</param>
        /// <returns>bool</returns>
        public bool Editar(int id, DateTime data)
        {
            
            int indice = Procura(id);
            if (indice >= 0)
            {
                funcionarios[indice].DataAdmissao = data;
                return true;
            }
            return false;
        }
        

        #endregion

        #region Metodos Listagem
        /// <summary>
        /// Mostra todos os Funcionarios pertencentes a lista
        /// </summary>
        /// <returns>string</returns>
        public string ListarFuncionarios()
        {
            string txt = "";
            if (QtdFuncionario != 0)
            {
                
                foreach (Funcionario f in funcionarios)
                {
                    txt += f.ShowDados() + "\n";
                }
            }
            else
            {
                txt += "A lista está vazia!";
            }
            
            return txt;
        }
        public string ListarFuncionariosDadosPessoais()
        {
            string txt = "";
            if(QtdFuncionario != 0)
            {
                foreach (Funcionario f in funcionarios)
                {
                    txt += f.ShowDadosPessoais() + "\n\n";
                }
            }
            else
            {
                txt += "A lista está vazia!";
            }

            return txt;
        }
        public string ListarFuncionariosCompleto()
        {
            string txt = "";
            if (QtdFuncionario != 0)
            {
                foreach (Funcionario f in funcionarios)
                {
                    txt += f.ShowDadosCompletos() + "\n";
                }
            }
            else
            {
                txt += "A lista está vazia!";
            }


            return txt;
        }

        #endregion

        #region Remove
        /// <summary>
        /// Muda o estado do funcionario na empresa caso seja encontrado
        /// </summary>
        /// <param name="id">id do funcionario para procura</param>
        /// <returns>bool</returns>
        public bool Remove(Funcionario f)
        {
            int indice = Procura(f.IdFuncionario);

            if (indice >= 0)
            {
                funcionarios[indice].Estado = false;
                return true;
            }
            return false;
        }
        #endregion



        #region Save/salvar
        /// <summary>
        /// Metodo Para guardar os dados dos funcionarios em dados binarios
        /// </summary>
        /// <returns></returns>
        public bool SaveFuncionarios()
        {
            string filename = Path.GetFullPath("./SavedFiles/funcio.bin");
            if (File.Exists(filename))
            {
                try
                {
                    Stream stream = File.Open(filename, FileMode.Create);
                    BinaryFormatter bin = new BinaryFormatter();
                    bin.Serialize(stream, funcionarios);                    
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
        /// Metodo que faz o carregamento dos dados de funcionarios para o programa.
        /// </summary>
        /// <returns></returns>
        public bool LoadFuncionarios()
        {
            string filename = Path.GetFullPath("./SavedFiles/funcio.bin");

            if (File.Exists(filename) && (new FileInfo(filename).Length>0))
            {
                try
                {
                    Stream stream = File.Open(filename, FileMode.Open);
                    BinaryFormatter bin = new BinaryFormatter();                    
                    funcionarios = (List<Funcionario>)bin.Deserialize(stream);
                    QtdFuncionario = funcionarios.Count;
                    stream.Close();
                    return true;
                }catch(SerializationException s)
                {
                    throw s;
                }
                catch (ArgumentNullException an)
                {
                    throw an;
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
