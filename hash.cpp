#include <iostream>
#define MAX_TABLE 1000007
using namespace std;

int _strlen(const char *s)
{
	int ret = 0;
	while (*s++) ++ret;
	return ret;
}

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2) ++s1, ++s2;
	return *s1 - *s2;
}

void _strcpy(char *s1, const char *s2)
{
	while (*s2) *s1++ = *s2++;
	*s1 = '\0';
}

unsigned long getHashKey(const char *str)
{
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}

struct Node
{
	char data[101];
	Node *prev;
}a[100000];
Node *hTable[MAX_TABLE];
int arr_idx = 0;
char str[101];

Node *myalloc()
{
	return &a[arr_idx++];
}

int main()
{
	/* --- insert ------------- */
	int hkey = getHashKey(str);
	Node *p = myalloc();
	_strcpy(p->data, str);
	p->prev = hTable[hkey];
	hTable[hkey] = p;

	/* --- search ------------- */
	for (Node *pp = hTable[hkey]; pp != NULL; pp = pp->prev)
	{
		if (!_strcmp(pp->data, str))
		{
			// print
		}
	}

	/* --- delete ------------- */
	Node **del = &hTable[hkey];
	for (Node *iter = hTable[hkey]; iter != NULL; iter = iter->prev)
	{
		if (!_strcmp(iter->data, str))
		{
			*del = iter->prev;
		}
		del = &iter->prev;
	}
}