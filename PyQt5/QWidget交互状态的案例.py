from PyQt5.Qt import *
import sys

class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.setWindowTitle("交互状态案例")
        self.resize(500, 500)
        self.setup_ui()

    def setup_ui(self):
        label=QLabel(self)
        le=QLineEdit(self)
        btn=QPushButton(self)

        label.setText("标签")
        label.move(100,50)
        label.hide()

        le.setText("文本框")
        le.move(100,100)

        btn.setText("登录")
        btn.move(100,150)
        btn.setEnabled(False)

        def text_cao(text):
            print("文本内容发生了改变",text)
            btn.setEnabled(len(text)>0)
        le.textChanged.connect(text_cao)

        def check():
            content=le.text()
            if content=="Sz":
                label.setText("登陆成功")
            else:
                label.setText("登陆失败")
            label.show()
            label.adjustSize()
        btn.pressed.connect(check)


if __name__ == '__main__':
    #创建一个应用程序对象
    app=QApplication(sys.argv)
    #创建控件
    window=Window()
    #设置控件




    #展示控件
    window.show()
    #进入消息循环
    sys.exit(app.exec_())
