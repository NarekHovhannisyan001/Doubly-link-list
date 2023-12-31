#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T>
class MyList {
public:
    MyList() : m_head(nullptr), m_tail(nullptr), m_sizeList(0) {}
    MyList(const MyList& list) : m_head(nullptr), m_tail(nullptr), m_sizeList(0) { 
        operator=(list);
    }

    MyList(std::initializer_list<T> list) {
        for (int i = 0;i < list.size();++i) {
            push_back(*(list.begin() + i));
        }
        
    }
    void push_back(const T& value) {
        Node* tmp = new Node(value);
        if (m_head == nullptr) {
            m_head = m_tail = tmp;
        } else {
            tmp->prev = m_tail;
            m_tail->next = tmp;
            m_tail = tmp;
        }
        m_sizeList++;
    }

    void push_front(const T& value) {
        Node* tmp = new Node(value);
        if (m_head != nullptr) {
            m_head->prev = tmp;
            tmp->next = m_head;
        }
        m_head = tmp;
        if (m_tail == nullptr) {
            m_tail = tmp;
        }
        m_sizeList++;
    }

    void pop_back() {
        if (m_tail == nullptr) {
            return;
        }
        if (m_tail->prev != nullptr) {
            m_tail = m_tail->prev;
            delete m_tail->next;
            m_tail->next = nullptr;
            m_sizeList--;
        } else {
            delete m_tail;
            m_head = m_tail = nullptr;
            m_sizeList = 0;
        }
    }

    void pop_front() {
        if (m_head == nullptr) {
            return;
        }
        if (m_head->next != nullptr) {
            m_head = m_head->next;
            delete m_head->prev;
            m_head->prev = nullptr;
            m_sizeList--;
        } else {
            delete m_head;
            m_head = m_tail = nullptr;
            m_sizeList = 0;
        }
    }

    void printList() {
        Node* start = m_head;
        while (start != nullptr) {
            std::cout << start->data << " ";
            start = start->next;
        }
    }

    void printReverse() {
        Node* start = m_tail;
        while (start != nullptr) {
            std::cout << start->data << " ";
            start = start->prev;
        }
    }

    void remove(int index) {
        if (index < 0 || index >= m_sizeList) {
            std::cerr << "Invalid index";
            return;
        }

        if (index == 0) {
            pop_front();
            return;
        } else if (index == m_sizeList - 1) {
            pop_back();
            return;
        }

        int i = 0;
        Node* tmp = m_head;
        while (i < index) {
            tmp = tmp->next;
            i++;
        }

        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        m_sizeList--;
    }

    void insert(size_t index, const T& value) {
        if (index > m_sizeList) {
            std::cerr << "Invalid index";
            return;
        }
        if (index == 0) {
            push_front(value);
            return;
        } else if (index == m_sizeList) {
            push_back(value);
            return;
        }

        int i = 0;
        Node* tmp = m_head;
        while (i < index) {
            tmp = tmp->next;
            i++;
        }

        Node* forInsert = new Node(value);
        forInsert->next = tmp;
        forInsert->prev = tmp->prev;
        tmp->prev->next = forInsert;
        tmp->prev = forInsert;
        m_sizeList++;
    }

    T& get(int index) const {
        if (index < 0 || index >= m_sizeList) {
            std::cerr << ("Index out of range");
        }

        int i = 0;
        Node* current = m_head;
        while (i < index) {
            current = current->next;
            i++;
        }

        return current->data;
    }

    bool empty() const {
        if (!m_head) {
            return true;
        }
        return false;
    }

    size_t size() const {
        return m_sizeList;
    }

    void clear() {
        while (m_head) {
            Node* temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
    }
    ~MyList() {
        Node* current = m_head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    T& operator[](size_t index) {
        return get(index);
    }
    MyList& operator=(const MyList& list) {
        if (this == &list) {
            return *this;
        }

        clear();
        Node* currentList = list.m_head;
        while (currentList)
        {
            push_back(currentList->data);
            currentList = currentList->next;
        }
        
        return *this;
    }


private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
private:
    Node* m_head;
    Node* m_tail;
    std::size_t m_sizeList;
};

#endif // LIST_H
