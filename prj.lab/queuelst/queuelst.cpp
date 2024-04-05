#include "queuelst.hpp"

QueueLst::QueueLst(QueueLst &&src) noexcept
    : head_(src.head_), tail_(src.tail_) {
  src.head_ = nullptr;
  src.tail_ = nullptr;
}

QueueLst::QueueLst(const QueueLst &src) {
  for (Node *temp = src.head_; temp != nullptr; temp = temp->next) {
    Push(temp->data);
  }
}

QueueLst::QueueLst(const Complex &val) { Push(val); }

QueueLst &QueueLst::operator=(QueueLst &&src) noexcept {
  if (this != &src) {
    Clear();
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
  }
  return *this;
}

QueueLst &QueueLst::operator=(const QueueLst &src) {
  if (this != &src) {
    Clear();
    for (Node *temp = src.head_; temp != nullptr; temp = temp->next) {
      Push(temp->data);
    }
  }
  return *this;
}

QueueLst::~QueueLst() { Clear(); }

bool QueueLst::IsEmpty() const noexcept { return head_ == nullptr; }

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node *temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

void QueueLst::Push(const Complex &val) {
  if (IsEmpty()) {
    tail_ = new Node;
    tail_->data = val;
    head_ = tail_;
  } else {
    Node *new_tail = new Node;
    new_tail->data = val;
    tail_->next = new_tail;
    tail_ = new_tail;
  }
}

Complex &QueueLst::Top() {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return head_->data;
}

const Complex &QueueLst::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return head_->data;
}

Complex &QueueLst::Tail() {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return tail_->data;
}

const Complex &QueueLst::Tail() const {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return tail_->data;
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}

void QueueLst::Print() const {
  std::cout << std::endl;
  for (Node *temp = head_; temp != nullptr; temp = temp->next) {
    std::cout << temp->data << " >> ";
  }
  std::cout << std::endl;
}