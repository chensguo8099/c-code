using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验3_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double num = 0;
            string mes = "error input";
            char op = Convert.ToChar(oper.Text);
            switch (op) {
                case '+':
                    num = Convert.ToDouble(num_a.Text) + Convert.ToDouble(num_b.Text);
                    break;
                case '-':
                    num = Convert.ToDouble(num_a.Text) - Convert.ToDouble(num_b.Text);
                    break;
                case '*':
                    num = Convert.ToDouble(num_a.Text) * Convert.ToDouble(num_b.Text);
                    break;
                case '/':
                    num = Convert.ToDouble(num_a.Text) / Convert.ToDouble(num_b.Text);
                    break;
                default:
                    MessageBox.Show(mes.ToString());
                    break;
            }
            textBox4.Text = num.ToString();
        }
    }
}
