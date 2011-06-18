
#include "exceptions.hh"

simtools::RuntimeError::RuntimeError(string text)
	: message(text)
{}

simtools::RuntimeError::RuntimeError(RuntimeError& oldone)
	: message(oldone.message) 
{}

simtools::RuntimeError::RuntimeError(const RuntimeError& oldone): message(oldone.message) {}
	
const char* RuntimeError::what() const throw()
{
	return message.c_str();
}
	
simtools::RuntimeError::~RuntimeError() throw()
{
}

simtools::string tostr(size_t size)
{
	std::stringstream ss;
	ss << size;
	return ss.str();
}

simtools::string tostr(double val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

simtools::string tostr(unsigned int val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

#ifdef USES_PYTHON
void simtools::translate_RE(RuntimeError const &re)
{
	//boost::python::object pythonExceptionInstance(re);
	//PyErr_SetObject(ndRuntimeError)
	PyErr_SetString(PyExc_RuntimeError, re.what());
}
#endif // USES_PYTHON
