using System;
using System.Windows.Forms;

namespace FisicaProjectil
{
    class Cannonball
    {
        #region Atributos
        double angulo;
        double anguloRad;
        const double gravidade = 9.8;
        double timeTotal;
        double cos;
        double sen;
        double tan;
        double v0;
        double vx;
        double vy;
        double x0;
        double y0;
        double x;
        double y;
        #endregion

        #region Construtor
        public Cannonball()
        {

        }

        public Cannonball(double angulo, double x, double y)
        {
            this.angulo = angulo;
            this.x = x;
            this.y = y;
        }
        #endregion

        #region Properties
        /// <summary>
        /// Membro que fornece um mecanismo que permite ler e escrever um valor de um campo
        /// </summary>
        public double Angulo
        {
            get => angulo;
            set
            {
                if (value < 90 && value > 0)
                {
                    if (AngleVerification(value) == true)
                    {
                        
                        angulo = value;
                        Cos = angulo;
                        Sen = angulo;
                        Tan = angulo;
                        
                    }
                    else
                    {
                        angulo = Math.Round(GiveRightAngle());
                        Cos = angulo;
                        Sen = angulo;
                        Tan = angulo;
                    }
                }
                else
                {
                    
                    angulo = Math.Round(GiveRightAngle());
                    MessageBox.Show("Angulo errado!\nSerá corrigido para um angulo minimo"+"\nAngulo:"+angulo);
                    Cos = angulo;
                    Sen = angulo;
                    Tan = angulo;
                }
                

            }
        }
        public double TimeTotal
        {
            get { return timeTotal; }
            set { timeTotal = value; }
        }
        /// <summary>
        /// Membro que fornece um mecanismo que permite ler e escrever um valor de um campo
        /// </summary>
        public double X
        {
            get => x;
            set
            {
                if (value >= 0) { x = value; }
            }
        }

        /// <summary>
        /// Membro que fornece um mecanismo que permite ler e escrever um valor de um campo
        /// </summary>
        public double Y
        {
            get => y;
            set
            {
                if (value > 0) { y = value; }
            }
        }

        /// <summary>
        /// Membro que fornece um mecanismo que permite ler e escrever um valor de um campo
        /// </summary>
        public double Gravidade
        {
            get => gravidade;
        }
        public double V0
        {
            get { return v0; }
            set { v0 = value; }
        }

        public double Cos
        {
            get { return cos; }
            set { cos = Math.Cos(DegToRad(value)); }
        }
        public double Sen
        {
            get { return sen; }
            set { sen = Math.Sin(DegToRad(value)); }
        }
        public double Tan
        {
            get { return tan; }
            set { tan = Math.Tan(DegToRad(value)); }
        }
        #endregion

        #region Metodos
        public double GiveRightAngle()
        {
            double valor;
            valor = Math.Atan(Y / X);
            valor = RadToDeg(valor);
            return valor;
        }
        public bool AngleVerification(double angle)
        {
            double angleAux=0;
            angleAux = Math.Atan(Y/X);
            
            angleAux = angleAux * (180 / Math.PI);
            

            if (angle > angleAux)
            {
                return true;
            }
            return false;
        }

        /// <summary>
        /// Converte radianos em graus
        /// </summary>
        /// <param name="valor"> valor do angulo inserido pelo utilizador</param>
        /// <returns></returns>
        public double RadToDeg(double valor)
        {

            double aux = 0;
            

            aux = 180 / Math.PI;
            valor = valor * aux;

            return valor;
        }

        /// <summary>
        /// Converte Graus em Radianos
        /// </summary>
        /// <param name="valor"> valor do angulo inserido pelo utilizador </param>
        /// <returns></returns>
        public double DegToRad(double valor)
        {

            double aux = 0;
            
            aux = Math.PI / 180;
            valor = valor * aux;
            return valor;
        }

        public double getXLocation(double time)
        {
            double x0 = 0,xaux=0, angle=0;
            if (Angulo == 0)
            {
                return 0;
            }
            else
            {
                
                xaux= x0 + V0 * (Cos * time);
               
                return x;
            }
        }

        public double getYLocation(double time)
        {
            double y0 = 0, yaux = 0;
            if (time == 0)
            {
                return 0;
            }
            else
            {               
               
                yaux = y0 + v0 * (Sen * time) - ((Gravidade / 2) * (Math.Pow(time, 2)));
                return yaux;
            }
         
        }
        /// <summary>
        /// Calcula a velocidade inicial
        /// </summary>
        /// <returns> v0 =velocidade inicial </returns>
        public void InicialVelocity()
        {
            double gravity = Gravidade,tan,time;

            tan = (Tan *X)-Y;
            
            time = Math.Sqrt(tan / (gravity / 2));
            V0 = Math.Round(X / (time * Cos),2);
            
            
           
        }
        /// <summary>
        /// Calcula a velocidade segundo o eixo dos xx
        /// </summary>
        /// <param name="v0">velocidade inicial </param>
        /// <returns></returns>
        public double VelocityX()
        {
            return V0 * Cos;

        }

        /// <summary>
        /// Calcula a velocidade segundo o eixo dos yy
        /// </summary>
        /// <param name="v0"> velocidade incial </param>
        /// <param name="time"> tempo do movimento </param>
        /// <returns></returns>
        public double VelocityY(double tempo)
        {
            //0.5235987756
            
            return ((V0 * Sen) - (Gravidade * tempo));
        }

        /// <summary>
        /// Calcula o tempo total do movimento até atingir o solo
        /// </summary>
        /// <param name="v0"> velocidade inicial </param>
        /// <returns>tempo do movimento </returns>
        public double TimeOfMovement(double v0)
        {
            double a,b,c;

            a = -gravidade / 2;
            b =  v0 * Sen;
            c = 0;
            timeTotal = Resolvente(a,b,c);
            
            return timeTotal;
        }

        /// <summary>
        /// Calcula a velocidade total para qualquer instante
        /// </summary>
        /// <param name="vx"> velocidade segundo x </param>
        /// <param name="vy"> velocidade segundo y </param>
        /// <returns> velocidade total </returns>
        public double VelocityTotal(double vx, double vy)
        {
            double total1 = 0, total = 0;
            total1 = (Math.Pow(vx, 2)) + (Math.Pow(vy, 2));
            total = (Math.Sqrt(total1));
            return total;
        }
        /// <summary>
        /// Calcula a distancia maxima percorrida
        /// </summary>
        /// <param name="time"> tempo que demora a atingir o solo </param>
        /// <param name="v0"> velocidade inicial </param>
        /// <returns> distancia a total no eixo xx </returns>
        public double Maxlength(double time, double v0)
        {
            double x0 = 0;
            
            X = x0 + v0 * (Cos * time);
            return X;
        }

        /// <summary>
        /// Calcula o altura maxima
        /// </summary>
        /// <param name="v0"> velocidade inicial </param>
        /// <returns> altura maxima atingida </returns>
        public double MaxHeigth(double v0)
        {
            double time = 0, ymax=0, y0=0;
          
            time = (v0 * Sen) / Gravidade;
            ymax = y0 + (v0 * Sen * time) - ((Gravidade / 2) * (Math.Pow(time, 2)));
            return ymax;

        }
        public double Resolvente(double a, double b, double c)
        {

            //double delta = (b * b) - (4.0 * a * c);
            double delta;
            double r1 = (b * b)- (4 * a * c);
            delta = Math.Sqrt(r1);
           
            var x1 = Math.Round(((-(b)) + delta) / (2.0 * a),2);
            var x2 = Math.Round(((-(b)) - delta) / (2.0 * a),2);
           
            if (x1 <= 0)
            {
                return x2;
            }
            else
            {
                return x1;
            }
            
            

        }
        #endregion

    }

}
