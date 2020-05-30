using MyWindow.Controller;
using System;
using System.Windows.Forms;

namespace MyWindow
{
    public partial class Form1 : Form
    {
        MainController mc = new MainController();
        ListView[] listasFunc = new ListView[3];
        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listasFunc[0] = tabFuncListViewListar;
            listasFunc[1] = tabRemovListView;
            listasFunc[2] = fTabEditListView;
            mc.UpdateLists(listasFunc,out listasFunc);            
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
            bool estado;
            estado = mc.InsereFuncionario(tabInsertTxtBxBi.Text, 
                                 tabInsertTxtBxNome.Text, 
                                 tabInsertTxtBxContri.Text, 
                                 tabInsertTxtBxCargo.Text, 
                                 tabInsertdateTimePicker.Value, 
                                 tabInsertTxtBxMorada.Text, 
                                 tabInsertTxtBxContacto.Text);
            if (estado)
            {
                MessageBox.Show("Dados inseridos!");
                tabInsertTxtBxBi.Text = "";
                tabInsertTxtBxNome.Text = "";
                tabInsertTxtBxContri.Text = "";
                tabInsertTxtBxCargo.Text = "";
                tabInsertTxtBxMorada.Text = "";
                tabInsertTxtBxContacto.Text = "";
                mc.UpdateLists(listasFunc, out listasFunc);
            }
            else MessageBox.Show("Erro ao inserir os dados");
            
            
        }

        private void fTabEditListView_MouseClick(object sender, MouseEventArgs e)
        {
            string[] dados = MainController.GetSelectedItem(fTabEditListView);  
            fTabEditTbxID.Text = dados[0];
            fTabEditTbxNome.Text = dados[1];
            fTabEditTbxCargo.Text = dados[2];
            fTabEditTbxContacto.Text = dados[3];
            fTabEditTbxContribu.Text = dados[4];
            fTabEditTbxBI.Text = dados[5];
            fTabEditTbxMorada.Text = dados[6];
        }

        private void picBXBackBtn_Click(object sender, EventArgs e)
        {
            pnlFuncionarios.Visible = false;
        }

        private void fTabEditBtnEditar_Click(object sender, EventArgs e)
        {
            mc.EditarFuncionario(fTabEditTbxID.Text,
                                 fTabEditTbxBI.Text,
                                 fTabEditTbxNome.Text,
                                 fTabEditTbxContribu.Text,
                                 fTabEditTbxCargo.Text,
                                 fTabEditTbxMorada.Text,
                                 fTabEditTbxContacto.Text                                                                
                                 );
            mc.UpdateLists(listasFunc, out listasFunc);
        }
    }
}
