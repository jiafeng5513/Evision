using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CvLabSandbox.Model
{
    class ChessBoard : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        private int _boardRows;
        private int _boardColumns;
        private int _nImages;   //数量
        private float _squareWidth;//尺寸

        public ChessBoard()
        {
            BoardRows = 6;
            BoardColumns = 9;
            NImages = 20;
            SquareWidth = 25.0F;
        }

        public int BoardRows
        {
            get => _boardRows;
            set
            {
                _boardRows = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("BoardRows"));
            }
        }

        public int BoardColumns
        {
            get => _boardColumns;
            set
            {
                _boardColumns = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("BoardColumns"));
            }
        }

        public int NImages {
            get => _nImages;
            set
            {
                _nImages = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("NImages"));
            }
         }
        public float SquareWidth {
            get => _squareWidth;
            set
            {
                _squareWidth = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("SquareWidth"));
            }
        }
    }
}
