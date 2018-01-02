#pragma once

template <typename T> class DblList;

template <typename T>
class DblListNode {
	friend class DblList<T>;
public:
	DblListNode(T data = T(), DblListNode<T> *left = nullptr, 
		DblListNode<T> *right = nullptr)
		: data_(data), left_(left), right_(right) {}
private:
	T data_;
	DblListNode<T> *left_, *right_;
};

template <typename T>
class DblList {
public:
	class Iterator {
	public:
		Iterator(DblListNode *start_node = nullptr) : current_(start_node) {}
		inline T& operator*() const {
			return current_->data;
		}
		inline T* operator->() const {
			return &current_->data;
		}
		Iterator& operator++() {
			current_ = current_->right;
			return *this;
		}
		Iterator operator++(int) {
			Iterator temp = *this;
			current_ = current_->right;
			return temp;
		}
		Iterator& operator--() {
			current_ = current_->left;
			return *this;
		}
		Iterator operator--(int) {
			Iterator temp = *this;
			current_ = current_->left;
			return temp;
		}
		inline bool operator!=(const Iterator& compared) const {
			return current_ != compared.current_;
		}
		inline bool operator==(const Iterator& compared) const {
			return current_ == compared.current_;
		}
	private:
		Node *current_;
	};
	DblList();
	~DblList();
	void Insert(DblListNode<T>*, DblListNode<T>*);
	void Delete(DblListNode<T>*);
	void Concatenate(DblList<T>);
	Iterator begin();
	Iterator end();
private:
	Node *head_;
};

template <typename T>
DblList<T>::DblList() {
	head_ = new DblListNode<T>();
	head_->left = head_;
	head_->right = head_;
}

template <typename T>
void DblList<T>::Insert(DblListNode<T> *left_neighbor, 
	DblListNode<T> *inserted) {
	inserted->left = left_neighbor;
	inserted->right = left_neighbor->right;
	left_neighbor->right->left = inserted;
	left_neighbor->right = inserted;
}

template <typename T>
void DblList<T>::Delete(DblListNode<T> *deleted) {
	if (deleted == head_)
		throw "Deletion of header node is not allowed.";
	else {
		deleted->left->right = deleted->right;
		deleted->right->left = deleted->left;
		delete deleted;
	}
}

template <typename T>
typename DblList<T>::Iterator DblList<T>::begin() {
	return Iterator(head_->right);
}

template <typename T>
typename DblList<T>::Iterator DblList<T>::end() {
	return Iterator(head_);
}