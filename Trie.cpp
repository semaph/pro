#include <iostream>
using namespace std;

/*
nodes�� nodesCnt�� myAlloc()�� ����
�����Ҵ��� �����Ҵ��� �� ó�� ����ϱ� ���� �Լ�
*/
struct Node
{
	bool isWord;
	Node *children[ALPHABET_NUM];
} nodes[MAX_TREE_SIZE];
int nodesCnt = 0;

Node *myAlloc()
{
	for (int i = 0; i < ALPHABET_NUM; i++)
		nodes[nodesCnt].children[i] = NULL;
	
	nodes->isWord = false;
	return &nodes[nodesCnt++];
}

/*
������ �湮�� ���� ���� �κ� ���ڿ��̸� ���ο� ��带 �Ҵ��ϸ鼭
Trie�� root�������� �־��� ���ڿ��� ������ Ÿ�� ������.
�������� str[i] == NULL�� ������ ������ ���ڿ��� ���̱� ������ �ݺ����� ������
isWord = true�� ���� �ش� ��尡 �ܾ��� ���� ǥ��.
*/
void add(Node *root, char *str)
{
	Node *c = root;
	for (int i = 0; str[i]; i++)
	{
		int nextIdx = str[i] - 'a';

		if (c->children[nextIdx])
		{
			c = c->children[nextIdx];
		}

		else
		{
			Node *newNode = myAlloc();
			c->children[nextIdx] = newNode;
			c = c->children[nextIdx];
		}
	}

	c->isWord = true;
}

/*
���ڿ��� Trie�� �������� ������ NULL�� ��ȯ.
���� �ܾ� ���� ����� �ʿ��ϴٸ� find()����
Node�� ã�� ������ isWord�� false�� ����� �ָ� ��.
*/
Node *find(Node *root, char *str)
{
	Node *c = root;
	for (int i = 0; str[i]; i++)
	{
		int nextIdx = str[i] - 'a';
		c = c->children[nextIdx];
		if (!c) return NULL;
	}
	return c;
}

/*
�־��� Trie root�� ��� ���ڿ��� ���������� ����ϴ� �Լ�.
a~z�� ���� children �迭�� 0~25�� ���εǾ� �ֱ� ������
������� �湮�ϸ� ���������� �湮�ϴ� ȿ��.
�� ��带 �湮�ϸ鼭 isWord�� true�� �ܾ��̱� ������ res�迭�� ����.
*/
void list(Node *root, char *str, int strIdx, char res[][MAX_STRING_SIZE], int &resIdx)
{
	if (root->isWord)
		strcpy(res[resIdx++], str);

	for (int i = 0; i < ALPHABET_NUM; i++)
	{
		if (root->children[i])
		{
			str[strIdx] = i + 'a';
			str[strIdx + 1] = NULL;
			list(root->children[i], str, strIdx + 1, res, resIdx);
		}
	}
}

int main()
{
	Node *root = myAlloc();

	for (int i = 0; i < 9; i++)
		add(root, A[i]);

	char str[1000];
	char res[MAX_RESULT_SIZE][MAX_STRING_SIZE];
	int resIdx = 0;

	list(root, str, 0, res, resIdx);

	for (int i = 0; i < resIdx; i++)
		cout << res[i];

	return 0;
}