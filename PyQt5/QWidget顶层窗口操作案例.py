from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setWindowTitle("顶层窗口操作案例")
        self.resize(500, 500)
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.setWindowOpacity(0.8)
        self.setup_ui()
        self.move_flag=False

    def setup_ui(self):
        top_margin = 10
        self.top_margin=top_margin
        btn_w = 80
        btn_h = 40
        close_btn = QPushButton(self)
        self.close_btn=close_btn
        close_btn.setText("关闭")
        close_btn.resize(btn_w, btn_h)
        self.close_btn_wid = close_btn.width()


        max_btn = QPushButton(self)
        self.max_btn=max_btn
        max_btn.setText("最大化")
        max_btn.resize(btn_w, btn_h)


        min_btn = QPushButton(self)
        self.min_btn=min_btn
        min_btn.setText("最小化")
        min_btn.resize(btn_w, btn_h)


        def max_normal():
            if window.isMaximized():
                window.showNormal();
                max_btn.setText("最大化")
            else:
                window.showMaximized()
                max_btn.setText("恢复")

        close_btn.pressed.connect(self.close)
        max_btn.pressed.connect(max_normal)
        min_btn.pressed.connect(self.showMinimized)

    def resizeEvent(self, a0: QtGui.QResizeEvent) -> None:
        print("窗口大小发生了改变")
        window_wid = self.width()
        self.close_btn.move(window_wid - self.close_btn_wid, self.top_margin)
        self.max_btn.move(window_wid - self.close_btn_wid - self.max_btn.width(), self.top_margin)
        self.min_btn.move(window_wid - self.close_btn_wid - self.max_btn.width() - self.min_btn.width(), 10)

    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        print("鼠标按下了")
        self.move_flag=True
        self.mouse_x=a0.globalX()
        self.mouse_y=a0.globalY()
        self.origin_x=self.x()
        self.origin_y=self.y()

    def mouseMoveEvent(self, a0: QtGui.QMouseEvent) -> None:
        if self.move_flag:
            print("鼠标移动了")
            self.move(self.origin_x+a0.globalX()-self.mouse_x,
                      self.origin_y+a0.globalY()-self.mouse_y)

    def mouseReleaseEvent(self, a0: QtGui.QMouseEvent) -> None:
        print("鼠标释放了")
        self.move_flag=False

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()
#window=QWidget(flags=Qt.FramelessWindowHint)

#设置控件
window.setMouseTracking(True)
#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
