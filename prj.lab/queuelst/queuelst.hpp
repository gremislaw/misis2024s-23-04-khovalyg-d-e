#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <algorithm>
#include <cstddef>
#include <ostream>
#include <stdexcept>

#include "../complex/complex.hpp"

class QueueLst {
 public:
  QueueLst() = default;
  QueueLst(QueueLst &&) noexcept;
  QueueLst(const QueueLst &);
  QueueLst(const Complex &);
  ~QueueLst();

  QueueLst &operator=(const QueueLst &);
  QueueLst &operator=(QueueLst &&) noexcept;

  void Pop() noexcept;
  void Push(const Complex &);
  void Clear() noexcept;
  void Print() const;

  [[nodiscard]] bool IsEmpty() const noexcept;
  [[nodiscard]] Complex &Top();
  [[nodiscard]] Complex &Tail();
  [[nodiscard]] const Complex &Tail() const;
  [[nodiscard]] const Complex &Top() const;

 private:
  struct Node {
    Node *next = nullptr;
    Complex data;
  };
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
};

#endif