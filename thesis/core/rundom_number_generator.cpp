#include "rundom_number_generator.hpp"

#include <cstdlib>
#include <time.h>

typedef rundom_number_generator RND;

RND* RND::get_instance()
{
	static RND* instance = new RND();
	return instance;
}

RND::rundom_number_generator()
{
	srand(time(NULL));
}

int RND::get_number(int begin, int end)
{
	return rand() % (end - begin) + begin;
}
