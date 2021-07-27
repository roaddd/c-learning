from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        local_x=a0.x()
        local_y=a0.y()
        sub_widget=self.childAt(local_x,local_y)
        if sub_widget is not None:
            sub_widget.setStyleSheet("background-color:red;")

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()
#设置控件
window.setWindowTitle("父子关系")
window.resize(500,500)

for i in range(1,11):
    label=QLabel(window)
    label.setText("标签"+str(i))
    label.move(40*i,40*i)

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
