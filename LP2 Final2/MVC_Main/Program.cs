using System;
using MVC_Controller;
using MVC_Model;
using MVC_View;

namespace MVC_Main
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Funcionarios f = new Funcionarios();
            
            MainView view = new  MainView(f);
            view.Visible = false;
            
            MainController controller = new MainController(view);
            
            view.ShowDialog();
        }
    }
}
