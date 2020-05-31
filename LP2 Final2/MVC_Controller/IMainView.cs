//-----------------------------------------------------------------------
// <copyright file="Program.cs" company="IPCA">
// Copyright (c) IPCA. All rights reserved.</copyright>
//-----------------------------------------------------------------------
// <author>Yuri Lemos</author>
// <desc> This program do the basics of C#</desc>
// <Date> 4 / 4 / 2020 </Date>
// <version>1.0</version>
//-----------------------------------------------------------------------

using MVC_Model;
using System;
using System.Windows.Forms;

namespace MVC_Controller
{
    /// <summary>
    /// 
    /// </summary>
    public interface IMainView
    {
        void SetController(MainController controller);
        bool UpdateLists(ListView[] listasIn, out ListView[] listasOut);
        void PreencheCampo();



        #region Properties
        #region Tab Insere Funcionario
        string TabInsertNome{ get;set; }
        string TabInsertContribuinte { get; set; }
        string TabInsertBi { get; set; }
        string TabInsertMorada { get; set; }
        string TabInsertContacto { get; set; }
        string TabInsertCargo { get; set; }
        DateTime TabInsertDataAdmissao { get; set; }
        #endregion

        #region Tab Remove Funcionario
        ListView TabRemoveListView { get; set; }
        #endregion

        #region Tab Listar Funcionarios
        ListView TabListarListView { get; set; }
        #endregion
        #endregion
    }
}
