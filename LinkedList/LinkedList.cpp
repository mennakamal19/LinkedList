#include <iostream>
#include <list> 
#include <iterator> 
using namespace std;

template<class T>
class Item 
{
private:T val;
       Item<T>* nxt;
public:
	Item() : val(0), nxt(NULL) {

	}
	T getVal() {
		return val;
	}
	void setVal(T _val) {
		val = _val;
	}
	Item<T>* getCur() {
		return this;
	}
	void setNxt(Item<T>* _nxt) {
		nxt = _nxt;
	}
	Item<T>* getNxt() {
		return nxt;
	}
};
template <class T>
class List {
private:
	Item<T>* head;
	int sz;
public:
	List() :head(NULL), sz(0) {

	}
	~List() {
		while (sz)
			del(0);//??
		cout << sz << endl;
	}
	int getSz() {
		return sz;
	}
	void add(T d) {
		Item<T>* data = new Item<T>();
		data->setVal(d);
		if (head == NULL) {
			head = data;
			++sz;
			return;
		}
		Item<T>* it = head;
		for (; it->getNxt() != NULL; it = it->getNxt());
		it->setNxt(data);
		++sz;
	}
	void insert(int idx, T d) {
		if (idx < 0 || idx > sz)
			return;
		if (idx == sz) {
			add(d); return;
		}
		Item<T>* data = new Item<T>();
		data->setVal(d);
		Item<T>* it = head;
		if (idx == 0) {
			data->setNxt(head);
			head = data;
			return;
		}
		for (int i = 1; i < idx; i++, it = it->getNxt());
		data->setNxt(it->getNxt());
		it->setNxt(data);
		++sz;
	}
	void del(int idx) {
		if (idx < 0 || idx >= sz)
			return;
		Item<T>* it = head, * prv;
		if (idx == 0) {
			Item<T>* t = head->getNxt();
			delete head;
			head = t;
			--sz;
			return;
		}
		for (int i = 1; i < idx; i++, it = it->getNxt());
		prv = it->getNxt();
		it->setNxt(it->getNxt()->getNxt());
		delete prv;
		--sz;

	}
	void show() {
		Item<T>* it = head;
		while (it != NULL) {
			cout << it->getVal() << endl;
			it = it->getNxt();
		}
	}
};

int main()
{
	List<int>* t = new List<int>();
	t->add(1);
	t->add(3);
	t->add(6);
	t->insert(1, 2);
	t->show();

}

