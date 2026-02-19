using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task1OOP
{
    public partial class Form1 : Form
    {
        private double x = 1.23, y = 15.4, z = 252;

        public double g(double x, double y, double z)
        {
            double h1 = Math.Pow((x + 1), -1 / Math.Sin(z) );
            double otv = Math.Pow(y, x + 1) / (Math.Pow(Math.Abs(y - 2), 1.0 / 3.0) + 3) + (x + y/2) / (2 * Math.Abs(x+y) )  * h1;
            return otv;
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                x = double.Parse(textBox1.Text);
                y = double.Parse(textBox2.Text);
                z = double.Parse(textBox3.Text);

                textBox4.Text = "Ответ: " + g(x, y, z); 

            }
            catch (Exception)
            {
                textBox4.Text = "Неверный формат данных!";
            
            }
            



        }

        private void button2_Click(object sender, EventArgs e)
        {
            x = 1.23; y = 15.4; z = 252;
            textBox4.Text = "Ответ: " + g(x, y, z);
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
