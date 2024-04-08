#pragma once
#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>

class QueueLstPr {
 public:
  QueueLstPr() = default;
  QueueLstPr(QueueLstPr &&) noexcept;
  QueueLstPr(const QueueLstPr &);
  QueueLstPr(const float &);
  ~QueueLstPr();

  QueueLstPr &operator=(const QueueLstPr &);
  QueueLstPr &operator=(QueueLstPr &&) noexcept;

  void Pop() noexcept;
  void Push(const float &);
  void Clear() noexcept;
  void Print() const;

  [[nodiscard]] bool IsEmpty() const noexcept;
  [[nodiscard]] float &Top();
  [[nodiscard]] float &Tail();
  [[nodiscard]] const float &Tail() const;
  [[nodiscard]] const float &Top() const;

 private:
  struct Node {
    Node *next = nullptr;
    float data;
  };
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
};

#endif