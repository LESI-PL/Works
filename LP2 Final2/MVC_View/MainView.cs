using System;
using System.Data.OleDb;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using MVC_Controller;
using MVC_Model;

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
        
        #region Tab Remove Funcionario
        public ListView TabRemoveListView { get => tabRemovListView; set => tabRemovListView = value; }
        #endregion

        #region Tab Listar Funcionarios
        public ListView TabListarListView { get => tabFuncListViewListar; set => tabFuncListViewListar = value; }
        #endregion

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

        private void tabInsertBtnCriar_Click(object sender, EventArgs e)
        {
            mc.InsereFuncionario();            
        }

        private void fTabEditListView_MouseClick(object sender, MouseEventArgs e)
        {
            mc.GetSelectedItem(fTabEditListView.ToString());
        }

        private void picBXBackBtn_Click(object sender, EventArgs e)
        {
            pnlFuncionarios.Visible = false;
        }

        private void fTabEditBtnEditar_Click(object sender, EventArgs e)
        {
            Funcionario f = new Funcionario();
            mc.EditarFuncionario(f);
        }

        public void PreencheCampo()
        {
            string[] dados = new string[8];
            try
            {
                //
                for (int i = 0; i < fTabEditListView.SelectedItems[0].SubItems.Count; i++)
                {
                    dados[i] = fTabEditListView.SelectedItems[0].SubItems[i].Text;
                }

                //return lv.SelectedItems[0].SubItems[0].Text;

            }
            catch (Exception ee)
            {
                throw new Exception(ee.Message);
            }
            fTabEditTbxID.Text = dados[0];
            fTabEditTbxNome.Text = dados[1];
            fTabEditTbxCargo.Text = dados[2];
            fTabEditTbxContacto.Text = dados[3];
            fTabEditTbxContribu.Text = dados[4];
            fTabEditTbxBI.Text = dados[5];
            fTabEditTbxMorada.Text = dados[6];
        }

        public bool UpdateLists(ListView[] listasIn, out ListView[] listasOut)
        {
            throw new NotImplementedException();
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








        #region Cenas Para Analisar
        //public ListView ListaFuncionarios(ListView lv)
        //{
        //    return fs.GetList(lv);

        //}









        //public bool UpdateLists(ListView[] listasIn, out ListView[] listasOut)
        //{
        //    ListView[] lists = new ListView[3];
        //    lists[0] = GetList(listasIn[0]);
        //    lists[1] = GetList(listasIn[1]);
        //    lists[2] = GetList(listasIn[2]);
        //    listasOut = lists;

        //    if (lists[0] != null && lists[1] != null && lists[2] != null) { return true; }
        //    return false;
        //}

        #endregion
    }
}
