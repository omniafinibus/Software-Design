using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicPlayerGUI
{
    class music
    {
        /* VARIABLE declarations */

        /* music song titles */
        private string[] musicSong = new string[]
            {
                "Hatrið Mun Sigra", "Fucked With An Anchor", "Bohemian Rhapsody", "Megalovania", "Love Of My Life", "Radio"
            };
        
        /* music artists */
        private string[] musicArtist = new string[]
            {
                "Hatari", "Alestorm", "Queen", "Undertale", "Rammstein"
            };

        /* music song times */
        private int[] musicTime = new int[]
            {
                180, 207, 354, 313, 218, 277
            };

        /* arduino music song titles */
        private string[] arduinoMusicSong = new string[]
            {
                "Für Elise", "Underworld (Mario)", "James Bond Theme", "Mario Theme", "He Is A Pirate"
            };

        /* arduino music artists */
        private string[] arduinoMusicArtist = new string[]
            {
                "Beethoven", "Koji Kondo", "Monty Norman", "Hans Zimmer & Klaus Badelt"
            };

        /* adruino music song times */
        private int[] arduinoMusicTime = new int[]
            {
                //13.877, 13.524, 22.152, 08.616, 37.212
                14, 14, 22, 09, 37
            };



        /* METHODS */

        /* This method will send the artist and song requested for songs */
        public string getMusicSong(int listStatus)
        {
            /* temp variable */
            string music;

            /* "artist - song" will be send */
            switch (listStatus)
            { 
                case 0:
                    music = $"{musicArtist[0]} - {musicSong[0]}";
                    break;
                case 1:
                    music = $"{musicArtist[1]} - {musicSong[1]}";
                    break;
                case 2:
                    music = $"{musicArtist[3]} - {musicSong[3]}";
                    break;
                case 3:
                    music = $"{musicArtist[3]} - {musicSong[5]}";
                    break;
                case 4:
                    music = $"{musicArtist[4]} - {musicSong[4]}";
                    break;
                case 5:
                    music = $"{musicArtist[5]} - {musicSong[6]}";
                    break;
                default:
                    music = "Something went wrong";
                    break;
            }

            /* return the string */
            return music;
        }

        /* This method will send the artist and song requested for arduino themes */
        public string getArduinoMusicSong(int listStatus)
        {
            /* temp variable */
            string arduinoMusic;

            /* "artist - song" will be send */
            switch (listStatus)
            {
                case 0:
                    arduinoMusic = $"{arduinoMusicArtist[0]} - {arduinoMusicSong[0]}";
                    break;
                case 1:
                    arduinoMusic = $"{arduinoMusicArtist[1]} - {arduinoMusicSong[1]}";
                    break;
                case 2:
                    arduinoMusic = $"{arduinoMusicArtist[2]} - {arduinoMusicSong[2]}";
                    break;
                case 3:
                    arduinoMusic = $"{arduinoMusicArtist[1]} - {arduinoMusicSong[3]}";
                    break;
                case 4:
                    arduinoMusic = $"{arduinoMusicArtist[3]} - {arduinoMusicSong[4]}";
                    break;
                default:
                    arduinoMusic = "Something went wrong";
                    break;
            }

            /* return the string */
            return arduinoMusic;
        }

        /* this method will send the requested music time per music song */
        public string getMusicSongTime(string wantedSongTime)
        {
            /* temp variable */
            string musicSongTime;
            int musicTime = 0;

            /* get the correct time */
            switch (wantedSongTime)
            {
                case "Für Elise":
                    /* get the correct time */
                    musicTime = (int)arduinoMusicTime[0];
                    break;
                case "Underworld (Mario)":
                    /* get the correct time */
                    musicTime = (int)arduinoMusicTime[1];
                    break;
                case "James Bond Theme":
                    /* get the correct time */
                    musicTime = (int)arduinoMusicTime[2];
                    break;
                case "Mario Theme":
                    /* get the correct time */
                    musicTime = (int)arduinoMusicTime[3];
                    break;
                case "He Is A Pirate":
                    /* get the correct time */
                    musicTime = (int)arduinoMusicTime[4];
                    break;
            }

            /* conversion to time in minutes */
            int musicMin = musicTime / 60;
            int musicSec = musicTime % 60;

            if (musicSec < 10)
            {
                /* to string */
                musicSongTime = $"{musicMin}:0{(musicSec).ToString("#")}";
            }
            else
            {
                /* to string */
                musicSongTime = $"{musicMin}:{(musicSec).ToString("##")}";
            }
            

            return musicSongTime;
        }

    }
}
