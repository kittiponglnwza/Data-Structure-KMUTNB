#include <bits/stdc++.h>
using namespace std;

class open_addressing
{
    public:
        int hash_key[100];
        string hash_table[100];
        int n = 0;
        int r = 0;

    open_addressing(int p_n, int p_r)
    {
        n = p_n;
        r = p_r;
        for(int i=0; i < n; i++)
        {
            hash_key[i] = -1;
            hash_table[i] = "";
        }
    }

    void add_modulo_division(int key, string data)
    {
        hash_key[key%n] = key;
        hash_table[key%n] = data;
    }

    string search_modulo_division(int key)
    {
        if (key == hash_key[key%n] )
        {
            return hash_table[key%n];
        }
        else
        {
            return "";
        }
    }

    void add_linear_probing(int key, string data)
    {
        for(int i=0; i < n; i++)
        {
            int j = (key + i) % n;
            if (hash_key[j] == -1 )
            {
                hash_key[j] = key;
                hash_table[j] = data;
                break;
            }
        }
    }

    string search_linear_probing(int key)
    {
        for(int i=0; i < n; i++)
        {
            int j = (key + i) % n;
            if (hash_key[j] == key )
            {
                return hash_table[j];
            }
            if (hash_key[j] == -1 )
            {
                return "";
            }
        }
    }

    void add_quadratic_probing(int key, string data)
    {
        for(int i=0; i < n; i++)
        {
            int j = (key + (i*i)) % n;
            if (hash_key[j] == -1 )
            {
                hash_key[j] = key;
                hash_table[j] = data;
                break;
            }
        }
    }

    string search_quadratic_probing(int key)
    {
        for(int i=0; i < n; i++)
        {
            int j = (key + (i*i)) % n;
            if (hash_key[j] == key)
            {
                return hash_table[j];
            }
            if (hash_key[j] == -1 )
            {
                return "";
            }
        }
    }

    void add_double_hashing(int key, string data)
    {
        int hash2 = r - (key % r);
        for(int i=0; i < n; i++)
        {
            int j = (key + (i*hash2)) % n;
            if (hash_key[j] == -1 )
            {
                hash_key[j] = key;
                hash_table[j] = data;
                break;
            }
        }
    }

    string search_double_hashing(int key)
    {
        int hash2 = r - (key % r);
        for(int i=0; i < n; i++)
        {
            int j = (key + (i*hash2)) % n;
            if (hash_key[j] == key)
            {
                return hash_table[j];
            }
            if (hash_key[j] == -1 )
            {
                return "";
            }
        }
    }

    void print()
    {
        for(int i=0; i < n; i++)
        {
            cout << "<" << hash_key[i] << "," << hash_table[i] << "> ";
        }
        cout << endl;
    }
};

class node
{
    public:
        int key;
        string data;
        node *next;

        node()
        {
            key = -1;
            data = "";
            next = NULL;
        }
        node(string s, int k)
        {
            key = k;
            data = s;
            next = NULL;
        }
};

class separate_chaining
{
    public:
        int n;
        node *hash_table[100];

    separate_chaining(int p_n)
    {
        n = p_n;
        for(int i=0; i < n; i++)
        {
            hash_table[i] = NULL;
        }
    }

    void add(int key, string data)
    {
        int j = key % n;
        if (hash_table[j] == NULL)
        {
            hash_table[j] = new node(data, key);
        }
        else
        {
            node *t_node = hash_table[j];
            while(t_node->next != NULL)
            {
                t_node = t_node->next;
            }
            t_node->next = new node(data, key);
        }
    }

    string search(int key)
    {
        int j = key % n;
        if(hash_table[j] == NULL)
        {
            return "";
        }
        else
        {
            node *t_node = hash_table[j];
            while(t_node->next != NULL)
            {
                if(key == t_node->key)
                {
                    return t_node->data;
                }
                t_node = t_node->next;
            }
            if(key == t_node->key)
            {
                return t_node->data;
            }
            return "";
        }
    }

    void print()
    {
        for(int i=0; i < n; i++)
        {
            cout << "<" << hash_table[i]->data << "," << hash_table[i]->key << "> ";
            if(hash_table[i] != NULL)
            {
                node *t_node = hash_table[i]->next;
                while(t_node->next != NULL)
                {
                    cout << "<" << t_node->data << "," << t_node->key << "> ";
                    t_node = t_node->next;
                }
            }
        }
        cout << endl;
    }
};

int main()
{

}
