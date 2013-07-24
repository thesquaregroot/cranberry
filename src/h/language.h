#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <vector>
#include <string>
#include <map>
#include <mutex>
#include <ostream>

namespace cranberry {
    class class_def;

    class language {
        public:
            language(std::mutex*, bool = false);
            virtual ~language() {}

            virtual std::string get_name() const = 0;
            virtual void create(
                                const std::vector<class_def>&,
                                const std::map<std::string,std::string>&
                    ) const = 0;

        protected:
            // helper functions for all langauges
            void debug(const std::string &) const;
            void error(const std::string &) const;
            void print_cranberry_notice(std::ostream &, const std::string &) const;

        private:
            std::mutex *io_mutex;
            bool debug_enabled;
    };
}

#endif
