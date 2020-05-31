using MVC_Controller;
using MVC_Model;
using System;
using System.Data.OleDb;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

namespace MVC_View
{
    public partial class MainView : Form, IMainView
    {

        ListView[] listasFunc = new ListView[3];
        MainController mc;
        Verificador vf;
        Funcionarios fst;

        public MainView(Funcionarios f)
        {
            InitializeComponent();
            fst = f;
            
        }


        #region Propriedades
        #region Tab Insere Funcionario
        public string TabInsertNome { get => tabInsertTxtBxNome.Text; set => tabInsertTxtBxNome.Text = value; }
        public string TabInsertContribuinte { get => tabInsertTxtBxContri.Text; set => tabInsertTxtBxContri.Text = value; }
        public string TabInsertBi { get => tabInsertTxtBxBi.Text; set => tabInsertTxtBxBi.Text = value; }
        public string TabInsertMorada { get => tabInsertTxtBxMorada.Text; set => tabInsertTxtBxMorada.Text = value; }
        public string TabInsertContacto { get => tabInsertTxtBxContacto.Text; set => tabInsertTxtBxContacto.Text = value; }
        public string TabInsertCargo { get => tabInsertTxtBxCargo.Text; set => tabInsertTxtBxCargo.Text = value; }
        public DateTime TabInsertDataAdmissao { get => tabInsertdateTimePicker.Value; set => tabInsertdateTimePicker.Value = value; }
        #endregion
        #endregion





        #region Tab Funcionarios
        public ListView TabEditarListView { get => fTabEditListView; set => fTabEditListView = value; }
        public ListView TabListarListView { get => tabFuncListViewListar; set => tabFuncListViewListar = value; }
        public ListView TabRemoveListView { get => tabRemovListView; set => tabRemovListView = value; }

        public string TabEditID { get => fTabEditTbxID.Text; set => fTabEditTbxID.Text = value; }
        public string TabEditNome { get => fTabEditTbxNome.Text; set => fTabEditTbxNome.Text=value; }
        public string TabEditContribuinte { get => fTabEditTbxContribu.Text; set => fTabEditTbxContribu.Text = value; }
        public string TabEditBi { get => fTabEditTbxBI.Text; set => fTabEditTbxBI.Text = value; }
        public string TabEditMorada { get => fTabEditTbxMorada.Text; set => fTabEditTbxMorada.Text = value; }
        public string TabEditContacto { get => fTabEditTbxContacto.Text; set => fTabEditTbxContacto.Text = value; }
        public string TabEditCargo { get => fTabEditTbxCargo.Text; set => fTabEditTbxCargo.Text = value; }

        public string TabRemoveID { get => tabRemovTxtBxID.Text; set => tabRemovTxtBxID.Text = value; }
        public string TabRemoveNome { get => tabRemovTxtBxNome.Text; set => tabRemovTxtBxNome.Text = value; }
        public string TabRemoveContacto { get => tabRemovTxtBxContato.Text; set => tabRemovTxtBxContato.Text = value; }
        public string TabRemoveCargo { get => tabRemovTxtBxCargo.Text; set => tabRemovTxtBxCargo.Text = value; }
        #endregion



        private void Form1_Load(object sender, EventArgs e)
        {
            listasFunc[0] = tabFuncListViewListar;
            listasFunc[1] = tabRemovListView;
            listasFunc[2] = fTabEditListView;
            //mc.UpdateLists(listasFunc,out listasFunc);            
        }
        public void SetController(MainController controller)
        {
            mc = controller;
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            pnlFuncionarios.Visible = true;
        }

        private void pictureSaveIcon_Click(object sender, EventArgs e)
        {
            if (mc.SaveAll())
            {
                MessageBox.Show("Dados Guardados!");
            }
            else
            {
                MessageBox.Show("Erro na gravação!");
            }
        }

        private void fTabEditBtnRemover_Click(object sender, EventArgs e)
        {
            mc.RemoverFuncionario();
        }

        private void tabInsertBtnCriar_Click(object sender, EventArgs e)
        {
            mc.InsereFuncionario();            
        }

        private void fTabEditListView_MouseClick(object sender, MouseEventArgs e)
        {
            mc.EditFuncionarioSelected();
        }

        private void tabRemovListView_MouseClick(object sender, MouseEventArgs e)
        {
            mc.RemoveFuncionarioSelected();
        }

        private void picBXBackBtn_Click(object sender, EventArgs e)
        {
            pnlFuncionarios.Visible = false;
        }

        private void fTabEditBtnEditar_Click(object sender, EventArgs e)
        {
            mc.EditarFuncionario();
        }
        public void PreencheCampoTabRemove()
        {
            string[] dados = new string[8];
            try
            {
                //
                for (int i = 0; i < tabRemovListView.SelectedItems[0].SubItems.Count; i++)
                {
                    dados[i] = tabRemovListView.SelectedItems[0].SubItems[i].Text;
                }
                tabRemovTxtBxID.Text = dados[0];
                tabRemovTxtBxNome.Text = dados[2];
                tabRemovTxtBxCargo.Text = dados[6];
                tabRemovTxtBxContato.Text = dados[5];
                //return lv.SelectedItems[0].SubItems[0].Text;

            }
            catch (Exception ee)
            {
                throw new Exception(ee.Message);
            }

        }
        public void PreencheCampoTabEdit()
        {
            string[] dados = new string[8];
            try
            {
                //
                for (int i = 0; i < fTabEditListView.SelectedItems[0].SubItems.Count; i++)
                {
                    dados[i] = fTabEditListView.SelectedItems[0].SubItems[i].Text;
                }
                fTabEditTbxID.Text = dados[0];
                fTabEditTbxNome.Text = dados[2];
                fTabEditTbxCargo.Text = dados[6];
                fTabEditTbxContacto.Text = dados[5];
                fTabEditTbxContribu.Text = dados[4];
                fTabEditTbxBI.Text = dados[1];
                fTabEditTbxMorada.Text = dados[3];
                //return lv.SelectedItems[0].SubItems[0].Text;

            }
            catch (Exception ee)
            {
                throw new Exception(ee.Message);
            }
            
        }

        public void LimpaTodosCampos()
        {
            TabInsertNome = "";
            TabInsertMorada = "";
            TabInsertBi = "";
            TabInsertCargo = "";
            TabInsertContacto = "";
            TabInsertContribuinte = "";
            TabInsertDataAdmissao = DateTime.Today;

            TabEditID = "";
            TabEditNome = "";
            TabEditCargo = "";
            TabEditContacto = "";
            TabEditContribuinte = "";
            TabEditBi = "";
            TabEditMorada = "";

            TabRemoveID = "";
            TabRemoveNome = "";
            TabRemoveCargo = "";
            TabRemoveContacto = "";
        }
    }
}
