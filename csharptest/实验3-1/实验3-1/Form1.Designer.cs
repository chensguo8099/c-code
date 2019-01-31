namespace 实验3_1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.num_a = new System.Windows.Forms.TextBox();
            this.oper = new System.Windows.Forms.TextBox();
            this.num_b = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.num_a_label = new System.Windows.Forms.Label();
            this.oper_label = new System.Windows.Forms.Label();
            this.num_b_label = new System.Windows.Forms.Label();
            this.num_result = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(75, 229);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(130, 52);
            this.button1.TabIndex = 0;
            this.button1.Text = "计算";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(274, 229);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(130, 52);
            this.button2.TabIndex = 1;
            this.button2.Text = "取消";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // num_a
            // 
            this.num_a.Location = new System.Drawing.Point(180, 54);
            this.num_a.Name = "num_a";
            this.num_a.Size = new System.Drawing.Size(224, 25);
            this.num_a.TabIndex = 2;
            // 
            // oper
            // 
            this.oper.Location = new System.Drawing.Point(180, 110);
            this.oper.Name = "oper";
            this.oper.Size = new System.Drawing.Size(224, 25);
            this.oper.TabIndex = 3;
            // 
            // num_b
            // 
            this.num_b.Location = new System.Drawing.Point(180, 166);
            this.num_b.Name = "num_b";
            this.num_b.Size = new System.Drawing.Size(224, 25);
            this.num_b.TabIndex = 4;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(180, 315);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(224, 25);
            this.textBox4.TabIndex = 5;
            // 
            // num_a_label
            // 
            this.num_a_label.AutoSize = true;
            this.num_a_label.Location = new System.Drawing.Point(72, 57);
            this.num_a_label.Name = "num_a_label";
            this.num_a_label.Size = new System.Drawing.Size(60, 15);
            this.num_a_label.TabIndex = 6;
            this.num_a_label.Text = "数字a：";
            // 
            // oper_label
            // 
            this.oper_label.AutoSize = true;
            this.oper_label.Location = new System.Drawing.Point(72, 113);
            this.oper_label.Name = "oper_label";
            this.oper_label.Size = new System.Drawing.Size(52, 15);
            this.oper_label.TabIndex = 7;
            this.oper_label.Text = "运算符";
            // 
            // num_b_label
            // 
            this.num_b_label.AutoSize = true;
            this.num_b_label.Location = new System.Drawing.Point(72, 169);
            this.num_b_label.Name = "num_b_label";
            this.num_b_label.Size = new System.Drawing.Size(60, 15);
            this.num_b_label.TabIndex = 8;
            this.num_b_label.Text = "数字b：";
            // 
            // num_result
            // 
            this.num_result.AutoSize = true;
            this.num_result.Location = new System.Drawing.Point(72, 318);
            this.num_result.Name = "num_result";
            this.num_result.Size = new System.Drawing.Size(52, 15);
            this.num_result.TabIndex = 9;
            this.num_result.Text = "结果：";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(501, 429);
            this.Controls.Add(this.num_result);
            this.Controls.Add(this.num_b_label);
            this.Controls.Add(this.oper_label);
            this.Controls.Add(this.num_a_label);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.num_b);
            this.Controls.Add(this.oper);
            this.Controls.Add(this.num_a);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox num_a;
        private System.Windows.Forms.TextBox oper;
        private System.Windows.Forms.TextBox num_b;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label num_a_label;
        private System.Windows.Forms.Label oper_label;
        private System.Windows.Forms.Label num_b_label;
        private System.Windows.Forms.Label num_result;
    }
}

