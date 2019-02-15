#pragma once
using namespace std;
using namespace tinyxml2;

#ifndef _SOURCE_H_
#define _SOURCE_H_

class Source{
	public:
		Source(){
			
		};
		string getPath(char order) {
			switch (order) {
			case 'i':
				return this->inputPath;
			case 'o':
				return this->outputPath;
			case 'b':
				return this->bufferPath;
			case 'l':
				return this->logPath;
			default:
				return NULL;
			}
		}
	private:
		const string inputPath = "input";
		const string outputPath = "output";
		const string bufferPath = "buffer";
		const string logPath = "log";
};

#endif

bool readyRun(Source user);
bool firstReadyRun(Source user);