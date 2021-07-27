from PyQt5.Qt import *
import sys
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.resize(500,500)

red=QWidget(window)
red.resize(100,100)
red.setStyleSheet("background-color:red;")
red.move(300,0)

green=QWidget(window)
green.resize(100,100)
green.setStyleSheet("background-color:green;")
green.move(300,50)

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
