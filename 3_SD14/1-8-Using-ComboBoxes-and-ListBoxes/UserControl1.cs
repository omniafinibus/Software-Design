using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.ComboBox;

namespace Using_Combo_Boxes
{
    public partial class UserControl1: UserControl
    {
        public UserControl1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Convert.ToString(comboBox1.SelectedItem));
            listBox1.Items.Add(Convert.ToString(comboBox1.SelectedItem));
            comboBox1.Items.RemoveAt(comboBox1.SelectedIndex);

            int amount = comboBox1.Items.Count;
            if (amount == 0)
            {
                MessageBox.Show("Das pech lijst weg.");
                Application.Exit();
            }
        }
    }
}
