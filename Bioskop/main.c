#include"Menu.c"

int main() {
	
	List list;
	lockets locket;
	
	createLocket(locket, "loket1", 0);
	createLocket(locket, "loket2", 1);
	
//	addPerson(locket, "Agim", 19, 0);
//	addPerson(locket, "Saya", 20, 0);
	
	
//  testDate
//	printChairStudio(locket, &list)
	createDate(&list);
	addDateFirst(&list, 2021, 2, 20);
//	addDateAfter(list.lastDate, &list, 2022, 3, 10);
//	addDateLast(&list, 2023, 4, 11);
//	printDate(list);
//	delPerson(locket, 0);
	
//	testFilm
	addFilmFirst(list.firstDate, "Pirates of the carribean", "action", 18, 168);
//	addFilmAfter(list.firstDate->firstFilm, list.firstDate, "Troll", "comedi", 20, 150);
//	addFilmLast(list.firstDate, "tamiya", "lulu", 11, 21);
//	printFilm(*list.firstDate);

//	testSchedule
	addScheduleFirst(list.firstDate->firstFilm, 9, 30);
	addScheduleAfter(list.firstDate->firstFilm->firstSchedule, list.firstDate->firstFilm, 10, 30);
	addScheduleLast(list.firstDate->firstFilm, 11, 30);
//	printSchedule(*list.firstDate->firstFilm);


	
	/*TEST STUDIO*/
//	addStudio(list.firstDate->firstFilm->firstSchedule, "Studio 1");
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
	tampilanMenuUtama(locket, &list);
//printPilihFilmDanJadwal();
//	printChair();
	
//	printQueue(locket, 0);
//	CreateFilm(&list);
//	printListFilm(locket, &list);
	system("pause");
	system("cls");
//	tampilanMenuUtama(locket ,&list);
//	CreateFilm(&list);
//	EditFilm(&list);
	system("cls");
//	printListFilm(locket, &list);
//	tampilanMenuUtama(locket ,&list);
	
	return 0;
}
