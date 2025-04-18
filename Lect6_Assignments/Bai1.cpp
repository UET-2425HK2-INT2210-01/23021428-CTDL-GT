#include <iostream>
using namespace std;
// tạo cấu trúc 1 node
struct Node {
	int data;// dữ liệu
	Node* pRight;// node phải
	Node* pLeft; // node trái
};

// hàm tạo 1 node mới
Node* makeNode(int x)
{
	Node* newNode = new Node();// cấp phát động
	newNode->data = x;// data của node mới bằng x
	newNode->pRight = NULL;// 2 node con bằng NULL
	newNode->pLeft = NULL;
	return newNode;// trả về node mới tạo
}

// tạo 1 class Tree
class Tree {
public:
	Node* root = NULL; // node gốc
	// hàm thêm 1 node vào cây
	void insert(Node*& root, int x)// giá trị nhận vào là địa chỉ root và giá trị x
	{
		// nếu root rỗng
		if (root == NULL)
		{
			Node* newNode = makeNode(x);// tạo 1 node mới có giá trị x
			root = newNode;// cho root bằng newNode
		}
		else {// nếu root không rỗng thì so sánh x với root rồi đệ quy xuống
			if (x < root->data) // nếu x nhỏ hơn root
			{
				insert(root->pLeft, x);// đệ quy trái
			}
			else {
				insert(root->pRight, x);// đệ quy phải
			}
		}
	}

	// hàm duyệt cây theo inorder
	void LNR(Node*& root) // giá trị nhận vào là địa chỉ node gốc
	{
		if(root != NULL)// nếu gốc không rỗng
		{
			LNR(root->pLeft);// đệ quy trái
			cout << root->data << ' ';// in data
			LNR(root->pRight);// đệ quy phải
		}
	}

	// hàm tìm phần tử nhỏ nhất bên phải node cần xóa
	void minNode(Node*& X, Node*& Y)// node X là Node cần xóa
	{
		if (Y->pLeft != NULL)
		{
			minNode(X, Y->pLeft);// cho Y chạy đến node nhỏ nhất 
		}
		else {
			X->data = Y->data;// cho data X = data Y
			X = Y;// cho X trỏ đến Y
			Y = NULL;// cập nhật Y == NULL
		}
	}

	// hàm xóa 1 phần tử x
	void Delete(Node*& root, int x)
	{
		if (root == NULL) return;// nếu cây rỗng
		if (x < root->data) // nếu x < hơn gốc
		{
			Delete(root->pLeft, x);// đệ quy qua trái
		}
		else if (x > root->data) { // nếu x lớn hơn gốc
			Delete(root->pRight, x);// đệ quy qua phải
		}
		else {// trường hợp đã tìm được vị tríc của giá trị x
			Node* tmp = root;// cho tmp = node có giá trị x
			// nếu node có chỉ có 1 con
			if (root->pLeft == NULL)// nếu node đó không có con trái
			{
				root = root->pRight;// cho node dó trỏ đến node phải
			}
			else if (root->pRight == NULL) {// nếu không có con phải
				root = root->pLeft;// cho trỏ sang trái
			}
			else {
				Node* Y = root->pRight;// cho node Y trỏ đến node phải của giá trị cần xóa
				minNode(tmp, Y);//lúc này tmp đã ở vị trí của node nhỏ nhất bên phải
			}

			delete tmp;// xóa tmp
		}
	}
};



int main()
{
	int array[] = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };// danh sách giá trị
	Node* root = NULL;
	Tree tree;
	for (int x : array)
	{
		tree.insert(root, x);// chèn từng phần tử vào cây
	}

	tree.insert(root, 14);
	tree.insert(root, 0);
	tree.insert(root, 35);
	tree.Delete(root, 6);
	tree.Delete(root, 13);
	tree.Delete(root, 35);
	tree.LNR(root);

	return 0;
}
