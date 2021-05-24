#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Window_mgr {
public:
	//窗口屏幕的编号
	using ScreenIndex = vector<Screen>::size_type;
	//按编号将屏幕置为空白
	void clear(ScreenIndex);//声明函数
private:
	vector<Screen> screens{ Screen(24, 80, ' ') };
};


class Screen {
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
	//using pos=string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {};
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd,c) {};
	Screen& set(char);
	Screen& set(pos, pos, char);
	char get() const {
		return contents[cursor];
	}
	inline char get(pos, pos) const;
	Screen& move(pos r, pos c);
	void some_member() const;
	Screen& display(ostream& os) {
		do_display(os);
		return *this;
	}
	//根据对象是否是const重载了display函数
	const Screen& display(ostream& os) const{
		do_display(os);
		return *this;
	}
	pos size() const {
		return height * width;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t access_ctr;
	//负责打印Screen内容
	void do_display(ostream& os)const {
		os << contents;
	}
};


inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c) const{
	pos row = r * width;
	return contents[row + c];
}
void Screen::some_member() const {
	++access_ctr;//记录成员函数被调用的次数
}
inline Screen& Screen::set(char c) {
	contents[cursor] = c;//设置当前光标所在位置的新值
	return *this;
}
inline Screen& Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;//设置给定位置的新值
	return *this;
}



void Window_mgr::clear(ScreenIndex i) {
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}


int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	return 0;
}