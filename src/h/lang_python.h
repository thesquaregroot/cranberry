#ifndef __CLAZZY_LANG_PYTHON_H__
#define __CLAZZY_LANG_PYTHON_H__

#include "language.h"
#include "class_def.h"
#include "type_convertor.h"
#include "access_type.h"
#include <vector>
#include <map>
#include <string>

namespace clazzy {
    class lang_python : public language {
        public:
            lang_python(std::mutex *io, bool debug) : language(io, debug) { initialize(); }

            std::string get_name() const override;
            std::string get_simple_name() const override;
            void create(
                        const std::vector<class_def>&,
                        const std::map<std::string,std::string>&
                    ) const override;

        private:
            void initialize();

            static std::map<access_type,std::string> access_prefixes;
            type_convertor types;
    };
}

#endif
