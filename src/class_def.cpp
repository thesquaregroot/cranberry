
#include "h/class_def.h"
#include <string>
#include <vector>
using namespace clazzy;
using namespace std;

// string _name
// map<access_type,vector<method>> _methods
// map<access_type,vector<member>> _members
// vector<type_hint> _parents

class_def::class_def(const string& name)
{
        _name = name;
}


void class_def::set_name(const string& name)
{
        _name = name;
}

string class_def::get_name() const
{
        return _name;
}

void class_def::add_method(method &m)
{
        _methods[m.get_visibility()].push_back(m);
}

void class_def::add_member(member &m)
{
        _members[m.get_visibility()].push_back(m);
}

void class_def::add_parent(type_hint &t)
{
        _parents.push_back(t);
}

void class_def::set_referenced_types(const vector<type_hint> &types)
{
        _referenced_types = types;
}

vector<method> class_def::get_methods(const access_type *visibility) const
{
        if (visibility != 0) {
                // return methods with given visibilty
                auto it = _methods.find(*visibility);
                if (it != _methods.end()) {
                        return it->second;
                }
                return vector<method>();
        }
        // return all methods
        vector<method> all_methods;
        for (auto p : _methods) {
                for (method m : p.second) {
                        all_methods.push_back(m);
                }
        }
        return all_methods;
}

vector<member> class_def::get_members(const access_type *visibility) const
{
        if (visibility != 0) {
                // return members with given visibilty
                auto it = _members.find(*visibility);
                if (it != _members.end()) {
                        return it->second;
                }
                return vector<member>();
        }
        // return all members
        vector<member> all_members;
        for (auto p : _members) {
                for (member m : p.second) {
                        all_members.push_back(m);
                }
        }
        return all_members;
}

vector<type_hint> class_def::get_parents() const
{
        return _parents;
}

vector<type_hint> class_def::get_referenced_types() const
{
        return _referenced_types;
}


