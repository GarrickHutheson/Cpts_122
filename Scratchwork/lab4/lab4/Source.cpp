typedef class Node {
public:
	Node(double data) {
		this->data = data;
	}

private:
	double data;
	Node * pNext;
};

typedef class Queue
{
	public:
		bool isEmpty() {
			return !this->pHead;
		}
		bool enqueue(double data) {
			if (pTail) {
				Node * pTemp = new Node(data);
				pTail->pNext = pTemp;
				pTail = pTemp;
			}
			else {
				pTail = new Node(data);
			}

			return true;
		}
	private:
		Node * pHead;
		Node * pTail;
};