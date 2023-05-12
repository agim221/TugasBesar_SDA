/*
	File 				: Menu.c
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include "ManipulationFile.c"

void increaseTime(int minute) {
	int tambah;

	timeLocalStruct->tm_min += minute;
	
	if(timeLocalStruct->tm_min > 59) {
		tambah = 0;
		while(timeLocalStruct->tm_min - 60 >= 0) {
			tambah++;
			timeLocalStruct->tm_min -= 60;
		}
		timeLocalStruct->tm_hour += tambah;
	}
	if(timeLocalStruct->tm_hour > 23) {
		tambah = 0;
		while(timeLocalStruct->tm_hour - 24 >= 0) {
			tambah++;
			timeLocalStruct->tm_hour -= 24;
		}
		timeLocalStruct->tm_mday += tambah;
	}
	if(timeLocalStruct->tm_mday > 30) {
		tambah = 0;
		while(timeLocalStruct->tm_mday - 31 >= 0) {
			tambah++;
			timeLocalStruct->tm_mday -= 31;
		} 
		if(timeLocalStruct->tm_mday == 0) timeLocalStruct->tm_mday = 1;
		timeLocalStruct->tm_mon += tambah;
	}
	if(timeLocalStruct->tm_mon > 11) {
		tambah = 0;
		while(timeLocalStruct->tm_mday > 11) {
			tambah++;
			timeLocalStruct->tm_mday -= 11;
		}
		timeLocalStruct->tm_year += tambah;
	} 
	
	timeLocalTime_t = mktime(timeLocalStruct);
}

void setManual(int year, int month, int day, int hour, int minute) {
	timeLocalStruct->tm_year = year;
	timeLocalStruct->tm_mon = month;
	timeLocalStruct->tm_mday = day;
	timeLocalStruct->tm_hour = hour;
	timeLocalStruct->tm_min = minute;
	timeLocalTime_t = mktime(timeLocalStruct);
}


