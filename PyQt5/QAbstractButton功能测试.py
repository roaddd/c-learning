
import numpy as np
from PyQt5 import QtCore, QtGui
from PyQt5.Qt import *
import sys
#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=QWidget()
#设置控件
window.setWindowTitle("按钮抽象类的功能测试")
window.resize(500,500)

btn=QPushButton(window)
btn.setText("1")

def add_number():
    num=int(btn.text())+1
    btn.setText(str(num))

def swap_enable():
    # btn1.toggle()
    # radio_button.toggle()
    btn1.setChecked(not btn1.isChecked())
btn.pressed.connect(swap_enable)
#btn.setShortcut("Alt+b")

btn.setAutoRepeat(True)
btn.setAutoRepeatDelay(2000)
btn.setAutoRepeatInterval(1000)
#----------图标操作------------#
icon=QIcon("xxx.png")
btn.setIcon(icon)

size=QSize(20,20)
btn.setIconSize(size)

btn1=QPushButton(window)
btn1.setText("btn1")
btn1.move(100,100)

radio_button=QRadioButton(window)
btn1=QPushButton(window)
radio_button.setText("radio")
radio_button.move(100,150)

checkbox=QCheckBox(window)
checkbox.setText("checkbox")
checkbox.move(100,200)

btn1.setStyleSheet("QPushButton:pressed {background-color:cyan;}")

btn1.setEnabled(False)
radio_button.setEnabled(False)

for i in range(3):
    btn=QCheckBox(window)
    btn.setText("btn"+str(i))
    btn.move(50*i,50*i)

    print(btn.autoExclusive())
    print(btn.isCheckable())

    btn.setAutoExclusive(False)

#模拟点击
btn=QPushButton(window)
btn.setText("按钮1")
btn.move(200,200)
btn.pressed.connect(lambda :print("点击了按钮"))
def click():
    #btn.click()
    btn.animateClick(1000)
btn1=QPushButton(window)
btn1.setText("按钮2")
btn1.move(250,250)
btn1.pressed.connect(click)


#设置点击有效区域
class Btn(QPushButton):
    def hitButton(self, pos: QtCore.QPoint) -> bool:
        # print(pos)
        # return pos.x()>(self.width()/2)
        center_x=self.width()/2
        center_y=self.height()/2
        distance=np.sqrt(np.square(pos.x()-center_x)
                         +np.square(pos.y()-center_y))
        return distance<self.width()/2
    def paintEvent(self, a0: QtGui.QPaintEvent) -> None:
        super(Btn, self).paintEvent(a0)
        painter=QPainter(self)
        painter.setPen(QPen(QColor(100,150,200),6))
        painter.drawEllipse(self.rect())
        print(self.rect())

btn=Btn(window)
btn.move(300,300)
btn.resize(200,200)
btn.setText("点击")
btn.pressed.connect(lambda :print("按钮被点击了"))

#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
