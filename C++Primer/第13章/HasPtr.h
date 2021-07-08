#pragma once
#include <string>
#include <iostream>
using namespace std;
class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& lhs_hp,const HasPtr& rhs_hp);
	HasPtr(const string &s=string()):ps(new string(s)),i(0){}
	HasPtr(const HasPtr& hp) :ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr& rhs_hp);
	void show()const;
	~HasPtr()
	{
		delete ps;
	}
private:
	string* ps;
	int i;
};
inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "call swap(HasPtr&,HapPtr&)" << endl;
}
inline
bool operator<(const HasPtr& lhs_hp, const HasPtr& rhs_hp)
{
	return *lhs_hp.ps < *rhs_hp.ps;
}



//-----Á·Ï°13.28
class TreeNode
{
public:
	TreeNode() :value(string()), count(new int(1)), left(nullptr), right(nullptr){}
	TreeNode(const TreeNode& rhs):value(rhs.value),count(rhs.count),left(rhs.left),right(rhs.right)
	{
		++* count;
	}
	TreeNode& operator=(const TreeNode& rhs)
	{
		++* rhs.count;
		if (-- * count == 0)
		{
			delete count;
			delete left;
			delete right;
		}
		value = rhs.value;
		count = rhs.count;
		left = rhs.left;
		right = rhs.right;
		return *this;
	}
	~TreeNode()
	{
		if (-- * count == 0)
		{
			delete count;
			delete left;
			delete right;
		}
	}
private:
	string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};
class BinStrTree
{
public:
	BinStrTree():root(new TreeNode()){}
	BinStrTree(const BinStrTree&bst):root(bst.root){}
	BinStrTree& operator=(const BinStrTree& bst)
	{
		TreeNode* new_root = new TreeNode(*bst.root);
		delete root;
		root = new_root;
		return *this;
	}
	~BinStrTree()
	{
		delete root;
	}
private:
	TreeNode* root;
};