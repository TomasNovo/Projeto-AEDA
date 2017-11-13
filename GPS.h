#ifndef GPS_H
#define GPS_H

#include <iostream>

/**
 * @brief      Class for GPS coordinates.
 */
class GPS {

	double latitude;
	double longitude;
public:

	GPS();
	GPS(double latitude, double longitude);
	double distance(const GPS & gps2);
	double getLatitude() const;
	double getLongitude() const;
	double degreesToRadians(const double & input) const;
	

};
std::ostream& operator <<(std::ostream & os,const GPS & input);

/**
 * @brief      Class for handling wrong coordinates in GPS.
 */
class WrongCoordinates {
	
	GPS gps;

public:

	WrongCoordinates(GPS gps);

	GPS getGPS();


};


#endif