#pragma once


constexpr auto HASHNUM = 10;//#define HASHNUM 10
typedef unsigned int KeyType;

//typedef struct {}DataType;

typedef struct HashNode
{
	KeyType key;
	//DataType data;
	struct HashNode* next;
}HashNode;

typedef struct
{
	HashNode* hashTable[HASHNUM];
	//int num;
}MyHash;


void InitHash(MyHash* hash)
{
	if (hash == NULL)	exit(0);

	for (int i = 0; i < HASHNUM; i++)
	{
		hash->hashTable[i] = NULL;
	}
}

//哈希函数  （散列函数）
static int Hash(KeyType key)
{
	return key % HASHNUM;
}

//SearchNot方法在插入时使用，保证Hash中没有重复的key值
static int SearchNot(MyHash* hash, KeyType key, int pos)
{
	HashNode* p = hash->hashTable[pos];

	while (p != NULL)
	{
		if (p->key == key)
			return 0;
		p = p->next;
	}

	return 1;
}

static HashNode* _ApplyHashNode(KeyType key, HashNode* next)
{
	HashNode* s = (HashNode*)malloc(sizeof(HashNode));

	if (s == NULL)		exit(0);
	s->key = key;
	s->next = next;
}

int InsertHash(MyHash* hash, KeyType key)
{
	if (hash == NULL)	exit(0);

	int pos = Hash(key);

	if (SearchNot(hash, key, pos))
	{
		HashNode *s = _ApplyHashNode(key, hash->hashTable[pos]);
		if (s != NULL)
		{
			hash->hashTable[pos] = s;
			return 1;
		}
	}
	return 0;
}

HashNode* Search(MyHash* hash, KeyType key)
{
	if (hash == NULL)	exit(0);

	HashNode* p = hash->hashTable[Hash(key)];

	while (p != NULL)
	{
		if (p->key == key)
			return p;
		p = p->next;
	}

	return NULL;
}

int DeleteHash(MyHash* hash, KeyType key)
{
	if (hash == NULL)	exit(0);

	int pos = Hash(key);

	HashNode* p = hash->hashTable[pos];
	HashNode* pr = NULL;

	while (p != NULL)
	{
		if (p->key == key)
			break;

		pr = p;
		p = p->next;
	}

	//在链表中没有找到与key相等的节点
	if (p == NULL)
		return 0;

	// 链表中的第一个节点就是要删除的节点，头删法（不带头结点的单链表）
	if (pr == NULL)
	{
		hash->hashTable[pos] = p->next;
		free(p);
	}
	else
	{
		pr->next = p->next;
		free(p);
	}

	return 1;
}

void DestroyHash(MyHash* hash)
{
	if (hash == NULL)	exit(0);

	for (int i = 0; i < HASHNUM; i++)
	{
		while (hash->hashTable[i] != NULL)
		{
			HashNode* p = hash->hashTable[i];
			hash->hashTable[i] = p->next;
			free(p);
		}
	}
}
