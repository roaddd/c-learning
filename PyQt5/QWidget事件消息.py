from PyQt5 import QtCore
from PyQt5.Qt import *

class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setWindowTitle("事件消息的学习")
        self.resize(500,500)
        self.setup_ui()

    def setup_ui(self):
        pass

    def showEvent(self, a0: QShowEvent) -> None:
        print("窗口被展示了出来")

    def closeEvent(self, a0: QCloseEvent) -> None:
        print("窗口被关闭了")

    def moveEvent(self, a0: QMoveEvent) -> None:
        print("窗口被移动了")

    def enterEvent(self, a0: QtCore.QEvent) -> None:
        self.setStyleSheet("background-color:cyan;")

    def leaveEvent(self, a0: QtCore.QEvent) -> None:
        self.setStyleSheet("background-color:blue;")
        
if __name__ == '__main__':
    import sys
    #创建一个应用程序对象
    app=QApplication(sys.argv)
    #创建控件
    window=Window()
    #设置控件

    #展示控件
    window.show()
    #进入消息循环
    sys.exit(app.exec_())
