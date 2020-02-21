#include <exception> 

using namespace std;

class StackOverflow : public std::exception {
public:  
	StackOverflow() : reason("Stack Overflow") {}  
	const char* what() const { return reason; }
private: 
	const char* reason;  // ! const 
};

class StackUnderflow : public std::exception {
public:  
	StackUnderflow() : reason("Stack Underflow") {}  
	const char* what() const { return reason; } 
private:  
	const char* reason;  // ! const 
};

template <class T> class Stack {
public:   
	virtual ~Stack() {}// ����������� - ��� ��������������� 

// ����������� �������� �� ������ 

	virtual void push(const T& e) = 0; // ���������� �������� � ����  
	virtual const T& pop() = 0;// �������� � ����������� �������� ��������.                               // ���� ��������� ���, ����� ���������� StackUnderflow  
	virtual bool isEmpty() = 0; // �������� ����� �� �������  

};

class WrongStackSize : public std::exception {
public: 
	WrongStackSize() : reason("Wrong Stack Size") {} 
	const char* what() const { return reason; } 
private:  
	const char* reason;  // ! const 

};