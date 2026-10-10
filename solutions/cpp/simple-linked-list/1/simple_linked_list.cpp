#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    Element* elem = new Element{entry};
    elem->next = head;
    head = elem;
    ++current_size;   
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if (!head) {
        throw std::out_of_range("pop empty list");
    }
    Element* old_head = head;
    int const value = old_head->data;
    head = old_head->next;
    delete old_head;
    --current_size;
    return value;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    Element* prev = nullptr;
    Element* cur = head;
    while (cur) {
        Element* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;   
    }
    head = prev;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    while (head) {
        Element* cur = head;
        head = cur->next;
        delete cur;
    }
}

}  // namespace simple_linked_list
