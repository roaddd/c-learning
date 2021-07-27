import sys
from PyQt5.Qt\
    import *
class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setWindowTitle("QLabel的学习")
        self.resize(500,500)
        self.setup_ui()
    def setup_ui(self):
        #self.QObject_()

        #信号与槽案例
        #self.single()

        #对象删除
        self.DeleteObject();
    def QObject_(self):
        with open("QObject.qss","r") as f:
            qApp.setStyleSheet(f.read())

        label=QLabel(self)
        label.setText("123")
        label.setObjectName("notice")
        label.setProperty("notice_level","warning")

        label2 = QLabel(self)
        label2.setText("456")
        label2.move(100,100)
        label.setProperty("notice_level", "error")

    def QObject_parent_chrildern(self):
        pass

    def single(self):
        #案例一：当用户点击按钮的时候, 打印"点我嘎哈?"
        btn=QPushButton(self)
        btn.setText("点击我")
        btn.move(200,200)
        # def cao():
        #     print("点击成功")
        # btn.clicked.connect(cao)

        #案例二：在所有修改的窗口标题前, 添加前缀"撩课-"
        #self.setWindowTitle("Hello Sz")
        # def cao(title):
        #     self.windowTitleChanged.disconnect()
        #     self.setWindowTitle("撩课-"+title)
        #     self.windowTitleChanged.connect(cao)
        # self.windowTitleChanged.connect(cao)
        # self.setWindowTitle("Hello Sz1")

        #案例三
        label1=QLabel(self)
        label1.setText("123")

        label2=QLabel(self)
        label2.setText("456")
        label2.move(150,150)

        for widget in self.children():
            if widget.inherits("QLabel"):
                widget.setStyleSheet("background-color:cyan;")

    def DeleteObject(self):
        obj1 = QObject()
        obj2 = QObject()
        obj3=QObject()
        self.obj1=obj1
        obj2.setParent(obj1)
        obj3.setParent(obj2)

        obj2.destroyed.connect(lambda :print("obj2被释放了"))
        obj3.destroyed.connect(lambda :print("obj3被释放了"))

        obj2.deleteLater()
        print(obj2) 


if __name__ == '__main__':
    app=QApplication(sys.argv)
    window=Window()
    window.show()
    sys.exit(app.exec_())