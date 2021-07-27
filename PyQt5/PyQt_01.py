from PyQt5.Qt import *
from Menu import Window
import sys
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.setWindowTitle("QLable")
window.resize(500,500)

label =QLabel(window)
label.setText("xxx")

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
