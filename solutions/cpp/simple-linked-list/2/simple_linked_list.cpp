#include "simple_linked_list.h"

#include <stdexcept>
#include <utility>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    auto node = std::make_unique<Element>(entry);
    node->next = std::move(head);
    head = std::move(node);
    ++current_size;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if (!head) {
        throw std::out_of_range("pop empty list");
    }
    auto node = std::move(head);
    head = std::move(node->next);
    --current_size;
    
    return node->data;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    std::unique_ptr<Element> prev;
    while (head) {
        auto next = std::move(head->next);
        head->next = std::move(prev);
        prev = std::move(head);
        head = std::move(next);
    }
    head = std::move(prev);
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    while (head) {
        head = std::move(head->next);
    }
}

}  // namespace simple_linked_list
