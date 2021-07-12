#define _CRT_SECURE_NO_WARNINGS 1
#include "Message.h"
#include <iostream>

Message& Message::operator=(const Message&rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
Message& Message::operator=(Message&& rhs)noexcept
{
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}
void Message::print_debug()
{
	cout << contents << endl;
}
void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}
//将本Meassage添加到指向m的Folder中
void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}
Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);//将本消息添加到指向m的Folder中
}
Message::Message(Message&& m) noexcept: contents(m.contents)
{
	move_Folders(&m);
}
//从对应的Folder中删除本Message
void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}
void Message::swap(Message& lhs, Message& rhs)
{
	using std::swap;
	for (auto f : folders)
		f->remMsg(&lhs);
	for (auto f : folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}
Message::~Message()
{
	remove_from_Folders();
}
void Message::move_Folders(Message* m)
{
	folders = move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}



void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	lhs.remove_from_message();
	rhs.remove_from_message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_message(lhs);
	rhs.add_to_message(rhs);
}
void Folder::add_to_message(const Folder&f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}
void Folder::remove_from_message()
{
	for (auto m : msgs)
		m->remFldr(this);
}