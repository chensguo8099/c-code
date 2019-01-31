using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Image img1 = Image.FromFile(@"D:\我的文档\Visual Studio 2017\Projects\实验三\1.jpg");//green
        Image img2 = Image.FromFile(@"D:\我的文档\Visual Studio 2017\Projects\实验三\2.jpg");//red
        Image img3 = Image.FromFile(@"D:\我的文档\Visual Studio 2017\Projects\实验三\3.jpg");//yellow
        int i = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (i == 0)
                i = 20;
            if (i > 13 && i <= 20)
            {
                pictureBox1.Image = img2;
                pictureBox4.Image = img2;
                pictureBox2.Image = img1;
                pictureBox3.Image = img1;
                int j = i - 10;
                int k = i - 13;
                label1.Text = j.ToString();//初始 上下为0
                label4.Text = j.ToString();

                label2.Text = k.ToString();
                label3.Text = k.ToString();
            }

            else if (i > 10 && i <= 13)
            {
                pictureBox1.Image = img2;
                pictureBox4.Image = img2;
                pictureBox2.Image = img3;
                pictureBox3.Image = img3;
                int j = i - 10;
                int k = i - 10;
                label1.Text = j.ToString();
                label4.Text = j.ToString();

                label2.Text = k.ToString();
                label3.Text = k.ToString();
            }
            else if (i > 3 && i <= 10) {
                pictureBox1.Image = img1;
                pictureBox4.Image = img1;
                pictureBox2.Image = img2;
                pictureBox3.Image = img2;
                int j = i - 3;
                int k = i;
                label1.Text = j.ToString();
                label4.Text = j.ToString();
                label2.Text = k.ToString();
                label3.Text = k.ToString();


            }
            else
            {
                pictureBox1.Image = img3;
                pictureBox4.Image = img3;
                pictureBox2.Image = img2;
                pictureBox3.Image = img2;
                int j = i;
                int k = i;
                label1.Text = j.ToString();
                label4.Text = j.ToString();
                label2.Text = k.ToString();
                label3.Text = k.ToString();
            }
            i--;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (button1.Text == "start")
            {
                timer1.Enabled = true;
                button1.Text = "stop";
            }
            else {
                timer1.Enabled = false;
                button1.Text = "start";
            }
        }
    }
}
