template <typename V>

class MapNode
{
public:
    string key;
    v value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next == NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (!prev)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                head->next = NULL;
                V value = head->value;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += currentCoeff * key[i];
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashCode % numBuckets;
    }

    void rehash()
    {
        auto temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;

        for (auto i : temp)
        {
            auto head = temp;
            while (head)
            {
                insert(head->key, head->val);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketSize; i++)
        {
            auto head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
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
        MapNode<V> *node = MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
};