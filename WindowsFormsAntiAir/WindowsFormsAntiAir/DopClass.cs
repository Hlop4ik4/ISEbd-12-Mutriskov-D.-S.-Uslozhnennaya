using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsAntiAir
{
    class DopClass
    {
        private DopEnum dopEnum;
        public int NumberUfGuns { set => dopEnum = (DopEnum)value;}
        public Color DopColor;

        public DopClass(int num, Color dopColor)
        {
            NumberUfGuns = num;
            DopColor = dopColor;
        }

        public void DrawGuns(Graphics g, float _startPosX, float _startPosY, Color dopColor)
        {
            Pen dopPen = new Pen(dopColor);
            switch (dopEnum)
            {
                case DopEnum.TwoGuns:
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 80, _startPosY - 3);
                    break;
                case DopEnum.FourGuns:
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 180, _startPosY - 3);
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 190, _startPosY - 3);
                    break;
                case DopEnum.SixGuns:
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 80, _startPosY - 3);
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 180, _startPosY - 3);
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 190, _startPosY - 3);
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 60, _startPosY);
                    g.DrawLine(dopPen, _startPosX + 130, _startPosY + 17, _startPosX + 200, _startPosY);
                    break;
            }
        }
    }
}
