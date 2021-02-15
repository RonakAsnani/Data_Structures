#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MapNode
{
public:
    T value;
    string key;
    MapNode *next;

    MapNode(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename T>

class Ourmap
{
public:
    MapNode<T> **buckets;
    int count;
    int numBuckets;

    Ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<T> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = 0;
        }
    }
    ~Ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
    }

    int size()
    {
        return count;
    }

private:
    int getHashIndex(string key)
    {
        int hash = 0;
        int currCoeff = 1;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            hash += key[i] * currCoeff;
            hash = hash % numBuckets;
            currCoeff *= 37;
            currCoeff = currCoeff % numBuckets;
        }
        return hash % numBuckets;
    }
    void rehash()
    {
        MapNode<T> **temp = buckets;
        buckets = new MapNode<T>[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = 0;
        }
        int oldBuckets = numBuckets;
        numBuckets *= 2;
        count = 0;
        for (int i = 0; i < oldBuckets; i++)
        {
            MapNode<T> *head = temp[i];
            while (head != 0)
            {
                string key = key;
                T value = value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int = 0; i < oldBuckets; i++)
        {
            MapNode<T> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insert(string key, T value)
    {
        int bucketIndex = getHashIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<T> *node = new MapNode<T>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    T remove(string key)
    {
        int bucketIndex = getHashIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        MapNode<T> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                T val = head->value;
                head->next = NULL;
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head->next;
        }
    }
    T getValue(string key)
    {
        int bucketIndex = getHashIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        while (head != 0)
        {
            if (head->key == key)
            {
                return head->value;
            }
        }
        return 0;
    }
};
