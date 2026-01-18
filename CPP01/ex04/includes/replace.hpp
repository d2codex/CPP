#ifndef REPLACE_HPP
#define REPLACE_HPP

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

bool	validateArgs(const std::string& filename,
					 const std::string& s1,
					 const std::string& s2);

#endif
