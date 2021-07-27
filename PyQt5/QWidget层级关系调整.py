from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

#第一种方法
class Mylabel(QLabel):
    def mousePressEvent(self, ev: QtGui.QMouseEvent) -> None:
        self.raise_()

#第二种方法
class Window(QWidget):
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        mouse_x=a0.x()
        mouse_y=a0.y()
        sub_label=self.childAt(mouse_x,mouse_y)
        sub_label.raise_()


#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()
#设置控件
window.setWindowTitle("层级关系调整")
window.resize(500,500)

label1=QLabel(window)
label1.setText("标签1")
label1.resize(100,100)
label1.setStyleSheet("background-color:red;")


label2=QLabel(window)
label2.setText("标签2")
label2.resize(100,100)
label2.setStyleSheet("background-color:green;")
label2.move(50,50)

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
