using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Millage_Calculator
{
    public partial class UserControl1: UserControl
    {
        public UserControl1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(Convert.ToDouble(numericUpDown1.Text) * 21.5);
            textBox2.Text = Convert.ToString(Convert.ToDouble(numericUpDown1.Text) * 26.8);
        }
    }
}
