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
	virtual ~Stack() {}// Виртуальный - для переопределения 

// Абстрактные операции со стеком 

	virtual void push(const T& e) = 0; // Добавление элемента в стек  
	virtual const T& pop() = 0;// Удаление и возвращение верхнего элемента.                               // Если элементов нет, может возникнуть StackUnderflow  
	virtual bool isEmpty() = 0; // Проверка стека на пустоту  

};

class WrongStackSize : public std::exception {
public: 
	WrongStackSize() : reason("Wrong Stack Size") {} 
	const char* what() const { return reason; } 
private:  
	const char* reason;  // ! const 

};