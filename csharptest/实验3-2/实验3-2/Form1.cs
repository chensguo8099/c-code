using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验3_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double sum = Convert.ToDouble(num_a.Text) + Convert.ToDouble(num_b.Text);
            label3.Text = sum.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double jian = Convert.ToDouble(num_a.Text) - Convert.ToDouble(num_b.Text);
            label3.Text = jian.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double cheng = Convert.ToDouble(num_a.Text) * Convert.ToDouble(num_b.Text);
            label3.Text = cheng.ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            double chu;
            if (Convert.ToDouble(num_b.Text) == 0)
                label3.Text = "分母不能为0".ToString();
            else
            {

                chu = Convert.ToDouble(num_a.Text) / Convert.ToDouble(num_b.Text);
            label3.Text = chu.ToString();
                 }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            double cifang = Math.Pow(Convert.ToDouble(num_a.Text), Convert.ToDouble(num_b.Text));
            label3.Text = cifang.ToString();
        }
    }
}
