#include <bits/stdc++.h> 
#include <cmath>

using namespace std;
int iterations = 0;

struct MinHeapNode
{
	char data;
	unsigned freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	while (minHeap.size() != 1) {
		iterations++;

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}
	printCodes(minHeap.top(), "");
}

int main()
{

	char arr[10];
	int freq[10], size;

	cout<<"Enter size of array: ";
	cin>>size;

	for(int i=0; i<size; i++)
    {
        cout<<"Enter element "<<i<<": ";
        cin>>arr[i];
        cout<<"Enter frequency of element "<<i<<": ";
        cin>>freq[i];
		cout<<endl;
    }

	HuffmanCodes(arr, freq, size);
    cout << "Expected number of iterations: " << size*log2(size) << endl;
    cout << "Actual number of iterations: " << iterations << endl;
	return 0;
}
