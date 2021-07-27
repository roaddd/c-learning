from PyQt5 import QtGui
from PyQt5.Qt import *
import sys

class Window(QWidget):
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        print(self.focusWidget())

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=Window()
#设置控件
window.setWindowTitle("焦点控制")
window.resize(500,500)

label1=QLineEdit(window)
label1.move(50,50)
label2=QLineEdit(window)
label2.move(100,100)
label3=QLineEdit(window)
label3.move(150,150)
label2.setFocus()

label2.setFocusPolicy(Qt.TabFocus)



#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
