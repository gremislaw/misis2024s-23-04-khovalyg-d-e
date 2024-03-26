#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stacklst/stacklst.hpp"

TEST_CASE("stackLst constructor") {
  StackLst stack;
  CHECK(stack.IsEmpty());
}

TEST_CASE("stackLst move constructor") {
  Complex c(1, 2);
  StackLst stack1(c);
  StackLst stack2(std::move(stack1));
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
  CHECK(stack1.IsEmpty());
}

TEST_CASE("stackLst push") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE("stackLst pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("stackLst copy constructor") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  StackLst stack2(stack);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack.Top(), c);
  CHECK_EQ(stack2.Top(), c);
  stack.Pop();
  CHECK(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
}

TEST_CASE("stackLst assignment operator") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  StackLst stack2;
  stack2 = stack;
  CHECK_FALSE(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack.Top(), c);
  CHECK_EQ(stack2.Top(), c);
  stack.Pop();
  CHECK(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
}

TEST_CASE("stackLst clear") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Clear();
  CHECK(stack.IsEmpty());
}

TEST_CASE("stackLst push and pop") {
  StackLst stack;
  Complex c1(1, 2);
  Complex c2(3, 4);
  stack.Push(c1);
  stack.Push(c2);
  CHECK_EQ(stack.Top(), c2);
  stack.Pop();
  CHECK_EQ(stack.Top(), c1);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("stackLst resizing") {
  StackLst stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e6; ++i) {
    value = Complex(i, i);
    stack.Push(value);
  }
  for (ptrdiff_t i = 1e6 - 1; i >= 0; --i) {
    CHECK_EQ(stack.Top(), Complex(i, i));
    stack.Pop();
  }
  CHECK(stack.IsEmpty());
}

TEST_CASE("stackLst resizing and copy") {
  StackLst stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e6; ++i) {
    value = Complex(i, i);
    stack.Push(value);
  }
  StackLst stack2(stack);
  for (ptrdiff_t i = 1e6 - 1; i >= 0; --i) {
    CHECK_EQ(stack.Top(), Complex(i, i));
    CHECK_EQ(stack2.Top(), Complex(i, i));
    stack.Pop();
    stack2.Pop();
  }
  CHECK(stack.IsEmpty());
  CHECK(stack2.IsEmpty());
}

TEST_CASE("stackLst resizing and assignment") {
  StackLst stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1e6; ++i) {
    value = Complex(i, i);
    stack.Push(value);
  }
  StackLst stack2;
  stack2 = stack;
  for (ptrdiff_t i = 1e6 - 1; i >= 0; --i) {
    CHECK_EQ(stack.Top(), Complex(i, i));
    CHECK_EQ(stack2.Top(), Complex(i, i));
    stack.Pop();
    stack2.Pop();
  }
  CHECK(stack.IsEmpty());
  CHECK(stack2.IsEmpty());
}