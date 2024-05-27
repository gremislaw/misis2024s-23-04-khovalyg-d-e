#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <algorithm>
#include <cstddef>
#include <stdexcept>

#include "../complex/complex.hpp"

class StackLst {
 public:
  StackLst() = default;
  StackLst(StackLst &&) noexcept;
  StackLst(const StackLst &);
  StackLst(const Complex &);
  ~StackLst();

  StackLst &operator=(const StackLst &);
  StackLst &operator=(StackLst &&) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;
  void Push(const Complex &val);

  Complex &Top();
  const Complex &Top() const;

  void Clear() noexcept;

 private:
  struct Node {
    Complex data;
    Node *next = nullptr;
  };
  Node *head_ = nullptr;
};

#endif