using System;
using MyWindow.Controller;
using System.Windows.Forms;

namespace MyWindow
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(MainController.Start());
            
        }
    }
}
