#pragma once

#include <exception>


class stackOverflow : public std::exception {
public:
	const char* what() {
		return "stackOverflow Exception";
	}
};

class stackUnderflow : public std::exception {
public:
	const char* what() {
		return "stackUnderflow Exception";
	}
};

template<typename T>
class Stack {
private:
	T** items;
	const int size;
	int num = 0;
	
public:
	Stack(int sz) : size(sz) { items = new T*[size];  }
	~Stack() {
		delete[] items;
	}
	void push(T* top) { //adds item to stack
		if (num >= size) { throw stackOverflow(); }
		items[num] = top;
		num++;
	}
	T* pop() { //returns and removes latest item from stack
		if (num <= 0) { throw stackUnderflow(); }
		num--;
		return items[num];
	}
	T* top() { //gets the latest item in the stack
		if (num == 0) { throw stackUnderflow(); }
		return items[num - 1]
	}
	int length() { //gets stack length
		return num;
	}
	bool isEmpty() { //checks if stack is empty
		return num == 0;
	}
	void empty() { //clears stack contents
		num = 0;
	}
};