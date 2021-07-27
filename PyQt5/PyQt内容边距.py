from PyQt5.Qt import *
import sys
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.setWindowTitle("Hello Sz")
window.resize(500,500)

pixmap=QPixmap("xxx.png")
new_pixmap=pixmap.scaled(50,50)
cursor=QCursor(new_pixmap,50,50)
window.setCursor(cursor)

label=QLabel(window)
label.setText("123456789")
label.resize(200,200)
label.setContentsMargins(100,100,0,0)
label.setStyleSheet("background-color:cyan;")



#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
