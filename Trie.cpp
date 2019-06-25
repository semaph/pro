#include <iostream>
using namespace std;

/*
nodes와 nodesCnt는 myAlloc()을 통해
정적할당을 동적할당한 것 처럼 사용하기 위한 함수
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
기존에 방문한 적이 없는 부분 문자열이면 새로운 노드를 할당하면서
Trie를 root에서부터 주어진 문자열의 끝으로 타고 내려옴.
마지막에 str[i] == NULL인 지점을 만나면 문자열의 끝이기 때문에 반복문을 나오고
isWord = true를 통해 해당 노드가 단어인 것을 표시.
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
문자열이 Trie에 존재하지 않으면 NULL을 반환.
만약 단어 삭제 기능이 필요하다면 find()에서
Node를 찾은 다음에 isWord를 false로 만들어 주면 됨.
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
주어진 Trie root의 모든 문자열을 사전순으로 출력하는 함수.
a~z가 각각 children 배열의 0~25로 매핑되어 있기 때문에
순서대로 방문하면 사전순으로 방문하는 효과.
각 노드를 방문하면서 isWord가 true면 단어이기 때문에 res배열에 복사.
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