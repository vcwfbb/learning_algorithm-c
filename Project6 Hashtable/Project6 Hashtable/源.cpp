#include<iostream>
using namespace std;
template<typename keyType, typename valueType>
class Hashtable {
private:
	struct Hashnode {
		keyType key;
		valueType value;
		Hashnode* next;
	};
	int hashkey(const keyType& key) const {
		int ret = key % size;
		if (ret < 0) {
			ret += size;
		}
		return ret;
	}
	int size;
	Hashnode** table;
public:
	Hashtable(int size);
	~Hashtable();
	void insert(const keyType& key, const valueType& value);
	void remove(const keyType& key);
	bool find(const keyType& key, valueType& value) const;
};

template<typename keyType, typename valueType>
Hashtable<keyType, valueType>::Hashtable(int size) {
	this->size = size;
	this->table = new Hashnode * [size];
	for (int i = 0; i < size; ++i) {
		table[i] = NULL;
	}
}
template<typename keyType, typename valueType>
Hashtable<keyType, valueType>::~Hashtable() {
	for (int i = 0; i < size; ++i) {
		Hashnode* cur = table[i];
		while (cur) {
			Hashnode* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		table[i] = NULL;
	}
	delete[] table;
	table = NULL;
}

template<typename keyType, typename valueType>
void Hashtable<keyType, valueType>::insert(const keyType& key, const valueType& value) {
	int index = hashkey(key);
	Hashnode* newnode = new Hashnode;
	newnode->next = NULL;
	newnode->key = key;
	newnode->value = value;
	if (table[index] == NULL) {
		table[index] = newnode;
	}
	else {
		newnode->next = table[index];
		table[index] = newnode;
	}
}

template<typename keyType, typename valueType>
void Hashtable<keyType, valueType>::remove(const keyType& key) {
	int index = hashkey(key);
	Hashnode* cur = table[index];
	Hashnode* pre = NULL;
	while (cur) {
		if (cur->key == key) {
			if (pre == NULL) {
				table[index] = cur->next;
			}
			else {
				pre->next = cur->next;
			}
			delete cur;
			return;
		}
		pre = cur;
		cur = cur->next;
	}
}
template<typename keyType, typename valueType>
bool Hashtable<keyType, valueType>::find(const keyType& key, valueType& value) const {
	int index = hashkey(key);
	Hashnode* cur = table[index];
	while (cur) {
		if (cur->key == key) {
			cout << "find ";
			value = cur->value;
			return true;
		}
		cur = cur->next;
	}
	cout << "NOT find " << endl;
	return false;
}
int main() {
	Hashtable<int, char> t(6);
	t.insert(1, 'a');
	t.insert(2, 'b');
	t.insert(3, 'c');
	t.insert(4, 'd');
	t.insert(5, 'e');
	t.insert(6, 'f');
	t.remove(5);
	char ch;
	if (t.find(4, ch)) {
		cout << ch << endl;
	}
	if (t.find(5, ch)) {
		cout << ch << endl;
	}
	return 0;
}