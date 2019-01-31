using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验4_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int i = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (i == 0)
                    i = 60;
            if (i > 30)
            {
                pictureBox4.Image = this.imageList1.Images[7];
                pictureBox5.Image = this.imageList1.Images[9];
                pictureBox6.Image = this.imageList1.Images[9];
                this.label2.ForeColor = Color.Red;
                this.label2.Text = (100 + (i - 30)).ToString().Substring(1, 2);

                pictureBox10.Image = this.imageList1.Images[1];
                pictureBox11.Image = this.imageList1.Images[5];
                pictureBox12.Image = this.imageList1.Images[5];
                this.label4.ForeColor = Color.Red;
                this.label4.Text = (100 + (i - 30)).ToString().Substring(1, 2);


                if (i > 43)
                {
                    pictureBox1.Image = this.imageList1.Images[5];
                    pictureBox2.Image = this.imageList1.Images[3];
                    pictureBox3.Image = this.imageList1.Images[3];//设置上路口上上2灯为green
                    this.label1.ForeColor = Color.Green;
                    this.label1.Text = (100 + (i - 30) - 13).ToString().Substring(1, 2);

                    pictureBox7.Image = this.imageList1.Images[9];
                    pictureBox8.Image = this.imageList1.Images[0];
                    pictureBox9.Image = this.imageList1.Images[0];//设置下路口下下2灯为green
                    this.label3.ForeColor = Color.Green;
                    this.label3.Text = (100 + (i - 30) - 13).ToString().Substring(1, 2);
                }
                else
                {
                    if (i > 40)
                    {
                        pictureBox2.Image = this.imageList1.Images[12];
                        pictureBox3.Image = this.imageList1.Images[12];//上为黄灯
                        pictureBox8.Image = this.imageList1.Images[2]; //下为黄灯
                        pictureBox9.Image = this.imageList1.Images[2];
                        this.label1.ForeColor = Color.Green;
                        this.label3.ForeColor = Color.Green;
                        this.label1.Text = (100 + (i - 30) - 10).ToString().Substring(1, 2);
                        this.label3.Text = (100 + (i - 30) - 10).ToString().Substring(1, 2);
                    }
                    else if (i > 33)
                    {
                        pictureBox2.Image = this.imageList1.Images[7];
                        pictureBox3.Image = this.imageList1.Images[7];//上置为红灯
                        pictureBox8.Image = this.imageList1.Images[1];
                        pictureBox9.Image = this.imageList1.Images[1];//下置为红灯
                        pictureBox1.Image = this.imageList1.Images[4];//上左转灯置为绿
                        pictureBox7.Image = this.imageList1.Images[8];//下右转灯置为绿
                        this.label1.ForeColor = Color.Green;
                        this.label3.ForeColor = Color.Green;
                        this.label1.Text = (100 + (i - 30)).ToString().Substring(1, 2);
                        this.label3.Text = (100 + (i - 30)).ToString().Substring(1, 2);
                    }
                    else if (i > 30)
                    {
                        pictureBox1.Image = this.imageList1.Images[6];
                        pictureBox7.Image = this.imageList1.Images[10];
                        this.label1.ForeColor = Color.Green;
                        this.label3.ForeColor = Color.Green;
                        this.label1.Text = (100 + (i - 30)).ToString().Substring(1, 2);
                        this.label3.Text = (100 + (i - 30)).ToString().Substring(1, 2);

                    }

                }
            }
            else if (i > 0)
            {
                pictureBox1.Image = this.imageList1.Images[5];
                pictureBox2.Image = this.imageList1.Images[7];
                pictureBox3.Image = this.imageList1.Images[7];
                this.label1.ForeColor = Color.Red;
                this.label1.Text = (100 + i).ToString().Substring(1, 2);

                pictureBox7.Image = this.imageList1.Images[9];
                pictureBox8.Image = this.imageList1.Images[1];
                pictureBox9.Image = this.imageList1.Images[1];
                this.label3.ForeColor = Color.Red;
                this.label3.Text = (100 + i).ToString().Substring(1, 2);


                if (i > 13)
                {
                    pictureBox4.Image = this.imageList1.Images[7];
                    pictureBox5.Image = this.imageList1.Images[8];
                    pictureBox6.Image = this.imageList1.Images[8];//设置右路口右右2灯为green
                    this.label2.ForeColor = Color.Green;
                    this.label2.Text = (100 + (i - 13)).ToString().Substring(1, 2);

                    pictureBox10.Image = this.imageList1.Images[1];
                    pictureBox11.Image = this.imageList1.Images[4];
                    pictureBox12.Image = this.imageList1.Images[4];//设置左路口坐坐2灯为green
                    this.label4.ForeColor = Color.Green;
                    this.label4.Text = (100 + (i - 13)).ToString().Substring(1, 2);
                }
                else
                {
                    if (i > 10)
                    {
                        pictureBox5.Image = this.imageList1.Images[10];
                        pictureBox6.Image = this.imageList1.Images[10];//右为黄灯
                        pictureBox11.Image = this.imageList1.Images[6]; //左为黄灯
                        pictureBox12.Image = this.imageList1.Images[6];
                        this.label2.ForeColor = Color.Green;
                        this.label4.ForeColor = Color.Green;
                        this.label2.Text = (100 + (i - 10)).ToString().Substring(1, 2);
                        this.label4.Text = (100 + (i - 10)).ToString().Substring(1, 2);
                    }
                    else if (i > 3)
                    {
                        pictureBox5.Image = this.imageList1.Images[9];
                        pictureBox6.Image = this.imageList1.Images[9];//右置为红灯
                        pictureBox11.Image = this.imageList1.Images[5];
                        pictureBox12.Image = this.imageList1.Images[5];//左置为红灯
                        pictureBox4.Image = this.imageList1.Images[3];//上左转灯置为绿
                        pictureBox10.Image = this.imageList1.Images[0];//下右转灯置为绿
                        this.label2.ForeColor = Color.Green;
                        this.label4.ForeColor = Color.Green;
                        this.label2.Text = (100 + i).ToString().Substring(1, 2);
                        this.label4.Text = (100 + i).ToString().Substring(1, 2);
                    }
                    else if (i > 0)
                    {
                        pictureBox4.Image = this.imageList1.Images[12];
                        pictureBox10.Image = this.imageList1.Images[2];
                        this.label2.ForeColor = Color.Green;
                        this.label4.ForeColor = Color.Green;
                        this.label2.Text = (100 + i).ToString().Substring(1, 2);
                        this.label4.Text = (100 + i).ToString().Substring(1, 2);
                    }
                }
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
            else
            {
                timer1.Enabled = false;
                button1.Text = "start";
            }
        }
    }
}
