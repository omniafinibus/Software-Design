namespace MusicPlayerGUI
{
    partial class musicPlayerWindow
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(musicPlayerWindow));
            this.playTimeBar = new System.Windows.Forms.ProgressBar();
            this.playPauseBtn = new System.Windows.Forms.Button();
            this.nextBtn = new System.Windows.Forms.Button();
            this.previousBtn = new System.Windows.Forms.Button();
            this.currentMusicTimeLbl = new System.Windows.Forms.Label();
            this.musicTimeLbl = new System.Windows.Forms.Label();
            this.musicListLbx = new System.Windows.Forms.ListBox();
            this.repeatAllBtn = new System.Windows.Forms.Button();
            this.shuffleBtn = new System.Windows.Forms.Button();
            this.coverMarioThemePbx = new System.Windows.Forms.PictureBox();
            this.NowPlayingSongLbl = new System.Windows.Forms.Label();
            this.speedTrbr = new System.Windows.Forms.TrackBar();
            this.nowPlayingArtistLbl = new System.Windows.Forms.Label();
            this.resetSpeedBtn = new System.Windows.Forms.Button();
            this.speedInfoLbl = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.comPortSettingsCbx = new System.Windows.Forms.ComboBox();
            this.settingsInfoLbl = new System.Windows.Forms.Label();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.coverJamesPbx = new System.Windows.Forms.PictureBox();
            this.coverElisePbx = new System.Windows.Forms.PictureBox();
            this.coverUnderworldPbx = new System.Windows.Forms.PictureBox();
            this.coverPiratesPbx = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.coverMarioThemePbx)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.speedTrbr)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverJamesPbx)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverElisePbx)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverUnderworldPbx)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverPiratesPbx)).BeginInit();
            this.SuspendLayout();
            // 
            // playTimeBar
            // 
            this.playTimeBar.Location = new System.Drawing.Point(19, 422);
            this.playTimeBar.Margin = new System.Windows.Forms.Padding(10);
            this.playTimeBar.Name = "playTimeBar";
            this.playTimeBar.Size = new System.Drawing.Size(530, 20);
            this.playTimeBar.TabIndex = 0;
            // 
            // playPauseBtn
            // 
            this.playPauseBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.playPauseBtn.Location = new System.Drawing.Point(254, 359);
            this.playPauseBtn.Margin = new System.Windows.Forms.Padding(5);
            this.playPauseBtn.Name = "playPauseBtn";
            this.playPauseBtn.Size = new System.Drawing.Size(60, 48);
            this.playPauseBtn.TabIndex = 3;
            this.playPauseBtn.Text = "▶";
            this.playPauseBtn.UseVisualStyleBackColor = true;
            this.playPauseBtn.Click += new System.EventHandler(this.PlayPauseBtn_Click);
            // 
            // nextBtn
            // 
            this.nextBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nextBtn.Location = new System.Drawing.Point(324, 359);
            this.nextBtn.Margin = new System.Windows.Forms.Padding(5);
            this.nextBtn.Name = "nextBtn";
            this.nextBtn.Size = new System.Drawing.Size(43, 48);
            this.nextBtn.TabIndex = 4;
            this.nextBtn.Text = "↪";
            this.nextBtn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.nextBtn.UseVisualStyleBackColor = true;
            this.nextBtn.Click += new System.EventHandler(this.nextBtn_Click);
            // 
            // previousBtn
            // 
            this.previousBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.previousBtn.Location = new System.Drawing.Point(201, 359);
            this.previousBtn.Margin = new System.Windows.Forms.Padding(5);
            this.previousBtn.Name = "previousBtn";
            this.previousBtn.Size = new System.Drawing.Size(43, 48);
            this.previousBtn.TabIndex = 5;
            this.previousBtn.Text = "↩";
            this.previousBtn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.previousBtn.UseVisualStyleBackColor = true;
            this.previousBtn.Click += new System.EventHandler(this.previousBtn_Click);
            // 
            // currentMusicTimeLbl
            // 
            this.currentMusicTimeLbl.AutoSize = true;
            this.currentMusicTimeLbl.Location = new System.Drawing.Point(16, 394);
            this.currentMusicTimeLbl.Margin = new System.Windows.Forms.Padding(5);
            this.currentMusicTimeLbl.Name = "currentMusicTimeLbl";
            this.currentMusicTimeLbl.Size = new System.Drawing.Size(34, 13);
            this.currentMusicTimeLbl.TabIndex = 7;
            this.currentMusicTimeLbl.Text = "00:00";
            // 
            // musicTimeLbl
            // 
            this.musicTimeLbl.AutoSize = true;
            this.musicTimeLbl.Location = new System.Drawing.Point(511, 394);
            this.musicTimeLbl.Margin = new System.Windows.Forms.Padding(5);
            this.musicTimeLbl.Name = "musicTimeLbl";
            this.musicTimeLbl.Size = new System.Drawing.Size(34, 13);
            this.musicTimeLbl.TabIndex = 8;
            this.musicTimeLbl.Text = "00:00";
            // 
            // musicListLbx
            // 
            this.musicListLbx.FormattingEnabled = true;
            this.musicListLbx.Location = new System.Drawing.Point(19, 19);
            this.musicListLbx.Margin = new System.Windows.Forms.Padding(10);
            this.musicListLbx.Name = "musicListLbx";
            this.musicListLbx.Size = new System.Drawing.Size(225, 199);
            this.musicListLbx.TabIndex = 9;
            this.musicListLbx.SelectedIndexChanged += new System.EventHandler(this.musicListLbx_SelectedIndexChanged);
            // 
            // repeatAllBtn
            // 
            this.repeatAllBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.repeatAllBtn.ForeColor = System.Drawing.SystemColors.ControlText;
            this.repeatAllBtn.Location = new System.Drawing.Point(382, 359);
            this.repeatAllBtn.Margin = new System.Windows.Forms.Padding(10, 5, 10, 5);
            this.repeatAllBtn.Name = "repeatAllBtn";
            this.repeatAllBtn.Size = new System.Drawing.Size(49, 48);
            this.repeatAllBtn.TabIndex = 10;
            this.repeatAllBtn.Text = "↻";
            this.repeatAllBtn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.repeatAllBtn.UseVisualStyleBackColor = true;
            this.repeatAllBtn.Click += new System.EventHandler(this.repeatAllBtn_Click);
            // 
            // shuffleBtn
            // 
            this.shuffleBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.shuffleBtn.ForeColor = System.Drawing.SystemColors.ControlText;
            this.shuffleBtn.Location = new System.Drawing.Point(137, 359);
            this.shuffleBtn.Margin = new System.Windows.Forms.Padding(10, 5, 10, 5);
            this.shuffleBtn.Name = "shuffleBtn";
            this.shuffleBtn.Size = new System.Drawing.Size(49, 48);
            this.shuffleBtn.TabIndex = 11;
            this.shuffleBtn.Text = "⤮";
            this.shuffleBtn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.shuffleBtn.UseVisualStyleBackColor = true;
            // 
            // coverMarioThemePbx
            // 
            this.coverMarioThemePbx.Image = ((System.Drawing.Image)(resources.GetObject("coverMarioThemePbx.Image")));
            this.coverMarioThemePbx.ImageLocation = "";
            this.coverMarioThemePbx.Location = new System.Drawing.Point(324, 19);
            this.coverMarioThemePbx.Margin = new System.Windows.Forms.Padding(10);
            this.coverMarioThemePbx.Name = "coverMarioThemePbx";
            this.coverMarioThemePbx.Size = new System.Drawing.Size(200, 200);
            this.coverMarioThemePbx.TabIndex = 12;
            this.coverMarioThemePbx.TabStop = false;
            this.coverMarioThemePbx.Click += new System.EventHandler(this.albumCoverPbx_Click);
            // 
            // NowPlayingSongLbl
            // 
            this.NowPlayingSongLbl.AutoSize = true;
            this.NowPlayingSongLbl.Location = new System.Drawing.Point(321, 272);
            this.NowPlayingSongLbl.Margin = new System.Windows.Forms.Padding(10);
            this.NowPlayingSongLbl.Name = "NowPlayingSongLbl";
            this.NowPlayingSongLbl.Size = new System.Drawing.Size(188, 13);
            this.NowPlayingSongLbl.TabIndex = 13;
            this.NowPlayingSongLbl.Text = "Selecteer een nummer om af te spelen";
            // 
            // speedTrbr
            // 
            this.speedTrbr.LargeChange = 3;
            this.speedTrbr.Location = new System.Drawing.Point(19, 238);
            this.speedTrbr.Margin = new System.Windows.Forms.Padding(10, 1, 10, 10);
            this.speedTrbr.Maximum = 11;
            this.speedTrbr.Name = "speedTrbr";
            this.speedTrbr.Size = new System.Drawing.Size(225, 45);
            this.speedTrbr.TabIndex = 14;
            this.speedTrbr.Value = 3;
            this.speedTrbr.Scroll += new System.EventHandler(this.speedTrbr_Scroll);
            // 
            // nowPlayingArtistLbl
            // 
            this.nowPlayingArtistLbl.AutoSize = true;
            this.nowPlayingArtistLbl.Location = new System.Drawing.Point(321, 239);
            this.nowPlayingArtistLbl.Margin = new System.Windows.Forms.Padding(10);
            this.nowPlayingArtistLbl.Name = "nowPlayingArtistLbl";
            this.nowPlayingArtistLbl.Size = new System.Drawing.Size(188, 13);
            this.nowPlayingArtistLbl.TabIndex = 15;
            this.nowPlayingArtistLbl.Text = "Selecteer een nummer om af te spelen";
            // 
            // resetSpeedBtn
            // 
            this.resetSpeedBtn.Location = new System.Drawing.Point(19, 272);
            this.resetSpeedBtn.Margin = new System.Windows.Forms.Padding(5);
            this.resetSpeedBtn.Name = "resetSpeedBtn";
            this.resetSpeedBtn.Size = new System.Drawing.Size(51, 36);
            this.resetSpeedBtn.TabIndex = 16;
            this.resetSpeedBtn.Text = "Reset speed";
            this.resetSpeedBtn.UseVisualStyleBackColor = true;
            this.resetSpeedBtn.Click += new System.EventHandler(this.resetSpeedBtn_Click);
            // 
            // speedInfoLbl
            // 
            this.speedInfoLbl.AutoSize = true;
            this.speedInfoLbl.Location = new System.Drawing.Point(19, 223);
            this.speedInfoLbl.Margin = new System.Windows.Forms.Padding(10, 1, 10, 1);
            this.speedInfoLbl.Name = "speedInfoLbl";
            this.speedInfoLbl.Size = new System.Drawing.Size(76, 13);
            this.speedInfoLbl.TabIndex = 17;
            this.speedInfoLbl.Text = "Change speed";
            this.speedInfoLbl.Click += new System.EventHandler(this.speedInfoLbl_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // comPortSettingsCbx
            // 
            this.comPortSettingsCbx.FormattingEnabled = true;
            this.comPortSettingsCbx.Location = new System.Drawing.Point(254, 35);
            this.comPortSettingsCbx.Name = "comPortSettingsCbx";
            this.comPortSettingsCbx.Size = new System.Drawing.Size(54, 21);
            this.comPortSettingsCbx.TabIndex = 18;
            this.comPortSettingsCbx.SelectedIndexChanged += new System.EventHandler(this.comPortSettingsCbx_SelectedIndexChanged);
            // 
            // settingsInfoLbl
            // 
            this.settingsInfoLbl.AutoSize = true;
            this.settingsInfoLbl.Location = new System.Drawing.Point(257, 19);
            this.settingsInfoLbl.Name = "settingsInfoLbl";
            this.settingsInfoLbl.Size = new System.Drawing.Size(45, 13);
            this.settingsInfoLbl.TabIndex = 19;
            this.settingsInfoLbl.Text = "Settings";
            // 
            // timer2
            // 
            this.timer2.Interval = 1000;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // coverJamesPbx
            // 
            this.coverJamesPbx.Image = ((System.Drawing.Image)(resources.GetObject("coverJamesPbx.Image")));
            this.coverJamesPbx.ImageLocation = "";
            this.coverJamesPbx.Location = new System.Drawing.Point(324, 19);
            this.coverJamesPbx.Margin = new System.Windows.Forms.Padding(10);
            this.coverJamesPbx.Name = "coverJamesPbx";
            this.coverJamesPbx.Size = new System.Drawing.Size(200, 200);
            this.coverJamesPbx.TabIndex = 20;
            this.coverJamesPbx.TabStop = false;
            // 
            // coverElisePbx
            // 
            this.coverElisePbx.Image = ((System.Drawing.Image)(resources.GetObject("coverElisePbx.Image")));
            this.coverElisePbx.ImageLocation = "";
            this.coverElisePbx.Location = new System.Drawing.Point(324, 19);
            this.coverElisePbx.Margin = new System.Windows.Forms.Padding(10);
            this.coverElisePbx.Name = "coverElisePbx";
            this.coverElisePbx.Size = new System.Drawing.Size(200, 200);
            this.coverElisePbx.TabIndex = 21;
            this.coverElisePbx.TabStop = false;
            // 
            // coverUnderworldPbx
            // 
            this.coverUnderworldPbx.Image = ((System.Drawing.Image)(resources.GetObject("coverUnderworldPbx.Image")));
            this.coverUnderworldPbx.ImageLocation = "";
            this.coverUnderworldPbx.Location = new System.Drawing.Point(324, 19);
            this.coverUnderworldPbx.Margin = new System.Windows.Forms.Padding(10);
            this.coverUnderworldPbx.Name = "coverUnderworldPbx";
            this.coverUnderworldPbx.Size = new System.Drawing.Size(200, 200);
            this.coverUnderworldPbx.TabIndex = 22;
            this.coverUnderworldPbx.TabStop = false;
            // 
            // coverPiratesPbx
            // 
            this.coverPiratesPbx.Image = ((System.Drawing.Image)(resources.GetObject("coverPiratesPbx.Image")));
            this.coverPiratesPbx.ImageLocation = "";
            this.coverPiratesPbx.Location = new System.Drawing.Point(324, 19);
            this.coverPiratesPbx.Margin = new System.Windows.Forms.Padding(10);
            this.coverPiratesPbx.Name = "coverPiratesPbx";
            this.coverPiratesPbx.Size = new System.Drawing.Size(200, 200);
            this.coverPiratesPbx.TabIndex = 23;
            this.coverPiratesPbx.TabStop = false;
            // 
            // musicPlayerWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(568, 461);
            this.Controls.Add(this.coverPiratesPbx);
            this.Controls.Add(this.coverUnderworldPbx);
            this.Controls.Add(this.coverElisePbx);
            this.Controls.Add(this.coverJamesPbx);
            this.Controls.Add(this.settingsInfoLbl);
            this.Controls.Add(this.comPortSettingsCbx);
            this.Controls.Add(this.speedInfoLbl);
            this.Controls.Add(this.resetSpeedBtn);
            this.Controls.Add(this.nowPlayingArtistLbl);
            this.Controls.Add(this.speedTrbr);
            this.Controls.Add(this.NowPlayingSongLbl);
            this.Controls.Add(this.coverMarioThemePbx);
            this.Controls.Add(this.shuffleBtn);
            this.Controls.Add(this.repeatAllBtn);
            this.Controls.Add(this.musicListLbx);
            this.Controls.Add(this.musicTimeLbl);
            this.Controls.Add(this.currentMusicTimeLbl);
            this.Controls.Add(this.previousBtn);
            this.Controls.Add(this.nextBtn);
            this.Controls.Add(this.playPauseBtn);
            this.Controls.Add(this.playTimeBar);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(584, 500);
            this.MinimumSize = new System.Drawing.Size(584, 500);
            this.Name = "musicPlayerWindow";
            this.Text = "Music Player";
            this.Load += new System.EventHandler(this.musicPlayerWindow_Load);
            this.Shown += new System.EventHandler(this.musicPlayerWindow_Shown);
            ((System.ComponentModel.ISupportInitialize)(this.coverMarioThemePbx)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.speedTrbr)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverJamesPbx)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverElisePbx)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverUnderworldPbx)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.coverPiratesPbx)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ProgressBar playTimeBar;
        private System.Windows.Forms.Button playPauseBtn;
        private System.Windows.Forms.Button nextBtn;
        private System.Windows.Forms.Button previousBtn;
        private System.Windows.Forms.Label currentMusicTimeLbl;
        private System.Windows.Forms.Label musicTimeLbl;
        private System.Windows.Forms.ListBox musicListLbx;
        private System.Windows.Forms.Button repeatAllBtn;
        private System.Windows.Forms.Button shuffleBtn;
        private System.Windows.Forms.PictureBox coverMarioThemePbx;
        private System.Windows.Forms.Label NowPlayingSongLbl;
        private System.Windows.Forms.TrackBar speedTrbr;
        private System.Windows.Forms.Label nowPlayingArtistLbl;
        private System.Windows.Forms.Button resetSpeedBtn;
        private System.Windows.Forms.Label speedInfoLbl;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ComboBox comPortSettingsCbx;
        private System.Windows.Forms.Label settingsInfoLbl;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Timer timer2;
        private System.Windows.Forms.PictureBox coverJamesPbx;
        private System.Windows.Forms.PictureBox coverElisePbx;
        private System.Windows.Forms.PictureBox coverUnderworldPbx;
        private System.Windows.Forms.PictureBox coverPiratesPbx;
    }
}

