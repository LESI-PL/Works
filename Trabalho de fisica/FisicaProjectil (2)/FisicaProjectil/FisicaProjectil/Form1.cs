using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FisicaProjectil
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLaunch_Click(object sender, EventArgs e)
        {
            double vInitial, vX, alcance, alturaMax;

            Cannonball cannon = new Cannonball();

            cannon.X = 30.0;
            cannon.Y = 20.0;




            cannon.Angulo = 34;
            lblResultAngulo.Text = String.Format("{0} º", cannon.Angulo.ToString("0.##"));





            cannon.InicialVelocity();
            lblResultV0.Text = String.Format("{0} m/s", cannon.V0.ToString("0.###"));


            cannon.TimeTotal = cannon.TimeOfMovement(cannon.V0);
            lblResultTime.Text = String.Format("{0} s", cannon.TimeTotal.ToString("0.##"));




            vX = cannon.VelocityX();
            alturaMax = cannon.MaxHeigth(cannon.V0);
            alcance = cannon.Maxlength(cannon.TimeTotal, cannon.V0);
            lblResultX.Text = String.Format("{0} m/s", vX.ToString("0.##"));
            lbAlturaMax.Text = String.Format("{0} m", alturaMax.ToString("0.##"));
            lbAlcanceMax.Text = String.Format("{0} m", alcance.ToString("0.##"));

            DrawVelocityY(cannon.TimeTotal,cannon,vX);
            
           

        }

        private void DrawVelocityY(double time, Cannonball obj,double vx)
        {
            double vy;

            for (double i = 0.0; i <= time; i += 0.01)
            {
                vy = obj.VelocityY(i);
                lblResultY.Text = String.Format("{0} m/s", obj.VelocityY(i).ToString("0.##"));
                lbVelToatal.Text= String.Format("{0} m/s", obj.VelocityTotal(vx,vy).ToString("0.##"));
                panel1.Refresh();

                

            }

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
