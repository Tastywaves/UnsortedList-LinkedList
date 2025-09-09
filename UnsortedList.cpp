

template<class T>
UnsortedList<T>::UnsortedList() {
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try
    {
        Node *testNode = new Node; // try to make a node
        delete testNode; // if the previous line ran ok, then remove the node
    }
    catch (std::bad_alloc &e)
    {
        return true;
    }
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return 0;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node *currN = head;
    while (currN != nullptr)
    {
        if (currN->item == someItem)
        {
            return true;
        }
    }
    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {
    Node* newNode = new Node;
    newNode->value = item;
    newNode->next = head;
    head = newNode;
    ++length;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node *currN = head;
    Node *prevN = nullptr;
    while (currN != nullptr)
    {
        if (currN->item == item)
        {
            if (prevN == nullptr){
                prevN->next = currN->next;
            } else
            {
                head = currN->next;
            }
                delete currN;
                --length;
                return;
        }
        prevN = currN;
        currN = currN->next;
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T currVal = currPos->value; //remember the curr value
    currPos = currPos->next; // move currPos to next
    return currVal;
    return T();
}
