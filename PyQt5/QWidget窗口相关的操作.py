from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        if a0.button()==Qt.LeftButton:
            if self.isMaximized():
                self.showMinimized()
            else:
                self.showMaximized()

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()
#设置控件
window.setWindowTitle("窗口操作")
window.resize(500,500)

icon=QIcon("xxx.png")
window.setWindowIcon(icon)
window.setWindowOpacity(0.8)

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
