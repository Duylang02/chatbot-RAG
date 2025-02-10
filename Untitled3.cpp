#include<iostream>

using namespace std;

template <typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int current;

public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;  
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current++] = data; 
    }

    T get(int index) {
        if (index >= 0 && index < current)
            return arr[index];
    }

    void pop() {
        if (current > 0) current--;
    }

    int size() {
        return current;
    }

    int getCapacity() {
        return capacity;
    }

    bool isEmpty() { return current == 0; }

    void display() {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T& operator[](int index) {
        if (index >= 0 && index < current)
            return arr[index];
    }
};
//
//class Node {
//public:
//    int data;
//    Vector<Node*> children; 
//
//    Node(int value) {
//        data = value;
//    }
//
//    void addChild(Node* parent, int value) {
//        Node* child = new Node(value);
//        parent->children.push_back(child);
//    }
//};

//void traverseTree(Node* root) {
//    if (root == NULL) return;
//    cout << root->data << " ";
//    for (int i = 0; i < root->children.size(); i++) {
//        traverseTree(root->children[i]); 
//    }
//}
//
//Vector<int> node;
//bool checkExist(int x) {
//    for (int i = 0; i < node.size(); i++) {
//        if (node.get(i) == x)
//            return true;
//    }
//    return false;
//}

int ans = 0;
void dfs(Vector<int> a[], int x, bool visited[]){
	//cout << x << endl;
	visited[x] = true;
	if(a[x].isEmpty()){
		if(ans < x) ans = x;
	}	
	
	for(int i = 0; i < a[x].size(); i++){
		if (visited[a[x][i]] == false)
			dfs(a, a[x][i], visited);
	}
}
int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int root;
    cin >> root;
    int c, d;
    Vector<int> a[100];
	bool visited[100] = {false};
    for (int i = 0; i < n/2; i++) {
        cin >> c >> d;
        a[c].push_back(d); 
    }
	
	ans = 0;
	dfs(a, root, visited);
	
	cout << ans <<endl;
}

