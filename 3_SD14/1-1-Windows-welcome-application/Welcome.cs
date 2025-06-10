using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Welcome_Meme
{
    public partial class Welcome: UserControl
    {
        int clicks = 0;
        public Welcome()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            clicks++;

            if (clicks == 1)
            {
                pictureBox2.SendToBack();
                button1.Text = "General Kenobi!";
            }
            else if (clicks == 2)
            {
                System.Windows.Forms.Application.ExitThread();
            }
        }
    }
}
