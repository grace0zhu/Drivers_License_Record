prog: main.o DriversLicenseRecord.o DMV.o
	g++ -std=c++11 -g -Wall main.o DriversLicenseRecord.o DMV.o -o prog

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
DriversLicenseRecord.o: DriversLicenseRecord.h DriversLicenseRecord.cpp
	g++ -std=c++11 -g -Wall -c DriversLicenseRecord.cpp
DMV.o: DMV.h DMV.cpp
	g++ -std=c++11 -g -Wall -c DMV.cpp
clean: 
	rm *.o prog