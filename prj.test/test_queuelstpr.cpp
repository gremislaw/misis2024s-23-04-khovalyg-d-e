#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuelstpr/queuelstpr.hpp"

TEST_CASE("queuelstPr constructor") {
  QueueLstPr queue;
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelstPr move constructor") {
  float c = 1.2;
  QueueLstPr queue1(c);
  QueueLstPr queue2(std::move(queue1));
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
  CHECK_EQ(queue2.Tail(), c);
  CHECK(queue1.IsEmpty());
}

TEST_CASE("queuelstPr push") {
  QueueLstPr queue;
  float c = 1.2;
  queue.Push(c);
  CHECK_FALSE(queue.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue.Tail(), c);
}

TEST_CASE("queuelstPr pop") {
  QueueLstPr queue;
  float c = 1.2;
  queue.Push(c);
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelstPr copy constructor") {
  QueueLstPr queue;
  float c = 1.2;
  queue.Push(c);
  QueueLstPr queue2(queue);
  CHECK_FALSE(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue.Top(), c);
  CHECK_EQ(queue2.Top(), c);
  queue.Pop();
  CHECK(queue.IsEmpty());
  CHECK_FALSE(queue2.IsEmpty());
  CHECK_EQ(queue2.Top(), c);
}

TEST_CASE("queuelstPr assignment operator") {
  QueueLstPr queue;
  float c = 1.2;
  queue.Push(c);
  QueueLstPr queue2;
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

TEST_CASE("queuelstPr clear") {
  QueueLstPr queue;
  float c = 1.2;
  queue.Push(c);
  queue.Clear();
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelst resizing") {
  QueueLstPr queue;
  float value;
  for (float i = 0; i < 1e2; ++i) {
    queue.Push(i);
  }
  for (float i = 0; i < 1e2; ++i) {
    CHECK_EQ(queue.Top(), i);
    CHECK_EQ(queue.Tail(), 0);
    queue.Pop();
  }
  CHECK(queue.IsEmpty());
}

TEST_CASE("queuelst resizing and copy") {
  QueueLstPr queue;
  float value;
  for (float i = 0; i < 1e3; ++i) {
    queue.Push(i);
  }
  QueueLstPr queue2(queue);
  for (float i = 0; i < 1e3; ++i) {
    CHECK_EQ(queue.Top(), i);
    CHECK_EQ(queue2.Top(), i);
    CHECK_EQ(queue.Tail(), 0);
    CHECK_EQ(queue2.Tail(), 0);
    queue.Pop();
    queue2.Pop();
  }
  CHECK(queue.IsEmpty());
  CHECK(queue2.IsEmpty());
}

TEST_CASE("queuelst resizing and assignment") {
  QueueLstPr queue;
  float value;
  for (float i = 0; i < 1e3; ++i) {
    queue.Push(i);
  }
  QueueLstPr queue2;
  queue2 = queue;
  for (float i = 0; i < 1e3; ++i) {
    CHECK_EQ(queue.Top(), i);
    CHECK_EQ(queue2.Top(), i);
    CHECK_EQ(queue.Tail(), 0);
    CHECK_EQ(queue2.Tail(), 0);
    queue2.Pop();
    queue.Pop();
  }
  CHECK(queue.IsEmpty());
  CHECK(queue2.IsEmpty());
}