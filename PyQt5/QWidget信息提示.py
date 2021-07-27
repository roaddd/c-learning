from PyQt5.Qt import *
import sys
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QMainWindow()
#设置控件
window.setWindowTitle("信息提示案例")
window.resize(500,500)

window.statusBar()
#鼠标停留显示提示文本
window.setStatusTip("这是窗口")
print(window.statusTip())

label=QLabel(window)
label.setText("123")
label.setStatusTip("这是标签")
label.setToolTip("这是一个提示标签")
#控制展示时长
label.setToolTipDuration(2000)
print(label.toolTip())

window.setWindowFlags(Qt.WindowContextHelpButtonHint)
label.setWhatsThis("这是啥")

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
