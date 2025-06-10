using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace MusicPlayerGUI
{
    public partial class musicPlayerWindow : Form
    {
        /* Load music class */
        private music music = new music();

        /* global variables */
        private bool playState = false;
        private int currentTime = 0;
        private int previousTime = 0;
        private int repeatAllState = 0;
        private int totalTime = 0;
        private int index = 0;
        private string currentSong;
        private string previousSong;

        public musicPlayerWindow()
        {
            InitializeComponent();

            /* Disable all elements as long as the serial port is not set up */
            playPauseBtn.Enabled = false;
            nextBtn.Enabled = false;
            previousBtn.Enabled = false;
            repeatAllBtn.Enabled = false;
            shuffleBtn.Enabled = false;
            musicListLbx.Enabled = false;
            speedTrbr.Enabled = false;
            resetSpeedBtn.Enabled = false;

            /* Determine which serial ports are available */
            string[] ports = SerialPort.GetPortNames();

            /* Add the serial ports to the combobox */
            foreach (string port in ports)
            {
                comPortSettingsCbx.Items.Add(port);
            }

            /* get all possible music songs */
            for (int i = 0; i < 5; i++)
            {
                musicListLbx.Items.Add(music.getArduinoMusicSong(i));
            }

            /* set the "fur elise" cover on top */
            coverElisePbx.BringToFront();
        }

        private void comPortSettingsCbx_SelectedIndexChanged(object sender, EventArgs e)
        {
            /* Make sure the serial port is not open */
            if (serialPort1.IsOpen)
                serialPort1.Close();

            /* Set the serial port to the port selected in the combobo */
            serialPort1.PortName = comPortSettingsCbx.Text;

            /* Open the serial port for communications
                Note: this does not check if the serial port exists.
                You will get an error if it does not exist. */
            serialPort1.Open();

            /* Enable buttons */
            playPauseBtn.Enabled = true;
            nextBtn.Enabled = true;
            previousBtn.Enabled = true;
            repeatAllBtn.Enabled = true;
            musicListLbx.Enabled = true;
            speedTrbr.Enabled = true;
            resetSpeedBtn.Enabled = true;
        }

        private void PlayPauseBtn_Click(object sender, EventArgs e)
        {

            /* send the command to the serial port */
            serialPort1.Write("play");

            /* change the playbutton icon */
            if (playState == true)
            {
                playPauseBtn.Text = "▎ ▎";
                playPauseBtn.Font = new Font("Microsoft Sans Serif", 17);

                /* pause the current music time */
                playState = false;
            }
            else
            {
                playPauseBtn.Text = "▶";
                playPauseBtn.Font = new Font("Microsoft Sans Serif", 20);

                /* play the current music time */
                playState = true;
            }
        }

        private void nextBtn_Click(object sender, EventArgs e)
        {
            /* send the command to the serial port */
            serialPort1.Write("next");

            /* get the next song */
            getPlaylistSong(true);
        }

        private void previousBtn_Click(object sender, EventArgs e)
        {
            /* send the command to the serial port */
            serialPort1.Write("prev");

            /* get the previous song */
            getPlaylistSong(false);
        }

        private void repeatAllBtn_Click(object sender, EventArgs e)
        {
            /* check if loop, repeat all or none is selected */
            switch (repeatAllState)
            {
                case 0:
                    /* send the command to the serial port */
                    serialPort1.Write("playlist");
                    repeatAllBtn.Text = "⮌";
                    repeatAllBtn.ForeColor = Color.Black;
                    repeatAllState++;
                    break;
                case 1:
                    /* send the command to the serial port */
                    serialPort1.Write("playlist");
                    serialPort1.Write("loop");
                    repeatAllBtn.Text = "↻";
                    repeatAllBtn.ForeColor = Color.Black;
                    repeatAllState++;
                    break;
                case 2:
                    /* send the command to the serial port */
                    serialPort1.Write("loop");
                    repeatAllBtn.Text = "⮌";
                    repeatAllBtn.ForeColor = Color.LightGray;
                    repeatAllState = 0;
                    break;
                default:
                    MessageBox.Show("This should not happen!", "Error in repeatAllButton_Click", MessageBoxButtons.OK, MessageBoxIcon.Error, MessageBoxDefaultButton.Button1);
                    break;
            }
        }

        private void speedTrbr_Scroll(object sender, EventArgs e)
        {
            /* send speed to arduino */
            switch (speedTrbr.Value)
            {
                case 0:
                    serialPort1.Write("S025");
                    break;
                case 1:
                    serialPort1.Write("S050");
                    break;
                case 2:
                    serialPort1.Write("S075");
                    break;
                case 3:
                    serialPort1.Write("S100");
                    break;
                case 4:
                    serialPort1.Write("S125");
                    break;
                case 5:
                    serialPort1.Write("S150");
                    break;
                case 6:
                    serialPort1.Write("S175");
                    break;
                case 7:
                    serialPort1.Write("S200");
                    break;
                case 8:
                    serialPort1.Write("S225");
                    break;
                case 9:
                    serialPort1.Write("S250");
                    break;
                case 10:
                    serialPort1.Write("S275");
                    break;
                case 11:
                    serialPort1.Write("S300");
                    break;
                default:
                    MessageBox.Show("Error, this should not happen!", "Error in speedTrbr_Scroll", MessageBoxButtons.OK, MessageBoxIcon.Error, MessageBoxDefaultButton.Button1);
                    break;
            }
        }

        private void resetSpeedBtn_Click(object sender, EventArgs e)
        {
            /* set to 3, this will represent "1x" */
            speedTrbr.Value = 3;
        }

        private void musicListLbx_SelectedIndexChanged(object sender, EventArgs e)
        {
            /* update current song */
            currentSong = Convert.ToString(musicListLbx.SelectedItem);

            if (currentSong != previousSong)
            {
                /* play a song, send which and refresh time */
                switch (currentSong)
                {
                    case "Rammstein - Radio":
                        /* send tot arduino */
                        serialPort1.Write("radio.wav");

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Alestorm - Fucked With An Anchor":
                        /* send tot arduino */
                        serialPort1.Write("fucked with an anchor.wav");

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Queen - Bohemian Rhapsody":
                        /* send tot arduino */
                        serialPort1.Write("bohemian rhapsody.wav");

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Undertale - Megalovania":
                        /* send tot arduino */
                        serialPort1.Write("megalovania.wav");

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Queen - Love Of My Life":
                        /* send tot arduino */
                        serialPort1.Write("love of my life.wav");

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Hatari - Hatrið Mun Sigra":
                        /* send tot arduino */
                        serialPort1.Write("hatrid mun sigra.wav");

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Beethoven - Für Elise":
                        /* send tot arduino */
                        serialPort1.Write("nameFurElise");

                        /*update the index */
                        index = 0;

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Koji Kondo - Underworld (Mario)":
                        /* send tot arduino */
                        serialPort1.Write("nameUnderWorld");

                        /*update the index */
                        index = 1;
                        
                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Monty Norman - James Bond Theme":
                        /* send tot arduino */
                        serialPort1.Write("nameJamesBond");

                        /*update the index */
                        index = 2;

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Koji Kondo - Mario Theme":
                        /* send tot arduino */
                        serialPort1.Write("nameMarioTheme");

                        /*update the index */
                        index = 3;

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;

                    case "Hans Zimmer & Klaus Badelt - He Is A Pirate":
                        /* send tot arduino */
                        serialPort1.Write("namePirOfTheCar");

                        /*update the index */
                        index = 4;

                        /* update current song & artist label */
                        UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
                        break;
                }
                
            if (playState == false)
            {
                    playPauseBtn.Text = "▎ ▎";
                    playPauseBtn.Font = new Font("Microsoft Sans Serif", 17);

                    /* play the current music time */
                    playState = true;
                }
            }

            /* current song will be the next previous song */
            previousSong = currentSong;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            /* update the current playing time */
            if (playState)
            {
                serialPort1.Write("updating clock");
                TimeCalcuation();
            }

            /* loop the current song */
            if (repeatAllState == 1)
            {
                /* calculate if restart is needed */
                int counter = totalTime - currentTime;

                /* check if counter = 0 */
                if (counter == 0)
                {
                    /* reset current time */
                    currentTime = 0;
                    previousTime = 0;
                }
            }
            
            /* repeat all */
            else if (repeatAllState == 2)
            {
                /* calculate if it is time to go next */
                int counter = totalTime - currentTime;

                /* check if counter = 0 */
                if (counter == 0)
                {
                    /* play next */
                    getPlaylistSong(true);
                }
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            /* check for data from arduino */
            ReceiveSerialData();
        }


        /* my functions */
        private void TimeCalcuation()
        {
            /* get the total time */
            string currentSongTime;
            int songTimeMin = Convert.ToInt32(musicTimeLbl.Text.Substring(0, 1));
            int songTimeSec = Convert.ToInt32(musicTimeLbl.Text.Substring(2, 2));
            
            totalTime = (songTimeMin * 60) + songTimeSec;

            /* calc current music time */
            currentTime++;

            /* conversion to time in minutes */
            int currentMin = currentTime / 60;
            int currentSec = currentTime % 60;

            if (currentSec < 10)
            {
                /* to string */
                currentSongTime = $"{currentMin}:0{(currentSec).ToString("#")}";
            }
            else
            {
                /* to string */
                currentSongTime = $"{currentMin}:{(currentSec).ToString("##")}";
            }

            /* show the current playing time */
            currentMusicTimeLbl.Text = currentSongTime;
            
            /* update the progressbar */
            playTimeBar.Value = (totalTime - currentTime) / totalTime * 100;

            /* update previous time */
            previousTime = currentTime;
        }

        private void TotalTimeRestart(string musicTitle)
        {
            /* set current time to 0:00 */
            currentTime = 0;

            /* get the time of the music */
            musicTimeLbl.Text = music.getMusicSongTime(musicTitle);
        }

        private void ReceiveSerialData()
        {
            /* Check if serial data is available */
            if (serialPort1.BytesToRead > 0)
            {
                /* Receive string from the serial port
                    Note: this will read until a \n is received */
                string incomingData = serialPort1.ReadLine();

                /* checks which input recieved */
                if (incomingData == "playAr")
                {
                    /* change the playbutton icon */
                    if (playState == true)
                    {
                        playPauseBtn.Text = "▎ ▎";
                        playPauseBtn.Font = new Font("Microsoft Sans Serif", 17);

                        /* pause the current music time */
                        playState = false;
                    }
                    else
                    {
                        playPauseBtn.Text = "▶";
                        playPauseBtn.Font = new Font("Microsoft Sans Serif", 20);

                        /* play the current music time */
                        playState = true;
                    }
                }
                else if (incomingData == "nextAr")
                {
                    /* get the next song */
                    getPlaylistSong(true);
                }
                else if (incomingData == "prevAr")
                {
                    /* get the previous song */
                    getPlaylistSong(false);
                }
            }
        }

        private void getPlaylistSong(bool upcomingMusic)
        {
            /* deselect the current selected */
            musicListLbx.SetSelected(index, false);

            /* select next or previous */
            if (upcomingMusic)
            {
                if (index < 4)
                {
                    index++;
                }
                else if (index == 4)
                {
                    index = 0;
                }
            }
            else
            {
                if (index > 0)
                {
                    index--;
                }
                else if (index == 0)
                {
                    index = 4;
                }
            }

            /* select the next song */
            musicListLbx.SetSelected(index, true);

            /* get the text selected */
            string upcomingSong = Convert.ToString(musicListLbx.SelectedItem);

            /* get the new time */
            TotalTimeRestart(upcomingSong);

            /* update the current playing artist and song */
            UpdateCurrentMusicLable(Convert.ToString(musicListLbx.SelectedItem));
        }

        private void UpdateCurrentMusicLable(string selectedSong)
        {
            /* get the music name from listbox */
            int intern = selectedSong.IndexOf(" - ");

            /* update the artistname */
            nowPlayingArtistLbl.Text = selectedSong.Substring(0, intern);

            /* update the songname */
            NowPlayingSongLbl.Text = selectedSong.Substring(intern + 3);

            /* update the time */
            TotalTimeRestart(selectedSong.Substring(intern + 3));

            /* get the correct album cover */
            switch (index)
            {
                case 0:
                   coverElisePbx.BringToFront();
                    break;
                case 1:
                    coverUnderworldPbx.BringToFront();
                    break;
                case 2:
                    coverJamesPbx.BringToFront();
                    break;
                case 3:
                    coverMarioThemePbx.BringToFront();
                    break;
                case 4:
                    coverPiratesPbx.BringToFront();
                    break;
            }
        }


        /* ... */
        private void musicPlayerWindow_Load(object sender, EventArgs e)
        {

        }

        private void musicPlayerWindow_Shown(object sender, EventArgs e)
        {

        }

        private void speedInfoLbl_Click(object sender, EventArgs e)
        {

        }

        private void albumCoverPbx_Click(object sender, EventArgs e)
        {

        }
    }
}