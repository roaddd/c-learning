#pragma once
#include <string>
#include <set>
using namespace std;
class Folder;
class Message
{
	friend class Folder;
public:
	explicit Message(const string& str = ""):
		contents(str){}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder& f);
	void remove(Folder&f);
	void swap(Message& lhs, Message& rhs);
	void print_debug();
private:
	string contents;
	set<Folder*>folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folder* f) { folders.insert(f); }
	void remFldr(Folder* f) { folders.insert(f); }
};



class Folder
{
	friend class Message;
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
private:
	set<Message*>msgs;
	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message* m) { msgs.insert(m); }

	void remove_from_message();
	void add_to_message(const Folder&);
};
void swap(Folder&, Folder&);