#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuearr/queuearr.hpp"

TEST_CASE("queuearr constructor") {
  QueueArr queue;
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuearr move constructor") {
  Complex c(1, 2);
  QueueArr queue1(c);
  QueueArr queue2(std::move(queue1));
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
  CHECK_EQ(queue2.Tail(), c);
  CHECK(queue1.IsEmpty());
}

TEST_CASE("queuearr push") {
  QueueArr queue;
  Complex c(1, 2);
  queue.Push(c);
  CHECK_FALSE(queue.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue.Tail(), c);
}

TEST_CASE("queuearr pop") {
  QueueArr queue;
  Complex c(1, 2);
  queue.Push(c);
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuearr copy constructor") {
  QueueArr queue;
  Complex c(1, 2);
  queue.Push(c);
  QueueArr queue2(queue);
  CHECK_FALSE(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue2.Top(), c);
  queue.Pop();
  CHECK(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
}

TEST_CASE("queuearr assignment operator") {
  QueueArr queue;
  Complex c(1, 2);
  queue.Push(c);
  QueueArr queue2;
  queue2 = queue;
  CHECK_FALSE(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue2.Top(), c);
  queue.Pop();
  CHECK(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
}

TEST_CASE("queuearr clear") {
  QueueArr queue;
  Complex c(1, 2);
  queue.Push(c);
  queue.Clear();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuearr push and pop") {
  QueueArr queue;
  Complex c1(1, 2);
  Complex c2(3, 4);
  queue.Push(c1);
  queue.Push(c2);
  CHECK_EQ(queue.Top(), c1);
  CHECK_EQ(queue.Tail(), c2);
  queue.Pop();
  CHECK_EQ(queue.Top(), c2);
  CHECK_EQ(queue.Tail(), c2);
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuearr resizing") {
  QueueArr queue;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    value = Complex(i, i);
    queue.Push(value);
  }
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    CHECK_EQ(queue.Top(), Complex(i, i));
    CHECK_EQ(queue.Tail(), Complex(1e3 - 1, 1e3 - 1));
    queue.Pop();
  }
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuearr resizing and copy") {
  QueueArr queue;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    value = Complex(i, i);
    queue.Push(value);
  }
  QueueArr queue2(queue);
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    CHECK_EQ(queue.Top(), Complex(i, i));
    CHECK_EQ(queue2.Top(), Complex(i, i));
    CHECK_EQ(queue.Tail(), Complex(1e3 - 1, 1e3 - 1));
    CHECK_EQ(queue2.Tail(), Complex(1e3 - 1, 1e3 - 1));
    queue.Pop();
    queue2.Pop();
  }
  CHECK(queue.IsEmpty());
  CHECK(queue2.IsEmpty());
}

TEST_CASE("queuearr resizing and assignment") {
  QueueArr queue;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    value = Complex(i, i);
    queue.Push(value);
  }
  QueueArr queue2;
  queue2 = queue;
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    CHECK_EQ(queue.Top(), Complex(i, i));
    CHECK_EQ(queue2.Top(), Complex(i, i));
    CHECK_EQ(queue.Tail(), Complex(1e3 - 1, 1e3 - 1));
    CHECK_EQ(queue2.Tail(), Complex(1e3 - 1, 1e3 - 1));
    queue.Pop();
    queue2.Pop();
  }
  CHECK(queue.IsEmpty());
  CHECK(queue2.IsEmpty());
}