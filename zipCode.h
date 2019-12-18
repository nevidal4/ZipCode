#ifndef _ZIP_H
#define _ZIP_H
const int BC_LENGTH = 28; // barcode length
const int SEQUENCE[5] = { 7,4,2,1,0 }; // barcode to zipcode conversion key
class ZipCode {
private:
	// int zip;
	// int toZip(char*bar);
	void toBar(int z); // helper method to convert zipcode to barcode
	char*bc = new char[BC_LENGTH]; // barcode as string
public:
	ZipCode(); // default constructor
	ZipCode(int zarg); // constructor to initialize zipcode
	ZipCode(char*bar); // constructor to initialize barcode
	~ZipCode(); // destructor
	int getZipCode(); // returns zipcode
	char*getBarCode(); // returns barcode as string
};
#endif