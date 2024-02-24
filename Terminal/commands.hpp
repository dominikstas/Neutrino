#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

void execute(const char *command);
void echo(const char *text);
void exitS();
void help();
void start(const std::string& setName);
void add(const std::string& setName);

#endif
