#pragma once
#ifndef QUEUEP
#define QUEUEP

#include <iosfwd>
#include <string>
#include <stdexcept>
#include <vector>
#include <memory>

class QueueP {
private:
    class Node {
    private:
        int data = 0;
        std::unique_ptr<Node> next = nullptr;

    public:
        Node(int data, std::unique_ptr<Node> next);
        ~Node() = default;
        friend class QueueP;
    };

    std::unique_ptr<Node> head = nullptr;

public:
    QueueP();
    QueueP(QueueP&) = delete;
    QueueP(QueueP&&) = default;

    void push(const int& data);
    void pop();

    bool isEmpty() const;
    const int& top() const;

    QueueP& operator=(QueueP&& other) = default;
    QueueP& operator=(const QueueP&) = delete;
    ~QueueP();
};

#endif

