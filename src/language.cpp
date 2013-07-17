
#include "h/language.h"
#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <map>
using namespace cranberry;
using namespace std;

// mutex *io_mutex
// bool debug_enabled

language::language(mutex *io, bool debug) {
        io_mutex = io;
        debug_enabled = debug;
}

void language::debug(const string &s) const {
        if (debug_enabled) {
                io_mutex->lock();
                cout << "[DEBUG:" << this->get_name() << "] " << s << endl;
                io_mutex->unlock();
        }
}

void language::error(const string &s) const {
        io_mutex->lock();
        cerr << "[ERROR:" << this->get_name() << "] " << s << endl;
        io_mutex->unlock();
}

