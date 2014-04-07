#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

vector<int> generuj_tablice(string nazwapliku);
void wyswietl(vector<int> pom);
vector<int> sortuj(vector<int> pom);
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();