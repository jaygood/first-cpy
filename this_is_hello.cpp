#include <boost/python.hpp>

char const* yo()
{
   return "Yo, Jerk";
}

int const add(int x, int y)
{
   return x + y;
}

BOOST_PYTHON_MODULE(this_is_hello)
{
    using namespace boost::python;
	def("yo", yo);
	def("add", add);
}
