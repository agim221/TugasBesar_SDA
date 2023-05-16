/*
	File 				: main.c
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include"Menu.c"

int main() {
	
	List list;
	lockets locket;
	list.firstTransaction = NULL;
	list.lastTransaction = NULL;
	
	timeLocalStruct = (struct tm *) malloc(sizeof(struct tm));
	memset(timeLocalStruct, 1, sizeof(timeLocalStruct));
	timeLocalStruct->tm_year = 2021-1900;
	timeLocalStruct->tm_mon = 1;
	timeLocalStruct->tm_mday = 20;
	timeLocalStruct->tm_hour = 12;
	timeLocalStruct->tm_min = 30;
	timeLocalStruct->tm_sec = 0;
	
	timeLocalTime_t = mktime(timeLocalStruct);

	createLocket(locket, "loket1", 0);
	createLocket(locket, "loket2", 1);
//	printf("%d", list.firstDate->firstFilm->firstSchedule->nextStudio->Chair.A[0]);
	
//	addPerson(locket, "Agim", 19, 0);
//	addPerson(locket, "Saya", 20, 0);
	
	
//  testDate
//	printChairStudio(locket, &list)
	createDate(&list);
//	addDateFirst(&list, timeLocalStruct->tm_year, timeLocalStruct->tm_mon, 20);
////	addDateAfter(list.lastDate, &list, 2022, 3, 10);
////	addDateLast(&list, 2023, 4, 11);
////	printDate(list);
////	delPerson(locket, 0);
//	
////	testFilm
//	addFilmFirst(list.firstDate, "Pirates of the carribean", "action", 18, 168);
//	addFilmAfter(list.firstDate->firstFilm, list.firstDate, "Troll", "comedi", 20, 150);
//	addFilmLast(list.firstDate, "tamiya", "lulu", 11, 21);
////	printFilm(*list.firstDate);
//
////	testSchedule
//	addScheduleFirst(list.firstDate->firstFilm, 12, 30);
//	addScheduleFirst(list.firstDate->firstFilm, 15, 30);
//	addScheduleFirst(list.firstDate->firstFilm, 18, 20);
//	addScheduleAfter(list.firstDate->firstFilm->firstSchedule, list.firstDate->firstFilm, 10, 30);
//	addScheduleLast(list.firstDate->firstFilm, 15, 30);
//	printSchedule(*list.firstDate->firstFilm);
//	printListFilm(locket, &list);
//	system("pause");
//
//	
//	/*TEST STUDIO*/
//	addStudio(list.firstDate->firstFilm->firstSchedule, "Studio 1");
//	addStudio(list.firstDate->firstFilm->firstSchedule->nextSchedule, "studio 2");
//	addStudio(list.firstDate->firstFilm->firstSchedule->nextSchedule->nextSchedule, "Studio 3");
//	printStudio(*list.firstDate->firstFilm->firstSchedule);
//	printListFilm(locket, &list);
//tampilanMenuUtama(locket, &list);
	
//	printListFilm(locket, &list);
//	printListFilm(locket, &list);

	/*TEST CHAIR*/
//	addChair(list.firstDate->firstFilm->firstSchedule->nextStudio, "A1", "toriq", 19);
//	addChair(list.firstDate->firstFilm->firstSchedule->nextStudio, "A2", "agim", 19);
//	addChair(list.firstDate->firstFilm->firstSchedule->nextStudio, "A3", "yayan", 19);
//	printChair(*list.firstDate->firstFilm->firstSchedule->nextStudio);

//	test loket
	getAllData(&list);
	tampilanMenuUtama(locket, &list);

	
//printPilihFilmDanJadwal();m
//	printChair();
	
//	printQueue(locket, 0);
//	CreateFilm(&list);
//	printListFilm(locket, &list);
//	system("pause");
//	system("cls");
//	tampilanMenuUtama(locket ,&list);
//	CreateFilm(&list);
//	EditFilm(&list);
//	system("cls");
//	printListFilm(locket, &list);
//	tampilanMenuUtama(locket ,&list);
	
	return 0;
}
