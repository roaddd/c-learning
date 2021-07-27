import sys
from PyQt5.Qt import *
app=QApplication(sys.argv)

#win1=QWidget()
# win1.setStyleSheet("background-color:red;")
# win1.setWindowTitle("红色")
# win1.show()
#
# win2=QWidget()
# win2.setStyleSheet("background-color:green;")
# #win2.setParent(win1)
# win2.resize(1000,100)
# win2.move(100,50)
# win2.setWindowTitle("绿色")
# win2.show()

#创建一个窗口 包含另外两个子控件

win_root=QWidget()

label1=QLabel()
label1.setText("label1")
label1.setParent(win_root)

label2=QLabel()
label2.setText("label2")
label2.setParent(win_root)
label2.move(50,50)

btn=QPushButton(win_root)
btn.move(100,100)
btn.setText("btn")

win_root.show()

#将QLabel控件的背景颜色进行设置
for sub_widget in win_root.findChildren(QLabel):
    sub_widget.setStyleSheet("background-color:cyan;")

sys.exit(app.exec_())