#ifndef TREE_HPP
#define TREE_HPP
#include "Queue.hpp"
#include "Stack.hpp"

template <typename T> class Tree;

template <typename T>
class TreeNode {
	friend class Tree<T>;
public:
	TreeNode(T &data = T(), TreeNode<T> *left = nullptr,
		TreeNode<T> *right = nullptr)
		: data_(data), left_(left), right_(right) {}
	~TreeNode() {
		delete left_;
		delete right_;
	}
private:
	T data_;
	TreeNode<T> *left_;
	TreeNode<T> *right_;
};

template <typename T>
class Tree {
public:
	Tree();
	Tree(const Tree<T>&);
	Tree(Tree<T>&, T&, Tree<T>&);
	~Tree();
	bool IsEmpty() const;
	bool operator==(const Tree<T>&);
	Tree<T> LeftSubTree();
	Tree<T> RightSubTree();
	T RootData();
	void Preorder();
	void Inorder();
	void Postorder();
	void LevelOrder();
	void NonrecPreorder();
	void NonrecInorder();
	void NonrecPostorder(); // TODO
	class PreorderIterator {

	};
	class InorderIterator {
	public:
		InorderIterator() : current_(root_) {}


	private:
		Stack<TreeNode<T>*> stack;
		TreeNode<T> *current_;
	};
	class PostorderIterator {

	};
	class LevelOrderIterator {

	};
	PreorderIterator PreorderBegin();
	PreorderIterator PreorderEnd();
	InorderIterator InorderBegin();
	InorderIterator InorderEnd();
	PostorderIterator PostorderBegin();
	PostorderIterator PostorderEnd();
	LevelOrderIterator LevelOrderBegin();
	LevelOrderIterator LevelOrderEnd();	
private:
	TreeNode<T>* Copy(TreeNode<T>*);
	bool Equal()(TreeNode<T>*, TreeNode<T>*);
	void Preorder(TreeNode<T>*);
	void Inorder(TreeNode<T>*);
	void Postorder(TreeNode<T>*);
	void Visit(TreeNode<T>*);
	TreeNode<T> *root_;
};

#endif // !TREE_HPP
