int RemoveLast() {
    if (head == nullptr) {   // empty list
        cout << "List is empty\n";
        return -1;
    }

    if (head->next == nullptr) { // only one node
        int val = head->val;
        delete head;
        head = nullptr;
        return val;
    }

    Node* curr = head;
    while (curr->next->next != nullptr) { // stop at 2nd last node
        curr = curr->next;
    }

    int val = curr->next->val;
    delete curr->next;       // free memory
    curr->next = nullptr;    // unlink last node
    return val;
}
