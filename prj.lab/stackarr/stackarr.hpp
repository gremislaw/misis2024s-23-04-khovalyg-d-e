#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include "../complex/complex.hpp"

#include <cstddef>
#include <algorithm>
#include <stdexcept>

class StackArr {
public:
  StackArr() = default;
  StackArr(StackArr&&);
  StackArr(const StackArr&);
  StackArr(const Complex&);
  ~StackArr();
  
  StackArr& operator=(const StackArr&);
  StackArr& operator=(StackArr&&);

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;
  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();
  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  
  ptrdiff_t size_ = 0;
  ptrdiff_t top_ind_ = -1;
  Complex* data_ = nullptr;
};

#endif