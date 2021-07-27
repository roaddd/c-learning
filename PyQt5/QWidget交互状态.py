from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def paintEvent(self, a0: QtGui.QPaintEvent) -> None:
        print("窗口被绘制了")
        return super().paintEvent(a0)

class Btn(QPushButton):
    def paintEvent(self, a0: QtGui.QPaintEvent) -> None:
        print("按钮被绘制了")
        return super().paintEvent(a0)

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()
#设置控件
window.setWindowTitle("[*]交互状态")
window.resize(500,500)
window.setWindowModified(True)

btn=Btn(window)
btn.setText("按钮")
btn.pressed.connect(lambda: btn.setVisible(False))
#btn.setEnabled(False)


#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
