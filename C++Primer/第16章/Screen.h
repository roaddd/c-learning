#ifndef SCREEN_H
#define SCREEN_H

template<unsigned H,unsigned W>
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(char c) :contents(H*W, c){ }
	char get()const
	{
		return contents[cursor];
	}
	Screen&move(pos r, pos c);

	friend ostream&operator<<(ostream&os, const Screen<H, W>&c)
	{
		unsigned int i, j;
		for (i = 0; i < c.height; i++)
		{
			os << c.contents.substr(0, W) << endl;
		}
		return os;
	}
	friend istream&operator>>(istream&is, Screen&c)
	{
		char a;
		is >> a;
		string tmp(H*W, a);
		c.contents = tmp;
		return is;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

template<unsigned H,unsigned W>
inline Screen<H, W>&Screen<H, W>::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
#endif // !SCREEN_H

