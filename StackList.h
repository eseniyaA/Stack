#pragma once
#include "Stack.h"

template<typename T>
class StackLinkedList : public Stack<T> 
{
public:

	StackLinkedList() : top_(nullptr) {}

	~StackLinkedList() 
	{
		while (!top_->next_)
		{
			Node* temp;
			temp->next_ = top_->next_;
			temp->item = top_->item;
			delete top_;
			top_ = temp;
		}
	}
	
	bool isEmpty() const 
	{
		return (top_ == nullptr);
	}

	void push(const T& item) override
	{
		Node* newItem = new Node;
		newItem->item_ = item;
		newItem->next = top_;
		top_ = newItem;
	}
	
	T pop() override
	{
		if (isEmpty())
			throw std::underflow_error{ "Stack is empty!" };
		int temp = top_->item;
		Node* oldTop = top_;
		delete top_;
		top_ = oldTop->next_;
		return temp;
	}

private:

	struct Node
	{
		Node* next_;
		T item_;
		Node() : next_{ nullptr } {}
	};

	Node* top_;
};