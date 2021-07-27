from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setWindowTitle("")
        self.resize(500, 500)
        self.setup_ui()
        self.move_flag=False;

    def setup_ui(self):
        pass

    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        if a0.button()==Qt.LeftButton:
            self.move_flag=True
            print("鼠标按下")
            self.mouse_x=a0.globalX()
            self.mouse_y=a0.globalY()

            self.origin_x=self.x()
            self.origin_y=self.y()

    def mouseMoveEvent(self, a0: QtGui.QMouseEvent) -> None:
        if self.move_flag:
            print("鼠标移动")
            move_x=a0.globalX()-self.mouse_x
            move_y=a0.globalY()-self.mouse_y
            self.move(self.origin_x+move_x,self.origin_y+move_y)

    def mouseReleaseEvent(self, a0: QtGui.QMouseEvent) -> None:
        print("鼠标释放")
        self.move_flag=False

if __name__ == '__main__':
    #创建一个应用程序对象
    app=QApplication(sys.argv)
    #创建控件
    window=Window()
    #设置控件

    window.setMouseTracking(True)


    #展示控件
    window.show()
    #进入消息循环
    sys.exit(app.exec_())
