#include "stacklst.hpp"

StackLst::StackLst(StackLst &&src) noexcept : head_{src.head_} {
  src.head_ = nullptr;
}

StackLst::StackLst(const StackLst &src) {
  head_ = nullptr;
  if (!src.IsEmpty()) {
    head_ = new Node;
    head_->data = src.head_->data;
    Node *temp = src.head_->next;
    Node *prev = head_;
    for (; temp->next != nullptr; temp = temp->next) {
      Node *elem = new Node;
      elem->data = temp->data;
      prev->next = elem;
      prev = elem;
    }
  }
}

StackLst::StackLst(const Complex &val) {
  head_ = new Node;
  head_->data = val;
}

StackLst &StackLst::operator=(StackLst &&src) noexcept {
  if (this != &src) {
    Clear();
    head_ = src.head_;
    src.head_ = nullptr;
  }
  return *this;
}

StackLst &StackLst::operator=(const StackLst &src) {
  if (this != &src) {
    Clear();
    if (!IsEmpty()) {
      head_ = new Node;
      head_->data = src.head_->data;
      Node *temp = src.head_->next;
      Node *prev = head_;
      for (; temp->next != nullptr; temp = temp->next) {
        Node *elem = new Node;
        elem->data = temp->data;
        prev->next = elem;
        prev = elem;
      }
    }
  }
  return *this;
}

StackLst::~StackLst() {
  while (!IsEmpty()) {
    Pop();
  }
}

bool StackLst::IsEmpty() const noexcept { return head_ == nullptr; }

void StackLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node *temp = head_;
    head_ = temp->next;
    delete temp;
  }
}

void StackLst::Push(const Complex &val) {
  Node *new_head = new Node;
  new_head->data = val;
  new_head->next = head_;
  head_ = new_head;
}

Complex &StackLst::Top() {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty stack");
  }
  return head_->data;
}

const Complex &StackLst::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty stack");
  }
  return head_->data;
}

void StackLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}