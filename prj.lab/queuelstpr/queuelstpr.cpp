#include "queuelstpr.hpp"

QueueLstPr::QueueLstPr(QueueLstPr &&src) noexcept
    : head_(src.head_), tail_(src.tail_) {
  src.head_ = nullptr;
  src.tail_ = nullptr;
}

QueueLstPr::QueueLstPr(const QueueLstPr &src) {
  for (Node *temp = src.head_; temp; temp = temp->next) {
    Push(temp->data);
  }
}

QueueLstPr::QueueLstPr(const float &val) { Push(val); }

QueueLstPr &QueueLstPr::operator=(QueueLstPr &&src) noexcept {
  if (this != &src) {
    Clear();
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
  }
  return *this;
}

QueueLstPr &QueueLstPr::operator=(const QueueLstPr &src) {
  if (this != &src) {
    Clear();
    for (Node *temp = src.head_; temp; temp = temp->next) {
      Push(temp->data);
    }
  }
  return *this;
}

QueueLstPr::~QueueLstPr() {
  while (!IsEmpty()) {
    Pop();
  }
}

bool QueueLstPr::IsEmpty() const noexcept { return head_ == nullptr; }

void QueueLstPr::Pop() noexcept {
  if (!IsEmpty()) {
    Node *temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

void QueueLstPr::Push(const float &val) {
  if (IsEmpty()) {
    tail_ = new Node;
    tail_->data = val;
    head_ = tail_;
  } else {
    Node *new_elem = new Node;
    new_elem->data = val;
    Node *temp = head_;
    Node *prev = new Node;
    for (; temp && temp->data < new_elem->data; temp = temp->next) prev = temp;
    if (prev) {
      new_elem->next = temp;
      prev->next = new_elem;
    } else {
      new_elem->next = head_;
      head_ = new_elem;
    }
  }
}

float &QueueLstPr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return head_->data;
}

const float &QueueLstPr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return head_->data;
}

float &QueueLstPr::Tail() {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return tail_->data;
}

const float &QueueLstPr::Tail() const {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty Queue");
  }
  return tail_->data;
}

void QueueLstPr::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}

void QueueLstPr::Print() const {
  std::cout << std::endl;
  for (Node *temp = head_; temp != nullptr; temp = temp->next) {
    std::cout << temp->data << " >> ";
  }
  std::cout << std::endl;
}