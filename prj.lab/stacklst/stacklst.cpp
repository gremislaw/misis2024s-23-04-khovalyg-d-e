#include "stacklst.hpp"

StackLst::StackLst(StackLst &&src) noexcept : head_(src.head_) {
  src.head_ = nullptr;
}

StackLst::StackLst(const StackLst &src) {
  if (!src.IsEmpty()) {
    head_ = new Node;
    head_->data = src.head_->data;
    Node *temp = src.head_->next;
    Node *prev = head_;
    while (temp != nullptr) {
      Node *new_elem = new Node;
      new_elem->data = temp->data;
      prev->next = new_elem;
      prev = new_elem;
      temp = temp->next;
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
    std::swap(head_, src.head_);
  }
  return *this;
}

StackLst &StackLst::operator=(const StackLst &src) {
  if (this != &src) {
    if (!IsEmpty()) {
      Clear();
    }
    head_ = new Node;
    head_->data = src.head_->data;
    Node *temp = src.head_->next;
    Node *prev = head_;
    while (temp != nullptr) {
      Node *new_elem = new Node;
      new_elem->data = temp->data;
      prev->next = new_elem;
      prev = new_elem;
      temp = temp->next;
    }
  }
  return *this;
}

StackLst::~StackLst() { Clear(); }

bool StackLst::IsEmpty() const noexcept { return head_ == nullptr; }

void StackLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node *temp = head_;
    head_ = temp->next;
    delete temp;
  }
}

void StackLst::Push(const Complex &val) {
  if (IsEmpty()) {
    head_ = new Node;
    head_->data = val;
  } else {
    Node *new_head = new Node;
    new_head->data = val;
    new_head->next = head_;
    head_ = new_head;
  }
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