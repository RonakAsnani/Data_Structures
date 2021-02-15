#include <bits/stdc++.h>
using namespace std;

template <typename T>

class MapNode
{
public:
    string key;
    T value;
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

class OurMap
{
    MapNode<T> **buckets;
    int count;
    int numBuckets;

public:
    OurMap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<T> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~OurMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int getSize()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currCoeff;
            hashcode = hashcode % numBuckets;
            currCoeff *= 37;
            currCoeff = currCoeff % numBuckets;
        }
        return hashcode % numBuckets;
    }

public:
    void insert(string key, T value)
    {
        int bucketIndex = getBucketIndex(string key);
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
        node->next = next;
        buckets[bucketIndex] = node;
        count++;
    }

    T getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
        }
        return 0;
    }

    T remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
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
                T value = head->next;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};