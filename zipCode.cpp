#include <iostream>
#include <cmath>
#include "zipCode.h"
using namespace std;
ZipCode::ZipCode() {
	bc[0] = '\0'; // initializes zipcode as empty string
}
ZipCode::ZipCode(int z) {
	bc[0] = '\0'; // initializes barcode as empty string
	toBar(z); // converts input zipcode to barcode via helper method
}
ZipCode::ZipCode(char*bar) {
	bc[0] = '\0'; // initializes barcode as empty string
	strcpy(bc, bar); // coppies arguement to object barcode in memory
}
ZipCode::~ZipCode() {
	delete[] bc; // unasigns barcode digits stored in memory
}
void ZipCode::toBar(int z) {
	strcpy(bc, "1"); // because barcodes always begin and end with '1's
	for (int exp = 4; 0 <= exp; --exp) { // exp representing the place of current zipcode digit
		switch (z / (int)pow(10, exp)) { // takes first digit of zipcode and matches it to binary
			case 0: strcat(bc, "11000"); break;
			case 1: strcat(bc, "00011"); break;
			case 2: strcat(bc, "00101"); break;
			case 3: strcat(bc, "00110"); break;
			case 4: strcat(bc, "01001"); break;
			case 5: strcat(bc, "01010"); break;
			case 6: strcat(bc, "01100"); break;
			case 7: strcat(bc, "10001"); break;
			case 8: strcat(bc, "10010"); break;
			case 9: strcat(bc, "10100"); break;
		}
		z %= (int)pow(10, exp); // truncates the last converted digit of zipcode
	}
	strcat(bc, "1");
}
char*ZipCode::getBarCode() { // barcode getter method
	return bc;
}
int ZipCode::getZipCode() {
	int zip = 0, digit = 0; // zipcode so far, current zipcode digit
	for (int bcIndex = 1, exp = 4; bcIndex < BC_LENGTH - 6; bcIndex += 5, --exp) { // leading digit of barcode quadruplet, place of current digit
		for (int i = 0; i < 5; ++i)
			digit += SEQUENCE[i] * (bc[bcIndex + i] - 48); // uses key to convert binary quadruplet into a single zipcode digit
		if (9 < digit) // incase digit results above 9, it represents a '0'
			digit = 0;
		zip += (int)pow(10, exp)*digit; // places digit in its subsequent place in zipcode starting at begining
		digit = 0;
		}
	return zip;
}
//			**ALTERNATIVE CLASS CODE**
/*
ZipCode::ZipCode() {
	zip = 0;
}
ZipCode::ZipCode(int z) {
	zip = z;
}
ZipCode::ZipCode(char*bar) {
	zip = 0;
	toZip(bar);
}
ZipCode::~ZipCode() {
	zip = 0;
}
int ZipCode::getZipCode() {
	return zip;
}
char*ZipCode::getBarCode() {
	int remainingDigits = zip;
	//static char bc[BC_LENGTH] = "";
	strcpy(bc, "");
	//char *bc;// = new char[BC_LENGTH];
	strcat_s(bc, "1");
	for (int exp = 4; 0 <= exp ; --exp){
		switch (remainingDigits / (int)pow(10, exp)) {
		case 0: strcat_s(bc, "11000"); break;
		case 1: strcat_s(bc, "00011"); break;
		case 2: strcat_s(bc, "00101"); break;
		case 3: strcat_s(bc, "00110"); break;
		case 4: strcat_s(bc, "01001"); break;
		case 5: strcat_s(bc, "01010"); break;
		case 6: strcat_s(bc, "01100"); break;
		case 7: strcat_s(bc, "10001"); break;
		case 8: strcat_s(bc, "10010"); break;
		case 9: strcat_s(bc, "10100"); break;
		}
		remainingDigits %= (int)pow(10, exp);
	}
	strcat_s(bc, "1");
	//cout << bc << endl;
	return bc;
}
int ZipCode::toZip(char*bar) {
	int z = 0, digit = 0;
	for (int barIndex = 1, digIndex = 0, exp = 4; barIndex < BC_LENGTH - 1; barIndex += 5, ++digIndex, --exp) {
		for (int seqIndex = 0; seqIndex < 5; ++seqIndex)
			digit += SEQUENCE[seqIndex] * (bar[barIndex + seqIndex] - 48);
		if (9 < digit)
			digit = 0;
		z += digit * (int)pow(10, exp);
		digit = 0;
	}
	return z;
}
*/
