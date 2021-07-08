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
//����Meassage��ӵ�ָ��m��Folder��
void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}
Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);//������Ϣ��ӵ�ָ��m��Folder��
}
//�Ӷ�Ӧ��Folder��ɾ����Message
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

void Folder::addMsg(Message* m)
{
	msgs.insert(m);
}
void Folder::remMsg(Message* m)
{
	msgs.erase(m);
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