
#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

std::string takeFirstStation(std::string epath);
int addCall(void* NotUsed, int argc, char** argv, char** colname);
void addEarthquake(Command* cmd);
void askEarthquake(Command* cmd);

#endif


