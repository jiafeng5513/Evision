using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Emgu.CV;
using Emgu.CV.Structure;

namespace CvLabSandbox.utils
{   /// <summary>
    /// 处理各种转型
    /// </summary>
    class TypeConverter
    {
        public static PointF[] PointArray2PointFArray(Point[] oldvalue)
        {
            PointF[] rerurnvalue = new PointF[oldvalue.Length];
            for (int i = 0; i < oldvalue.Length; i++)
            {
                rerurnvalue[i] = (PointF) oldvalue[i];
            }
            return rerurnvalue;
        }

        public static Mat Bitmap2Mat(Bitmap bitmap)
        {
            Image<Bgr, Byte> currentFrame = new Image<Bgr, Byte>(bitmap);  
            Mat invert = new Mat();
            CvInvoke.BitwiseAnd(currentFrame, currentFrame, invert);
            return invert;
        }
    }
}
