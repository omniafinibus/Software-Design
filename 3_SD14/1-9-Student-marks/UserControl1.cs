using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudentMarks
{
    public partial class UserControl1: UserControl
    {
        int failed = 0;
        int passed = 0;
        int amount;
        double sum = 0;
        public UserControl1()
        {
            InitializeComponent();
            this.Text = "Mark processing";
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            listBox1.Items.Add(Convert.ToString(textBox1.Text));
            if (Convert.ToDouble(textBox1.Text) < 5.5)
            {
                failed++;
            }
            else if (Convert.ToDouble(textBox1.Text) >= 5.5)
            {
                passed++;
            }
            sum += Convert.ToDouble(textBox1.Text);
        }

        private void resultsButton_Click(object sender, EventArgs e)
        {
            amount = listBox1.Items.Count;
            if (amount != 0)
            {
                averageMark.Text = Convert.ToString(sum / amount);
            }
            else
            {
                averageMark.Text = "0";
                failed = 0;
                passed = 0;
            }
            numOfMarks.Text = Convert.ToString(amount);
            numOfFails.Text = Convert.ToString(failed);
            numOfPasses.Text = Convert.ToString(passed);
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void stopButton_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Are you sure about that?", "Exit confirmation", MessageBoxButtons.OKCancel);
            Application.Exit();
        }
    }
}
