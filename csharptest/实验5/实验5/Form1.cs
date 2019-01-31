using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public abstract class Student
        {
            protected string name;
            protected int age;
            public static int number;
            public Student(string name, int age)
            {
                this.name = name;
                this.age = age;
                number++;
            }
            public string Name { get { return name; } }
            public abstract double Average();
        }

        public class Pupil : Student
        {
            protected double chinese;
            protected double math;
            public Pupil(string name, int age, double chinese, double math) : base(name, age)
            {
                this.chinese = chinese;
                this.math = math;
            }
            public override double Average()
            {
                return (chinese + math) / 2;
            }
        }
        public class highSchoolStudent : Pupil
        {
            protected double english;
            public highSchoolStudent(string name, int age, double chinese, double math, double english) : base(name, age, chinese, math)
            {
                this.english = english;
            }
            public override double Average()
            {
                return (chinese + math + english) / 3;
            }
        }
        public class universityStudent : Student
        {
            protected double bixiu;
            protected double xuanxiu;
            public universityStudent(string name, int age, double bixiu, double xuanxiu) : base(name, age) {
                this.bixiu = bixiu;
                this.xuanxiu = xuanxiu;
            }
            public override double Average()
            {
                return (bixiu + xuanxiu) / 2;
            }
        }
        public void DisplayPupil(Student s)
        {
            textBox6.Text += "总人数:" + Student.number + ",姓名:" + s.Name + ",平均成绩:" + s.Average() + "\r\n";
        }
        public void DisplayhighSchoolStudent(highSchoolStudent s)
        {
            textBox6.Text += "总人数:" + highSchoolStudent.number + ",姓名:" + s.Name + ",平均成绩:" + s.Average() + "\r\n";
        }
        public void DisplayuniversityStudent(universityStudent s)
        {
            textBox6.Text += "总人数:" + +universityStudent.number + ",姓名:" + s.Name + ",平均成绩:" + s.Average() + "\r\n";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            string na = Convert.ToString(textBox1.Text);
            int ag = Convert.ToInt32(textBox2.Text);
            double chi = Convert.ToDouble(textBox3.Text);
            double mat = Convert.ToDouble(textBox4.Text);
            double num = Student.number;
            Pupil msg = new Pupil(na, ag, chi, mat);
            DisplayPupil(msg);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string na = Convert.ToString(textBox1.Text);
            int ag = Convert.ToInt32(textBox2.Text);
            double chi = Convert.ToDouble(textBox3.Text);
            double mat = Convert.ToDouble(textBox4.Text);
            double eng = Convert.ToDouble(textBox5.Text);
            double num = Student.number;
            highSchoolStudent msg = new highSchoolStudent(na, ag, chi, mat, eng);
            DisplayhighSchoolStudent(msg);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string na = Convert.ToString(textBox1.Text);
            int ag = Convert.ToInt32(textBox2.Text);
            double bix = Convert.ToDouble(textBox3.Text);
            double xux = Convert.ToDouble(textBox4.Text);
            double num = Student.number;
            universityStudent msg = new universityStudent(na, ag, bix, xux);
            DisplayuniversityStudent(msg);
        }
    }
}
