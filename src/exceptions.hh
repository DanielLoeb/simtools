// netdyn - a chemical reaction network dynamics package
// 
// Copyright © 2009,2010 Daniel Löb <daniel@zombiepiratesfromspace.eu>
// 
// netdyn is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// netdyn is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with netdyn.  If not, see <http://www.gnu.org/licenses/>.

#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

#include<exception>
#include<sstream>

using std::exception;
using std::string;

namespace simtools
{
	string tostr(size_t size);
	string tostr(double val);
	string tostr(unsigned int val);

	struct RuntimeError: std::exception
	{
		public:
			RuntimeError(string text);
			
			RuntimeError(RuntimeError& oldone);
			RuntimeError(const RuntimeError& oldone);
			
			const char* what() const throw();
			
			virtual ~RuntimeError() throw();
			
			string get_message();
			
		private:
			string message;
	};

#ifdef USES_PYTHON
	void translate_RE(RuntimeError const &re);
#endif // USES_PYTHON
} // End of namespace simtools.

#endif // EXCEPTIONS_HH
