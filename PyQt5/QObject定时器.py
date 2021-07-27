from PyQt5.Qt import *
import sys

class MyObject(QObject):
    def timerEvent(self, evt):
        print(evt,"1")

class MyLabel(QLabel):
    def __init__(self,*args,**kwargs):
        super(MyLabel, self).__init__(*args,**kwargs)
        self.setText("10")
        self.move(100, 100)
        self.setStyleSheet("font-size:22px;")

    def setSec(self,sec):
        self.setText(str(sec))

    def startMyTimer(self,ms):
        self.timer_id = self.startTimer(ms)

    def timerEvent(self,*args,**kwargs):
        print("xx")
        #获取当前标签的内容
        current_sec=int(self.text())
        current_sec-=1
        self.setText(str(current_sec))
        if current_sec==0:
            print("停止")
            self.killTimer(self.timer_id)

class MyWidge(QWidget):
    def __init__(self,*args,**kwargs):
        super(MyWidge, self).__init__(*args,**kwargs)
        self.setWindowTitle("QObject定时器的使用")
        self.resize(500,500)
    def startMyTimer(self,msc):
        self.startTimer(msc)
    def timerEvent(self,*args,**kwargs):
        current_w=self.width()
        current_h=self.height()
        self.resize(current_w+10,current_h+10)

#创建一个应用程序对象
app=QApplication(sys.argv)
#创建控件
window=MyWidge()
#设置控件
window.setWindowTitle("QObject定时器的使用")
window.startMyTimer(500)
#案例一
label=QLabel(window)


# obj=MyObject()
# timer_id=obj.startTimer(1000)
# obj.killTimer(timer_id)
#展示控件
window.show()
#进入消息循环
sys.exit(app.exec_())
