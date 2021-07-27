from PyQt5.Qt import *
import sys
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.setWindowTitle("九宫格")
window.resize(500,500)
window.move(300,300)

#总的控件个数
widget_count=60
#一行多少列
column_count=3

#一个控件的宽度
widget_width=window.width()/column_count
#总共有多少行
row_count=(widget_count-1)//column_count+1
widget_height=window.height()/row_count

for i in range(widget_count):
    w=QWidget(window)
    w.resize(widget_width,widget_height)
    w.move((i%column_count)*widget_width,(i%row_count)*widget_height)
    w.setStyleSheet("background-color:red;border:1px solid yellow;")
    w.show()

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
