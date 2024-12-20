/* Icinga 2 | (c) 2012 Icinga GmbH | GPLv2+ */

#ifndef DEPENDENCYGRAPH_H
#define DEPENDENCYGRAPH_H

#include "base/i2-base.hpp"
#include "base/object.hpp"
#include <map>
#include <mutex>

namespace icinga {

/**
 * A graph that tracks dependencies between objects.
 *
 * @ingroup base
 */
class DependencyGraph
{
public:
	static void AddDependency(Object* child, Object* parent);
	static void RemoveDependency(Object* child, Object* parent);
	static std::vector<Object::Ptr> GetChildren(const Object::Ptr& parent);

private:
	DependencyGraph();

	static std::mutex m_Mutex;
	static std::map<Object *, std::map<Object *, int> > m_Dependencies;
};

}

#endif /* DEPENDENCYGRAPH_H */
