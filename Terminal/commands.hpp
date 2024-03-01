#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

void execute(const char *command);
void echo(const char *text);
void exitNeutrino();
void help();
void start(const std::string& setName);
void add();
void edit();
void lsSet();
void showSets();
void deleteSet(const std::string& setName);

#endif
