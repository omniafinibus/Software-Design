namespace StudentMarks
{
    partial class UserControl1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.numOfMarks = new System.Windows.Forms.TextBox();
            this.numOfFails = new System.Windows.Forms.TextBox();
            this.numOfPasses = new System.Windows.Forms.TextBox();
            this.averageMark = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.stopButton = new System.Windows.Forms.Button();
            this.clearButton = new System.Windows.Forms.Button();
            this.addButton = new System.Windows.Forms.Button();
            this.resultsButton = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // numOfMarks
            // 
            this.numOfMarks.Enabled = false;
            this.numOfMarks.Location = new System.Drawing.Point(305, 20);
            this.numOfMarks.Name = "numOfMarks";
            this.numOfMarks.Size = new System.Drawing.Size(100, 20);
            this.numOfMarks.TabIndex = 0;
            // 
            // numOfFails
            // 
            this.numOfFails.Enabled = false;
            this.numOfFails.ForeColor = System.Drawing.Color.Red;
            this.numOfFails.Location = new System.Drawing.Point(305, 46);
            this.numOfFails.Name = "numOfFails";
            this.numOfFails.Size = new System.Drawing.Size(100, 20);
            this.numOfFails.TabIndex = 1;
            // 
            // numOfPasses
            // 
            this.numOfPasses.Enabled = false;
            this.numOfPasses.Location = new System.Drawing.Point(305, 72);
            this.numOfPasses.Name = "numOfPasses";
            this.numOfPasses.Size = new System.Drawing.Size(100, 20);
            this.numOfPasses.TabIndex = 2;
            // 
            // averageMark
            // 
            this.averageMark.Enabled = false;
            this.averageMark.Location = new System.Drawing.Point(305, 98);
            this.averageMark.Name = "averageMark";
            this.averageMark.Size = new System.Drawing.Size(100, 20);
            this.averageMark.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(185, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(114, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "Amount of marks";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(194, 49);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(105, 17);
            this.label2.TabIndex = 5;
            this.label2.Text = "Amount of Fails";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(177, 75);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(122, 17);
            this.label3.TabIndex = 6;
            this.label3.Text = "Amount of Passes";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(203, 101);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(96, 17);
            this.label4.TabIndex = 7;
            this.label4.Text = "Average mark";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(108, 46);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(63, 95);
            this.listBox1.TabIndex = 8;
            // 
            // stopButton
            // 
            this.stopButton.Location = new System.Drawing.Point(17, 107);
            this.stopButton.Name = "stopButton";
            this.stopButton.Size = new System.Drawing.Size(75, 23);
            this.stopButton.TabIndex = 9;
            this.stopButton.Text = "Stop";
            this.stopButton.UseVisualStyleBackColor = true;
            this.stopButton.Click += new System.EventHandler(this.stopButton_Click);
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(17, 78);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(75, 23);
            this.clearButton.TabIndex = 10;
            this.clearButton.Text = "Clear";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point(17, 20);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(75, 23);
            this.addButton.TabIndex = 11;
            this.addButton.Text = "Add";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // resultsButton
            // 
            this.resultsButton.Location = new System.Drawing.Point(17, 49);
            this.resultsButton.Name = "resultsButton";
            this.resultsButton.Size = new System.Drawing.Size(75, 23);
            this.resultsButton.TabIndex = 12;
            this.resultsButton.Text = "Results";
            this.resultsButton.UseVisualStyleBackColor = true;
            this.resultsButton.Click += new System.EventHandler(this.resultsButton_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(108, 17);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(63, 20);
            this.textBox1.TabIndex = 13;
            // 
            // UserControl1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.resultsButton);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.stopButton);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.averageMark);
            this.Controls.Add(this.numOfPasses);
            this.Controls.Add(this.numOfFails);
            this.Controls.Add(this.numOfMarks);
            this.Name = "UserControl1";
            this.Size = new System.Drawing.Size(427, 156);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox numOfMarks;
        private System.Windows.Forms.TextBox numOfFails;
        private System.Windows.Forms.TextBox numOfPasses;
        private System.Windows.Forms.TextBox averageMark;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button stopButton;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button resultsButton;
        private System.Windows.Forms.TextBox textBox1;
    }
}
