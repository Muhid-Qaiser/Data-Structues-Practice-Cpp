class hash1 {
public:
	int* ptr3;
	int size;
	int key1;
	int index1;
	hash1()
	{
		size = 0;
	}

	hash1(int size)
	{
		this->size = size;
		ptr3 = new int[size] {};
	}
	void inhash( int index,int key)
	{
		ptr3[index] = key;
		key1 = key;
		index1 = index;
	}
	int getkey()
	{
		return key1;
	}
	int getindex()
	{
		return index1;
	}
	int namehash(string name,int key)
	{
		string s;
		s = SplitStr(name);
		long int sum = 0;
		int p = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			sum += int(s[i]) * pow(7, p);
			p++;
		}
		sum = sum % 23;
		//cout << sum << endl;
		//inhash(key, sum);
		key1 = sum;
		index1 = key;
		return sum;
		
	}
	string SplitStr(string str)
	{
		string s = "";
			for (auto x : str)
			{
				if (x == '.')
				{
					return s;
					s = "";
				}
				else 
				{
					s = s + x;
				}
			}
		//cout << s << endl;
	}

	int hash4(int** ptr,int row,int col,string name)
	{
	//	cout << name << endl;
		int count = 0;
		int* hblack = new int[row] {};
		int* vblack = new int [col] {};
		for (int i = 0; i < row; i++)
		{
			count = 0;
			for (int j = 0; j < col; j++)
			{
				if (ptr[i][j] == 0)
				{
					count++;
				}
			}
			hblack[i] = count;
		}
		for (int i = 0; i < col; i++)
		{
			count = 0;
			for (int j = 0; j < row; j++)
			{
				if (ptr[j][i] == 0)
				{
					count++;
				}
			}
			vblack[i] = count;
		}
		//	cout << hblack << " " << vblack;
		string k = "";
		for (int i = 0; i < row; i++)
		{
			k += to_string(hblack[i]);
		}
		for (int i = 0; i < col; i++)
		{
			k += to_string(vblack[i]);
		}

		//cout << k.size();
		string k1 = "";
		int c1 = 0;
		long int sum = 0;
		for (int i = 0; k[i] != '\0'; i++)
		{
			c1++;
			k1 += k[i];
			if (c1 == 4)
			{
				sum = sum + stoi(k1);
				c1 = 0;
			//	cout << k1 << endl;
				k1 = "";
			}

		}
		if (c1 > 0 && c1 < 4)
		{
			if (c1 == 1)
			{
				k1 += "000";
			}
			else if (c1 == 2)
			{
				k1 += "00";
			}
			else if (c1 == 3)
			{
				k1 += '0';
			}
		//	cout << k1 << endl;
			sum = sum + stoi(k1);
			k1 = "";
		}

		sum = sum % 23;
		return sum;
		
	}

};
const int SIZE = 23;
struct HashNode
{
public:
	    int key;
	int value;
	HashNode* next;
	HashNode(int key, int value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

//Hash class 2
class HashMap
{
public:
	HashNode** hashtable1;
public:
	HashMap()
	{
		hashtable1 = new HashNode * [SIZE];
		for (int i = 0; i < SIZE; i++)
			hashtable1[i] = 0;
	}


	//Finding function of hash 
	int find(int key, int val)
	{
		bool f = false;
		int key3 = key;
		HashNode* temp = hashtable1[key3];
		while (temp != NULL)
		{
			if (temp->key == key)
			{
				if (temp->value == val)
				{
					cout << val;
					return 1;
				}
				f = true;
			}
			temp = temp->next;
		}
		if (!f)
			return -1;
	}
	//Function with chaining for hashing 
	void insert(int key, int value)
	{
		int key3 = key;
		HashNode* prev = NULL;
		HashNode* temp = hashtable1[key3];
		while (temp != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
		{
			temp = new HashNode(key, value);
			if (prev == NULL)
			{
			
				hashtable1[key3] = temp;
			}
			else
			{
				
				prev->next = temp;
			}
		}
		else
		{
			temp->value = value;
		}
	}
	
};

class Hash
{
	int BUCKET;    // No. of buckets

	// Pointer to an array containing buckets
	list<int>* table;
public:
	Hash(int V);  // Constructor

	// inserts a key into hash table
	void insertItem(int key, int value);


	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key,int value)
{
	int index = key;
	table[index].push_back(value);
}



// function to display hash table
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}