template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    //don't do anything if you're copying yourself
    if (this == &copyObj) {
        return;
    }

    //clear the current list
    clear();

    //check if the source list is empty, otherwise skip
    if (copyObj.head == nullptr) {
        head = nullptr;
        this->length = 0;
        return;
    }

    //copy the first node
    head = new Node;
    head->value = copyObj.head->value;
    head->next = nullptr;

    Node* currThis = head;
    Node* currOther = copyObj.head->next;

    //copy next nodes afterwards, will continue until it reaches nullptr
    while (currOther != nullptr) {
        currThis->next = new Node;
        currThis = currThis->next;

        currThis->value = currOther->value;
        currThis->next = nullptr;

        currOther = currOther->next;
    }

    this->length = copyObj.length;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("insert: error, position out of bounds");
    }

    Node* newNode = new Node;
    newNode->value = elem;
    newNode->next = nullptr;

    // inserting at head
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } 
    // inserting anywhere else
    else {
        Node* curr = head;

        // go to node before insert position
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    this->length++;


}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }

    Node* temp;

    //remove head if position 0
    if (position == 0) {
        temp = head;
        head = head->next;
        delete temp;
    }

    //remove node if anything other than position 0
    else {
        Node* curr = head;

        //go to position before removal
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }

        temp = curr->next;          //deletes node
        curr->next = temp->next;    
        delete temp;                //cleanup
    }

    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
