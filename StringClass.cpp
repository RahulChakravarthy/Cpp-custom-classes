//String class
//Author Rahul Chakravarthy
//Date created: December 2nd 2016
#include "StringClass.h"
//#include <iostream>

using namespace std;
// CONSTRUCTORS (used out of scope of the class therefore you add the ::nameofclass next to it)/////////////////
myStr::myStr(){

	strLen = 0;
	dataLen = 1;
	data = new char[dataLen];
	data[0] = '\0';
	//cout << "TEST" << endl;

}
myStr::myStr(const myStr& input){

	(*this).strLen = input.strLen;
	(*this).dataLen = input.dataLen;

	(*this).data = new char[strLen];

	for (int i = 0; i < input.strLen; i++){
		(*this).data[i] = input.data[i];
	}
	(*this).data[(*this).strLen] = '\0';
	//cout << (*this).data << endl;
}

myStr::myStr(const char* input){
	//Create temporary buffer to hold all the characters
	int i = 0;
	while (input[i] != '\0'){
		i++;
	}
	(*this).strLen = i;
	(*this).dataLen = i + 1;
	(*this).data = new char[i+1];
	for (int k = 0; k < i; k++){
		(*this).data[k] = input[k];
	}
	(*this).data[i] = '\0';
}

myStr::~myStr(){
/*
	delete (*this).data;
	(*this).strLen = -1;
	(*this).dataLen = -1;
*/
}

//PUBLIC METHODS/////////(Part of class so add classname:: before function name)///////////////////////////////////////////////////////////////////////////////////
int myStr::length() const{

	unsigned int counter = 0;
	while ((*this).data[counter] != '\0'){
	counter++;
	}

	return counter;
}

int myStr::strCmp(const myStr& compareString) const {
	int charCount = 0;
	while((*this).data[charCount] != '\0' || compareString.data[charCount] != '\0') {
		if((*this).data[charCount] == '\0' && compareString.data[charCount] != '\0') {
			return 1;
		} else if((*this).data[charCount] != '\0' && compareString.data[charCount] == '\0') {
			return -1;
		} else if((*this).data[charCount] < 96 && compareString.data[charCount] > 96) {
			return 1;
		} else if((*this).data[charCount] > 96 && compareString.data[charCount] < 96) {
			return -1;
		} else if((*this).data[charCount] < compareString.data[charCount]) {
			return 1;
		} else if((*this).data[charCount] > compareString.data[charCount]) {
			return -1;
		}
		charCount++;
	}
	return 0;
}

int myStr::strCmp(const char* compareArray) const {
	int charCount = 0;
	while((*this).data[charCount] != '\0' || compareArray[charCount] != '\0') {
		if((*this).data[charCount] == '\0' && compareArray[charCount] != '\0') {
			return 1;
		} else if((*this).data[charCount] != '\0' && compareArray[charCount] == '\0') {
			return -1;
		} else if((*this).data[charCount] < 96 && compareArray[charCount] > 96) {
			return 1;
		} else if((*this).data[charCount] > 96 && compareArray[charCount] < 96) {
			return -1;
		} else if((*this).data[charCount] < compareArray[charCount]) {
			return 1;
		} else if((*this).data[charCount] > compareArray[charCount]) {
			return -1;
		}
		charCount++;
	}
	return 0;
}


bool myStr::strCpy(const myStr& input){
//The strCpy()function copies the string from the parameter, overwriting this string
	//delete (*this).data;
	(*this).data = new char[input.dataLen];
	for (int k = 0; k < input.strLen; k++){
		(*this).data[k] = input.data[k];
	}
	(*this).data[input.strLen] = '\0';
	(*this).strLen = input.strLen;
	(*this).dataLen = input.dataLen;
	//cout << "test2: " << (*this).data << endl;
return true;
}

bool myStr::strCpy(const char* input){
	//delete (*this).data;
	int i = 0;
	while (input[i] != '\0'){
		i++;
	}
	(*this).data = new char[i+1];
	for (int k = 0; k < i; k++){
		(*this).data[k] = input[k];
	}
	(*this).data[i+1] = '\0';
	(*this).strLen = i;
	(*this).dataLen = i+1;
	//cout << "test1: "<<  (*this).data << endl;

return true;
}

int myStr::subStr(const char* input) const{
	int i = 0;
	while(input[i] != '\0'){
		i++;
	}
	//Loop through the (*this data) to find matches between the explicit string and the implcity this
	int k = 0; //<-- keeps track of position
	while ((*this).data[k] != '\0'){
		if ((*this).data[k] == input[0]){
			int correct = 0;
			int other = k;
			bool stay = true;
			while (input[correct] != '\0' && stay == true){//MODIFY HERE TO MAKE IT CASE SENSITIVE
				if ((*this).data[other] == input[correct]){
					correct++;
					other++;
				}
				else {
					break;
				}
			}
			if (correct == i){
				return k;
			}
		}
		k++;
	}
	return -1;
}

int myStr::subStr(const myStr& input) const{
	int i = 0;
	while(input.data[i] != '\0'){
		i++;
	}

	//Loop through the (*this data) to find matches between the explicit string and the implcity this
	int k = 0; //<-- keeps track of position
	while ((*this).data[k] != '\0'){
		
		if ((*this).data[k] == input.data[0]){
			int correct = 0;
			int other = k;
			bool stay = true;
			while (input.data[correct] != '\0' && stay == true){//MODIFY HERE TO MAKE IT CASE SENSITIVE
				if ((*this).data[other] == input.data[correct]){
					correct++;
					other++;
				}

				else {
					break;
				}

			}
			if (correct == i){
				return k;
			}
		}
		k++;
	}

	return -1;


}
int myStr::subStr(const char* findMe, int startingAt) const{
	int i = 0;
	while(findMe[i] != '\0'){
		i++;
	}
	//Loop through the (*this data) to find matches between the explicit string and the implcity this
	int k = startingAt; //<-- keeps track of position
	while ((*this).data[k] != '\0'){
		
		if ((*this).data[k] == findMe[0]){
			int correct = 0;
			int other = k;
			bool stay = true;
			while (findMe[correct] != '\0' && stay == true){//MODIFY HERE TO MAKE IT CASE SENSITIVE
				if ((*this).data[other] == findMe[correct]){
					correct++;
					other++;
				}
				else {
					break;
				}
			}
			if (correct == i){
				return k;
			}
		}
		k++;
	}
	return -1;
}
		

int myStr::subStr(const myStr& findMe, int startingAt) const{
	int i = 0;
	while(findMe.data[i] != '\0'){
		i++;
	}

	//Loop through the (*this data) to find matches between the explicit string and the implcity this
	int k = startingAt; //<-- keeps track of position
	while ((*this).data[k] != '\0'){
		
		if ((*this).data[k] == findMe.data[0]){
			int correct = 0;
			int other = k;
			bool stay = true;
			while (findMe.data[correct] != '\0' && stay == true){//MODIFY HERE TO MAKE IT CASE SENSITIVE
				if ((*this).data[other] == findMe.data[correct]){
					correct++;
					other++;
				}

				else {
					break;
				}

			}
			if (correct == i){
				return k;
			}
		}
		k++;
	}

	return -1;
}
char myStr::at(const unsigned int index) const{
	
	if (index == 0 && data[0] == '\0'){
		return 0;
	}
	if (index > strLen){
		return 0;
	}
	return data[index];

}

