#include<iostream>
#include<iomanip>
using namespace std;
#define elemtype int
//----------创建顺序表
struct SequentialList {
	int size;
	int capacity;
	elemtype* elements;
};
//----------初始化顺序表
void InitializeList(SequentialList* list,int capacity) {
	list->elements = new elemtype[capacity];
	list->capacity = capacity;
	list->size = 0;
}
//----------销毁顺序表
void DetrpyList(SequentialList* list) {
	delete[] list->elements;
}
//------------获取顺序表大小
int getsize(SequentialList* list) {
	return list->size;
}
//------------检查顺序表是否为空
bool isEmpty(SequentialList* list) {
	if (list->size == 0) {
		return true;
	}
	else {
		return false;
	}
}
//--------------------顺序表的插入
void insert(SequentialList* list, int index, elemtype element) {
	if (index<0 || index>list->size) {
		throw std::invalid_argument("invalid index");
	}
	if (list->size == list->capacity) {
		int newcapacity = 2 * list->capacity;
		elemtype* newelements = new elemtype[newcapacity];
		for (int i = 0; i < list->size; i++) {
			newelements[i] = list->elements[i];
		}
		delete[] list->elements;
		list->capacity = newcapacity;
		list->elements = newelements;
	}//----------扩容
	for (int i = list->size; i > index; --i) {
		list->elements[i] = list->elements[i - 1];
	}
	list->elements[index] = element;
	list->size++;
}
//----------------------顺序表的删除
void delelement(SequentialList* list,int index) {
	if (index<0 || index>=list->size) {
		throw std::invalid_argument("invalid index");
	}
	for (int i = index; i < list->size; ++i){
		list->elements[i] = list->elements[i + 1];
	}
	list->size--;
}
//---------------------顺序表的查找
int findelement(SequentialList* list, elemtype target) {
	for (int i = 0; i < list->size; i++) {
		if (list->elements[i] == target) {
			return i;
		}
	}
	return -1;
}
//--------------------顺序表的索引
elemtype getindex(SequentialList* list, int index) {
	return list->elements[index];
}
//---------------------顺序表元素修改
void update(SequentialList* list, int index, elemtype element) {
	list->elements[index] = element;
}
//---------------------打印顺序表所有元素
void Print(SequentialList* list) {
	for (int i = 0; i < list->size; ++i) {
		cout << list->elements[i] << " ";
	}
	cout << endl;
}
int main() {
	SequentialList list;
	InitializeList(&list, 10);
	insert(&list, 0, 2);
	insert(&list, 0, 2);
	Print(&list);
	return 0;
}