#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct node {
	int data;
	node* right;
	node* left;
};
node* create(int num) {
	node* t = new node();
	t->data = num;
	t->left = NULL;
	t->right = NULL;
	return t;
}

node* find(node* root, int num) {
	if (num > (root->data)) {
		if (root->right != NULL) {
			return find(root->right, num);
		}
	}
	if (num < (root->data)) {
		if (root->left != NULL) {
			return find(root->left, num);
		}
	}
	if (num == root->data) {
		return root;
	}
	return NULL;
}

void insert(node* root, int num) {
	if (num > (root->data)) {
		if (root->right != NULL) {
			insert(root->right, num);
			return;
		}
		node* temp = create(num);
		root->right = temp;
		return;
	}
	if (num <= (root->data)) {
		if (root->left != NULL) {
			insert(root->left, num);
			return;
		}
		node* temp = create(num);
		root->left = temp;
		return;
	}
}

void del(node*& root, int num) {
	node* temp = root;
	node* parent = temp;
	while (temp != NULL && temp->data != num) {
		if (temp->data >= num) {
			temp = temp->left;
		}
		if (temp->data < num) {
			temp = temp->right;
		}
	}
	if (temp == root) {
		if (temp->left == NULL) {
			node* t = root;
			root = temp->right;
			delete t;
			return;
		}
		if (temp->right == NULL) {
			node* t = root;
			root = temp->left;
			delete t;
			return;
		}

	}
	if (temp == NULL) {
		return;
	}
	if (temp->left == NULL) {
		parent->right = temp->right;
		delete temp;
		return;
	}
	if (temp->right == NULL) {
		parent->left = temp->left;
		delete temp;
		return;
	}
	parent = temp;
	node* t = temp;
	temp = temp->left;
	while (temp->right != NULL) {
		parent = temp;
		temp = temp->right;
	}
	if (parent->left == temp) {
		t->data = temp->data;
		parent->left = NULL;
	} else {
		t->data = temp->data;
		parent->right = NULL;
	}
	delete temp;
}

void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* x = q.front();
		q.pop();
		cout << x->data << " ";
		if (x->left != NULL) {
			q.push(x->left);
		}
		if (x->right != NULL) {
			q.push(x->right);
		}
	}

}
void dfs(node* root) {
	stack<node*> s;
	s.push(root);
	while (!s.empty()) {
		node* x = s.top();
		s.pop();
		cout << x->data << " ";
		if (x->right != NULL) {
			s.push(x->right);
		}
		if (x->left != NULL) {
			s.push(x->left);
		}
	}

}

int main() {
	int n;
	cout << "Number of elements:" << endl;
	cin >> n;
	int a;
	cin >> a;
	node* root = create(a);
	for (int i = 1; i < n; i++) {
		cin >> a;
		insert(root, a);
	}
	cout << "bfs:";
	bfs(root);
	cout << endl;
	cout << "dfs:";
	dfs(root);

	cout << endl;
	cout << "del:";
	cin >> a;
	del(root, a);
	cout << "bfs:";
	bfs(root);
	cout << endl;
	cout << "dfs:";
	dfs(root);
	return 0;
}