#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuelst/queuelst.hpp"

TEST_CASE("queuelst constructor") {
  QueueLst queue;
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelst move constructor") {
  Complex c(1, 2);
  QueueLst queue1(c);
  QueueLst queue2(std::move(queue1));
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
  CHECK_EQ(queue2.Tail(), c);
  CHECK(queue1.IsEmpty());
}

TEST_CASE("queuelst push") {
  QueueLst queue;
  Complex c(1, 2);
  queue.Push(c);
  CHECK_FALSE(queue.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue.Tail(), c);
}

TEST_CASE("queuelst pop") {
  QueueLst queue;
  Complex c(1, 2);
  queue.Push(c);
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelst copy constructor") {
  QueueLst queue;
  Complex c(1, 2);
  queue.Push(c);
  QueueLst queue2(queue);
  CHECK_FALSE(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue2.Top(), c);
  queue.Pop();
  CHECK(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
}

TEST_CASE("queuelst assignment operator") {
  QueueLst queue;
  Complex c(1, 2);
  queue.Push(c);
  QueueLst queue2;
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

TEST_CASE("queuelst clear") {
  QueueLst queue;
  Complex c(1, 2);
  queue.Push(c);
  queue.Clear();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelst push and pop") {
  QueueLst queue;
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

TEST_CASE("queuelst resizing") {
  QueueLst queue;
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

TEST_CASE("queuelst resizing and copy") {
  QueueLst queue;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    value = Complex(i, i);
    queue.Push(value);
  }
  QueueLst queue2(queue);
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

TEST_CASE("queuelst resizing and assignment") {
  QueueLst queue;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e3; ++i) {
    value = Complex(i, i);
    queue.Push(value);
  }
  QueueLst queue2;
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