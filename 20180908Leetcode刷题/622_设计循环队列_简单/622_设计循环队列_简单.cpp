#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//���ʵ��˫�˶��С�
//���ʵ����Ҫ֧�����²�����
//
//MyCircularDeque(k)�����캯��, ˫�˶��еĴ�СΪk��
//insertFront()����һ��Ԫ����ӵ�˫�˶���ͷ���� ��������ɹ����� true��
//insertLast()����һ��Ԫ����ӵ�˫�˶���β������������ɹ����� true��
//deleteFront()����˫�˶���ͷ��ɾ��һ��Ԫ�ء� ��������ɹ����� true��
//deleteLast()����˫�˶���β��ɾ��һ��Ԫ�ء���������ɹ����� true��
//getFront()����˫�˶���ͷ�����һ��Ԫ�ء����˫�˶���Ϊ�գ����� - 1��
//getRear()�����˫�˶��е����һ��Ԫ�ء� ���˫�˶���Ϊ�գ����� - 1��
//isEmpty()�����˫�˶����Ƿ�Ϊ�ա�
//isFull()�����˫�˶����Ƿ����ˡ�
//
//ʾ����
//MyCircularDeque circularDeque = new MycircularDeque(3); // ����������СΪ3
//circularDeque.insertLast(1);			// ���� true
//circularDeque.insertLast(2);			// ���� true
//circularDeque.insertFront(3);			// ���� true
//circularDeque.insertFront(4);			// �Ѿ����ˣ����� false
//circularDeque.getRear();  				// ����  32
//circularDeque.isFull();				// ���� true
//circularDeque.deleteLast();			// ���� true
//circularDeque.insertFront(4);			// ���� true
//circularDeque.getFront();				// ���� 4
//
//��ʾ��
//����ֵ�ķ�ΧΪ[1, 1000]
//���������ķ�ΧΪ[1, 1000]
//�벻Ҫʹ�����õ�˫�˶��п⡣

class MyCircularDeque {
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		rongliang = k;
		cur = 0;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull())
			return false;
		vec.insert(vec.begin(), value);
		cur++;
		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull())
			return false;
		vec.push_back(value);
		cur++;
		return true;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty())
			return false;

		vec.erase(vec.begin());
		cur--;
		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty())
			return false;

		vec.erase(vec.end() - 1);
		cur--;
		return true;
	}

	/** Get the front item from the deque. */
	int getFront() {
		if (isEmpty())
			return -1;
		return vec[0];
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (isEmpty())
			return -1;

		return vec[vec.size() - 1];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return cur == 0;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return cur == rongliang;
	}
	vector<int>vec;
	int rongliang;
	int cur;
};

/**
* Your MyCircularDeque object will be instantiated and called as such:
* MyCircularDeque obj = new MyCircularDeque(k);
* bool param_1 = obj.insertFront(value);
* bool param_2 = obj.insertLast(value);
* bool param_3 = obj.deleteFront();
* bool param_4 = obj.deleteLast();
* int param_5 = obj.getFront();
* int param_6 = obj.getRear();
* bool param_7 = obj.isEmpty();
* bool param_8 = obj.isFull();
*/

int main() {
	//test1
	MyCircularDeque circularDeque(3); // ����������СΪ3
	bool a = circularDeque.insertLast(1);			// ���� true
	bool b = circularDeque.insertLast(2);			// ���� true
	bool c = circularDeque.insertFront(3);			// ���� true
	bool d = circularDeque.insertFront(4);			// �Ѿ����ˣ����� false
	int e = circularDeque.getRear();  				// ����  2
	bool f = circularDeque.isFull();				// ���� true
	bool g = circularDeque.deleteLast();			// ���� true
	bool h = circularDeque.insertFront(4);			// ���� true
	int i = circularDeque.getFront();				// ���� 4
	cout << a << endl << b << endl << c << endl << d << endl << e << endl << f << endl << g << endl << h << endl << i << endl;
	//test end
	system("pause");
	return 0;
}