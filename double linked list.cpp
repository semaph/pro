#include <iostream>
using namespace std;

struct Node
{
	int v;
	Node *prev, *next;
}a[100000];

int arr_idx = 0;
Node *myalloc()
{
	return &a[arr_idx++];
}

int main()
{
	/* --- init -------------- */
	Node *head = myalloc();
	Node *tail = myalloc();

	head->next = tail;
	tail->prev = head;

	/* --- insert (1) --------- */
	Node *node1 = myalloc();
	node1->v = 1;

	node1->prev = tail->prev;
	tail->prev = node1;

	node1->next = tail;
	node1->prev->next = node1;

	/* --- insert (2) --------- */
	Node *node2 = myalloc();
	node2->v = 2;

	node2->prev = tail->prev;
	tail->prev = node2;

	node2->next = tail;
	node2->prev->next = node2;

	/* --- insert (3) ---------- */
	Node *node3 = myalloc();
	node3->v = 3;

	node3->prev = tail->prev;
	tail->prev = node3;

	node3->next = tail;
	node3->prev->next = node3;

	/* ---- print -------------- */
	for (Node *iter = head->next; iter != tail; iter = iter->next)
	{
		cout << iter->v << " ";
	}
	cout << endl;

	/* ---- delete -------------- */
	for (Node *iter = head->next; iter != tail; iter = iter->next)
	{
		if (iter->v == 2)
		{
			iter->prev->next = iter->next;
			iter->next->prev = iter->prev;
		}
	}

	/* ---- print --------------- */
	for (Node *iter = head->next; iter != tail; iter = iter->next)
	{
		cout << iter->v << " ";
	}
	cout << endl;
}