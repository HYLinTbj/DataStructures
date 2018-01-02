#include <iostream>
#include "Tree.hpp"
using namespace std;

template <typename T>
Tree<T>::Tree() : root_(nullptr) {}

template <typename T>
Tree<T>::Tree(const Tree& copied) {
	root_ = Copy(copied.root_);
}

template <typename T>
TreeNode<T>* Tree<T>::Copy(TreeNode<T> *original_node) {
	if (!original_node) return nullptr;
	return new Tree<T>(original_node,
		Copy(original_node->left_), Copy(original_node->right_);
}

template <typename T>
Tree<T>::Tree(Tree<T>& left_sub_tree, T& item, Tree<T>& right_sub_tree) {
	root_ = new TreeNode<T>(item, &left_sub_tree, &right_sub_tree)
}

template <typename T>
Tree<T>::~Tree() {
	delete root_;
}

template <typename T>
inline bool Tree<T>::IsEmpty() const {
	return root_ == nullptr;
}

template <typename T>
bool Tree<T>::operator==(const Tree<T>& compared) {
	return Equal(root_, compared.root_);
}

template <typename T>
bool Tree<T>::Equal(TreeNode<T> *a, TreeNode<T> *b) {
	return !a && !b // Both are null pointers
		|| (a && b // Both are not null pointers
		&& a->data_ == b->data_) // And all their fields equal
		&& (Equal(a->left_, b->left_)
		&& Equal(a->right_, b->right_));
}

template <typename T>
Tree<T> Tree<T>::LeftSubTree() {
	Tree<T> left_sub_tree;
	left_sub_tree.root_ = root_->left_;
	return left_sub_tree;
}

template <typename T>
Tree<T> Tree<T>::RightSubTree() {
	Tree<T> right_sub_tree;
	right_sub_tree.root_ = root_->right_;
	return right_sub_tree;
}

template <typename T>
inline T Tree<T>::RootData() {
	return root_->data_;
}

template <typename T>
void Tree<T>::Preorder() {
	Preorder(root_);
}

template <typename T>
void Tree<T>::Inorder() {
	Inorder(root_);
}

template <typename T>
void Tree<T>::Postorder() {
	Postorder(root_);
}

template <typename T>
void Tree<T>::LevelOrder() {
	Queue<TreeNode<T>*> queue;
	TreeNode<T> *current = root_;
	while (current) {
		Visit(current);
		if (current->left_) queue.Push(current->left_);
		if (current->right_) queue.Push(current->right_);
		if (queue.IsEmpty()) return;
		current = queue.Front();
		queue.Pop();
	}
}

template <typename T>
void Tree<T>::Preorder(TreeNode<T> *current) {
	if (current) {
		Visit(current);
		Preorder(current->left_);
		Preorder(current->right_);
	}
}

template <typename T>
void Tree<T>::Inorder(TreeNode<T> *current) {
	if (current) {
		Inorder(current->left_);
		Visit(current);
		Inorder(current->right_);
	}
}

template <typename T>
void Tree<T>::Postorder(TreeNode<T> *current) {
	if (current) {
		Postorder(current->left_);
		Postorder(current->right_);
		Visit(current);
	}
}

template <typename T>
void Tree<T>::NonrecPreorder() {
	Stack<TreeNode<T>*> stack;
	TreeNode<T> *current = root_;
	while (true) {
		while (current) {
			Visit(current);
			stack.push(current);
			current = current->left_;
		}
		if (stack.isEmpty()) return;
		current = stack.top();
		stack.pop();
		current = current->right_;
	}
}

template <typename T>
void Tree<T>::NonrecInorder() {
	Stack<TreeNode<T>*> stack;
	TreeNode<T> current = root_;
	while (true) {
		while (current) {
			stack.push(current);
			current = current->left_;
		}
		if (stack.isEmpty()) return;
		current = stack.top();
		stack.pop();
		Visit(current);
		current = current->right_;
	}
}

template <typename T>
void Tree<T>::NonrecPostorder() {

}

template <typename T>
void Tree<T>::Visit(TreeNode<T>* visited) {
	cout << visited->data_ << ' ';
}

template <typename T>
Tree<T>::PreorderIterator Tree<T>::PreorderBegin() {
	return PreorderIterator(root_);
}

template <typename T>
Tree<T>::PreorderIterator Tree<T>::PreorderEnd() {
	return PreorderIterator(nullptr);
}

template <typename T>
Tree<T>::InorderIterator Tree<T>::InorderBegin() {
	if (root_) return InorderIterator(nullptr);
	TreeNode<T> *leftmost = root_;
	while (leftmost->left_)
		leftmost = leftmost->left_;
	return InorderIterator(leftmost);
}

template <typename T>
Tree<T>::InorderIterator Tree<T>::InorderEnd() {
	return InorderIterator(nullptr);
}

template <typename T>
Tree<T>::PostorderIterator Tree<T>::PostorderBegin() {
	if (root_) return PostorderIterator(nullptr);
	TreeNode<T> *leftmost = root_;
	while (leftmost->left_)
		leftmost = leftmost->left_;
	return PostorderIterator(leftmost);
}

template <typename T>
Tree<T>::PostorderIterator Tree<T>::PostorderEnd() {
	return PostorderIterator(nullptr);
}

template <typename T>
Tree<T>::LevelOrderIterator Tree<T>::LevelOrderBegin() {
	return LevelOrderIterator(root_);
}

template <typename T>
Tree<T>::LevelOrderIterator Tree<T>::LevelOrderEnd() {
	return LevelOrderIterator(nullptr);
}