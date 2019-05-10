#include <cppcoro/single_event_consumer>
#include <cppcoro/task>
#include <cppcoro/sync_wait>
#include <chrono/literals>

using namespace std::chrono::literals;

void test(){
  single_consumer_event event;
  cppcoro::sync_wait(cppcoro::when_all_ready(
    [&]() -> cppcoro::task<> {
      while(true){
        co_await event;
        event.reset();
        std::this_thread_sleep(500ms)
      }
    }(),
    [&]() -> cppcoro::task<>{
      while(true){
        event.set();
      }
    }()
  ));
}

