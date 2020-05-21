using MyWindow.Controller;
using System;
using System.Windows.Forms;

namespace MyWindow
{
    public partial class Form1 : Form
    {
        MainController mc = new MainController();
        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            mc.InsereFuncionario("afjhs", "AAAA", "187297", "Paneleiro", new DateTime(2050, 9, 8), "Rua Amarela 345", "26936");
            mc.InsereFuncionario("hdhd", "BBBB", "74894", "Conas", new DateTime(2100, 10, 20), "Rua Verde 345", "165456");
            tabFuncListViewListar = mc.ListaFuncionarios(tabFuncListViewListar);
            tabRemovListView = mc.ListaFuncionarios(tabRemovListView);
            fTabEditListView = mc.ListaFuncionarios(fTabEditListView);
            
            
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

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pnlFuncionarios.Visible = false;
        }

        private void tabInsertBtnCriar_Click(object sender, EventArgs e)
        {
            int i, j;
            mc.InsereFuncionario(tabInsertTxtBxBi.Text, 
                                 tabInsertTxtBxNome.Text, 
                                 tabInsertTxtBxContri.Text, 
                                 tabInsertTxtBxCargo.Text, 
                                 tabInsertdateTimePicker.Value, 
                                 tabInsertTxtBxMorada.Text, 
                                 tabInsertTxtBxContacto.Text);
            tabInsertTxtBxBi.Text = "";
            tabInsertTxtBxNome.Text = "";
            tabInsertTxtBxContri.Text = "";
            tabInsertTxtBxCargo.Text = "";
            tabInsertTxtBxMorada.Text = "";
            tabInsertTxtBxContacto.Text = "";
            tabFuncListViewListar = mc.ListaFuncionarios(tabFuncListViewListar);
            mc.VariosOut(10, out i,out j);
            MessageBox.Show("i:"+i.ToString()+"J:"+ j.ToString());
        }

        private void fTabEditListView_MouseClick(object sender, MouseEventArgs e)
        {
            string id = fTabEditListView.SelectedItems[0].SubItems[0].Text;

            textBox12.Text = id;
        }
    }
}
