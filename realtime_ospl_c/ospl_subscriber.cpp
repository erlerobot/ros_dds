#include <rttest/rttest.h>
#include "ExampleSubscriber.hpp"

#define STACK_SIZE 1024*1024*1024

ExampleSubscriber sub;

void* sub_callback(void * unused)
{
	sub.callback();
}

int main(int argc, char *argv[])
{
	sub.init();

	rttest_read_args(argc, argv);

	if (rttest_set_sched_priority(90, SCHED_RR) != 0)
  {
    perror("Failed to set scheduling priority and policy of thread");
  }

	if (rttest_lock_memory() != 0)
  {
    perror("Failed to lock memory");
  }

	rttest_prefault_stack();

	rttest_spin(sub_callback, NULL);

	rttest_write_results();
	rttest_finish();

	sub.teardown();
}
