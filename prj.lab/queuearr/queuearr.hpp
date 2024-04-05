#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <algorithm>
#include <cstddef>
#include <ostream>
#include <stdexcept>

#include "../complex/complex.hpp"

class QueueArr {
 public:
  QueueArr() = default;
  QueueArr(QueueArr &&) noexcept;
  QueueArr(const QueueArr &);
  QueueArr(const Complex &);
  ~QueueArr();

  QueueArr &operator=(const QueueArr &);
  QueueArr &operator=(QueueArr &&) noexcept;

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
  ptrdiff_t size_ = 0;
  ptrdiff_t front_ind_ = -1;
  Complex *data_ = nullptr;
};

#endif