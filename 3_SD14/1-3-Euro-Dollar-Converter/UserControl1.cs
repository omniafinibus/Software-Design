using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Euro_Dollar_converter
{
    public partial class UserControl1: UserControl
    {
        double euro, dollar;
        public UserControl1()
        {
            InitializeComponent();
            this.Text = "Currency converter";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            euro = Convert.ToDouble(textBox2.Text) / Convert.ToDouble(numericUpDown1.Text);
            textBox1.Text = Convert.ToString(euro);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dollar = Convert.ToDouble(numericUpDown1.Text) * Convert.ToDouble(textBox1.Text);
            textBox2.Text = Convert.ToString(dollar);
        }
    }
}
