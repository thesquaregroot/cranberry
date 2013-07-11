#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>
#include <string>

class FlexLexer;

namespace cranberry {
    class class_def;
    class language;
    class function;

    class parser {
        public:
            parser(FlexLexer *lexer);
            ~parser();
            
            void set_debug(bool);
            void parse();
            void write() const;

        private:
            bool                                debug_enabled = false;
            int                                 lookahead;
            FlexLexer                           *lex;
            std::vector<class_def>              classes;
            std::vector<language*>              langs;
            std::map<std::string, std::string>  properties;
            
            void next_token(bool exit_on_eof = true);
            std::string token_text() const;

            void parse_statement();
            void parse_property();
            class_def parse_type_definition();
            void parse_definition_list(class_def&);
            void parse_definition(class_def&);
            void parse_action_list(class_def&);
            void parse_action(class_def&);
            void parse_parameter_list(function&);
            void parse_attribute_list(class_def&);
            
            void debug(std::string) const;
            void error(std::string) const;
    };
}

#endif