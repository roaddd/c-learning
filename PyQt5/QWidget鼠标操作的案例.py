from PyQt5 import QtCore, QtGui
from PyQt5.Qt import *
import sys

class MyLabel(QLabel):
    def enterEvent(self, a0: QtCore.QEvent) -> None:
        print("鼠标进入")
        self.setText("欢迎光临")

    def leaveEvent(self, a0: QtCore.QEvent) -> None:
        print("鼠标离开")
        self.setText("谢谢惠顾")

    def keyPressEvent(self, ev: QtGui.QKeyEvent) -> None:
        print("xx")
        # if ev.key()==Qt.Key_Tab:
        #     print("用户点击了Tab键位")
        if ev.modifiers()==Qt.ControlModifier|Qt.ShiftModifier and ev.key()==Qt.Key_A:
            print("Ctrl+Shift+A被点击了")
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.setWindowTitle("鼠标操作案例")
window.resize(500,500)

label=MyLabel(window)
label.resize(200,200)
label.setStyleSheet("background-color:cyan;")
label.move(50,50)
label.grabKeyboard();

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
