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
        void PreencheCampoTabEdit();
        void PreencheCampoTabRemove();
        void LimpaTodosCampos();


        string TabInsertNome { get; set; }
        string TabInsertContribuinte { get; set; }
        string TabInsertBi { get; set; }
        string TabInsertMorada { get; set; }
        string TabInsertContacto { get; set; }
        string TabInsertCargo { get; set; }

        string TabEditID { get; set; }
        string TabEditNome { get; set; }
        string TabEditContribuinte { get; set; }
        string TabEditBi { get; set; }
        string TabEditMorada { get; set; }
        string TabEditContacto { get; set; }
        string TabEditCargo { get; set; }

        string TabRemoveID { get; set; }
        string TabRemoveNome { get; set; }
        string TabRemoveContacto { get; set; }
        string TabRemoveCargo { get; set; }


        DateTime TabInsertDataAdmissao { get; set; }
        ListView TabEditarListView { get; set; }
        ListView TabListarListView { get; set; }
        ListView TabRemoveListView { get; set; }


    }
}
