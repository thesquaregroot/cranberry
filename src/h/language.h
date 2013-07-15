#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <vector>
#include <string>
#include <map>

namespace cranberry {
    class class_def;

    class language {
        public:
            virtual ~language() {}

            virtual std::string get_name() const = 0;
            virtual void create(
                                const std::vector<class_def>&,
                                const std::map<std::string,std::string>&
                    ) const = 0;
    };
}

#endif
