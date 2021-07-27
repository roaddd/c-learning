from PyQt5.Qt import *
import sys

class MyWindow(QWidget):
    def __init__(self):
        super(MyWindow, self).__init__()
        self.setWindowTitle("鼠标操作案例")
        self.resize(500, 500)
        self.move(200, 200)
        self.setMouseTracking(True)

        pixmap = QPixmap("xxx.png").scaled(50, 50)
        cursor = QCursor(pixmap)
        self.setCursor(cursor)

        self.label = QLabel(self)
        self.label.setText("123")
    def mouseMoveEvent(self,me):
        print("鼠标移动了",me.localPos())
        self.label=self.findChildren(QLabel)
        #label=self.findChind(QLabel)
        #label.move(300,300)
        self.label[0].move(me.localPos().x(),me.localPos().y())

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=MyWindow()
#设置控件

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
