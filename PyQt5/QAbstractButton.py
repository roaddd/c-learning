from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Btn(QAbstractButton):
    def paintEvent(self, e: QtGui.QPaintEvent) -> None:
        #创建画家，画在什么地方
        painter=QPainter(self)
        #创建并设置一支笔
        pen=QPen(QColor(111,250,250),10)
        painter.setPen(pen)
        #画家画
        painter.drawText(20,20,self.text())
        painter.drawEllipse(0,0,100,100)

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.setWindowTitle(" ")
window.resize(500,500)

btn=Btn(window)
btn.setText("xxx")
btn.resize(100,100)
btn.pressed.connect(lambda :print("点击了按钮"))


#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
