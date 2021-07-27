from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        print("外层控件被按下")

class Mid_Window(QWidget):
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        print("中间控件被按下")

class Label(QLabel):
    def mousePressEvent(self, ev: QtGui.QMouseEvent) -> None:
        print("标签控件鼠标按下")
        ev.ignore()

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()

#设置控件
window.setWindowTitle("事件转发")
window.resize(500,500)

mid_window=Mid_Window(window)
mid_window.resize(200,200)
mid_window.setAttribute(Qt.WA_StyledBackground,True)
mid_window.setStyleSheet("background-color:yellow;")

label=Label(mid_window)
label.setText("标签")
label.setStyleSheet("background-color:red;")
label.move(100,100)

btn=QPushButton(mid_window)
btn.setText("握手按钮")
btn.move(50,50)
#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
