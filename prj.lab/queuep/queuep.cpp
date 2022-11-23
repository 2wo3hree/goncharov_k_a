#include "queuep.h"
#include <algorithm>

QueueP::Node::Node(int data, std::unique_ptr<Node> next) {
    this->data = data;
    this->next = std::move(next);
}

QueueP::QueueP() {
    this->head = nullptr;
}

void QueueP::push(const int& data) {
    if (!isEmpty()) {
        if (data < head->data) {
            head = std::make_unique<Node>(data, std::move(head));
            return;
        }

        Node* counter = head.get();

        while ((counter->next != nullptr) && (counter->next->data < data)) {
            counter = counter->next.get();
        }

        std::unique_ptr<Node> item = std::make_unique<Node>(data, std::move(counter->next));
        counter->next = std::move(item);


    }
    else
        head = std::make_unique<Node>(data, nullptr);
}

void QueueP::pop() {
    if (!isEmpty()) {
        head = std::move(head->next);
    }
}

const int& QueueP::top() const {
    if (!isEmpty())
        return head->data;
}

bool QueueP::isEmpty() const {

    return head == nullptr;
  
}

QueueP::~QueueP() {
    while (!isEmpty())
        pop();
}
