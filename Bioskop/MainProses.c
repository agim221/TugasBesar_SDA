/*
	File 				: MainProses.c
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include"Queue.c"

void serveQueue(lockets queue, List *X, int index){	
	int x = 14;
	int y = 3;
	int ada = 1;
	int pilih;
	int tiket;
	int i;
	struct tm *tempTime = (struct tm *) malloc(sizeof(struct tm));

	printf("%s", ctime(&timeLocalTime_t));;
	if(isLocketEmpty(queue, index)){
		system("cls");
		gotoxy(30, 8); printf("Antrian Kosong, Silahkan Input Antrian Terlebih Dahulu.\n");
		gotoxy(30, 9); system("pause"); 
		system("cls");
	}else{
		List *bantu = X;
		int i;
		Film *film;
		film = bantu->firstDate->firstFilm;
		Schedule *schedule = film->firstSchedule;
		printPilihFilmDanJadwal(queue, bantu);
		pilih = cursorPilihFilm(CountFilm(bantu->firstDate), &x, &y);
		if(pilih == 99) {
			ada = 0;
			goto end;
		}
		for(i = 1; i < pilih; i++) {
			film = nextFilm(*film);
		}
		
		if(firstPerson(queue, index)->age < film->umur) {
			system("cls");
			ada = 0;
			printf("Belum cukup umur. Pilih film lainnya");
			system("pause");
			system("cls");
			goto end;
		}
		
		y+= 3;
		
		pilih = cursorPilihJadwal(CountSchedule(*film), &x, &y);
		for(i = 1; i < pilih;i++) {
			schedule = nextSchedule(*schedule);
		}
		
		tempTime = localtime(&schedule->time);
			
		if(tempTime->tm_hour < timeLocalStruct->tm_hour || tempTime->tm_hour == timeLocalStruct->tm_hour && tempTime->tm_min >= timeLocalStruct->tm_min) {
			system("cls");
			printf("Jam tersebut sudah tidak tersedia, pilih yang lainnya\n");
			system("pause");
			ada = 0;
			system("cls");	
		}
		
		end:
			if(ada) {
				system("cls");
				printf("Masukan jumlah tiket yang ingin dipesan");scanf("%d", &tiket);
				for(i = 0; i < tiket;i++) {
					printChairStudio(queue, bantu, film, schedule, index);
					system("cls");
				}
				setcolor(15);
			} else if(pilih == 99) {
				system("cls");
				tampilanMenuUtama(queue, X);
			} else {
				serveQueue(queue, X, index);
			}
	}
}

//void CreateFilm(List *L) {
//	int date, hour, minute;
//	String title, category, studioName;
//	title = (String) malloc(sizeof(char));
//	category = (String) malloc(sizeof(char));
//	studioName = (String) malloc(sizeof(char));
//	int age, duration;
//	char lagi = 'Y';
//	
//	struct tm timeStruct;
//	time_t time;
//	time_t timeSchedule;
//	
//	gotoxy(40, 2); printf("Ingin Menambahkan Film di Tanggal Berapa ? ");
//	gotoxy(40, 5);printf("Masukan Tanggal : "); scanf("%d", &date);
//	
//	memset(&time, 0, sizeof(struct tm));
//	timeStruct.tm_year = timeLocalStruct->tm_year;
//	timeStruct.tm_mon = timeLocalStruct->tm_mon;
//	timeStruct.tm_mday = date;
//	time = mktime(&timeStruct);
//	
//	if(GetDate(*L, time) == NULL) {
//		addDateLast(L, timeStruct.tm_year, timeStruct.tm_mon, date);
//	}
//	
//	Date *dateFilm = GetDate(*L, time);
//	
//	gotoxy(40, 6);printf("Masukan Informasi Film");
//	gotoxy(40, 7);printf("Title : "); scanf(" %[^\n]", title);
//	gotoxy(40, 8);printf("Category : "); scanf(" %[^\n]", category);
//	gotoxy(40, 9);printf("Age : "); scanf("%d", &age);
//	gotoxy(40, 10);printf("Duration : "); scanf("%d", &duration);
//	
//	addFilmLast(dateFilm , title, category, age, duration);
//	
//	Film *film = GetFilm(*L, time, title);
//
//	while(CountSchedule(*film) < 36000 / filmDuration(*film) && lagi == 'Y') {
//		jam :
//			gotoxy(40, 11);printf("Masukan Jam Tayang : "); scanf("%d", &hour);
//		if(timeLocalStruct->tm_hour < 10 || timeLocalStruct->tm_hour > 20) {
//			printf("\nMasukan di jam operasional antara jam 10 - 20");
//			goto jam;
//		}
//		gotoxy(40, 12);printf("Masukan Menit Tayang : "); scanf("%d", &minute);
//		gotoxy(40, 13);printf("Masukan Studio yang Menayangkan : "); scanf(" %[^\n]", studioName);
//		
//		if(ScheduleIsAvailable(*L, time, duration, hour, minute, studioName)) {
//			printf("\nMasukan Jam dan Menit tayang yang berbeda");
//			continue;
//		}
//		
//		if(firstSchedule(*film) == NULL) {
//			addScheduleFirst(film, hour, minute);
//		} else {
//			addScheduleAfter(SearchSchedulePrev(*film, hour, minute), film, hour, minute);
//		}
//		
//		timeStruct.tm_year = 2020-1900;
//		timeStruct.tm_mon = 0;
//		timeStruct.tm_mday = 1;
//		timeStruct.tm_hour = hour;
//		timeStruct.tm_min = minute;
//		timeSchedule = mktime(&timeStruct);
//		
//		Schedule *schedule = GetSchedule(*L, time, title, timeSchedule);
//		
//		addStudio(schedule, studioName);
//		gotoxy(30, 17);printf("Ingin Memasukan Jam Tayang Lainnya ? (Y/N)"); scanf(" %c", &lagi);
//	}
//}

void CreateFilm(List *L) {
	int date, hour, minute;
	String title, category, studioName;
	title = (String) malloc(sizeof(char));
	category = (String) malloc(sizeof(char));
	studioName = (String) malloc(sizeof(char));
	int age, duration;
	char lagi = 'Y';
	
	struct tm timeStruct;
	time_t timeDate;
	time_t timeSchedule;
	
	gotoxy(40, 2); printf("Ingin Menambahkan Film di Tanggal Berapa ? ");
	gotoxy(40, 5);printf("Masukan Tanggal : "); scanf("%d", &date);
	
	memset(&timeStruct, 0, sizeof(struct tm));
	timeStruct.tm_year = timeLocalStruct->tm_year;
	timeStruct.tm_mon = timeLocalStruct->tm_mon;
	timeStruct.tm_mday = date;
	timeDate = mktime(&timeStruct);
	
	if(GetDate(*L, timeDate) == NULL) {
		addDateLast(L, timeStruct.tm_year, timeStruct.tm_mon, date);
	}

	Date *dateFilm = GetDate(*L, timeDate);
	
	gotoxy(40, 6);printf("Masukan Informasi Film");
	gotoxy(40, 7);printf("Title : "); scanf(" %[^\n]", title);
	gotoxy(40, 8);printf("Category : "); scanf(" %[^\n]", category);
	gotoxy(40, 9);printf("Age : "); scanf("%d", &age);
	gotoxy(40, 10);printf("Duration : "); scanf("%d", &duration);
		
//	addFilmFirst(dateFilm, title, category, age, duration);
	addFilmLast(dateFilm, title, category, age, duration);
	
	Film *film = GetFilm(*L, timeDate, title);
	printf("%s", film->judul);
	system("pause");
	
	while(lagi == 'Y') {
		jam :
			gotoxy(40, 11);printf("Masukan Jam Tayang : "); scanf("%d", &hour);
		if(hour < 10 || hour > 20) {
			printf("\nMasukan di jam operasional antara jam 10 - 20");
			goto jam;
		}
		gotoxy(40, 12);printf("Masukan Menit Tayang : "); scanf("%d", &minute);
		gotoxy(40, 13);printf("Masukan Studio yang Menayangkan : "); scanf(" %[^\n]", studioName);
		
		
		
		if(ScheduleIsAvailable(*L, *dateFilm, studioName, duration, hour, minute)) {
			printf("\nMasukan Jam dan Menit tayang yang berbeda");
			continue;
		}
		
		printf("test");
		system("pause");
		
		if(firstSchedule(*film) == NULL) {
			printf("\nMasuk di awal");
			system("pause");
			addScheduleFirst(film, hour, minute);
		} else {
			printf("\nMasuk setelahnya");
			system("pause");
			addScheduleAfter(SearchSchedulePrev(*film, hour, minute), film, hour, minute);
		}
		
		timeStruct.tm_year = 2020-1900;
		timeStruct.tm_mon = 0;
		timeStruct.tm_mday = 1;
		timeStruct.tm_hour = hour;
		timeStruct.tm_min = minute;
		timeSchedule = mktime(&timeStruct);
		
		Schedule *schedule = GetSchedule(*L, timeDate, title, timeSchedule);
		
		addStudio(schedule, studioName);
		gotoxy(30, 17);printf("Ingin Memasukan Jam Tayang Lainnya ? (Y/N)"); scanf(" %c", &lagi);
	}
}

int ScheduleIsAvailable(List L, Date date, String studioName, int duration, int hour, int minute) {
	Film *film = firstFilm(date);
	Schedule *schedule;
	int studioExist;
	
//	struct tm *timeStruct;
//	time_t time;
//	timeStruct = (struct tm *) malloc(sizeof(struct tm));
//	memset(timeStruct, 0, sizeof(struct tm));
//	timeStruct->tm_year = 2020-;
//	timeStruct->tm_mon = 0;
//	timeStruct->tm_mday = 1;
//	timeStruct->tm_hour = hour;
//	timeStruct->tm_min = minute;
//	time = mktime(timeStruct);
	
	studioExist = isStudioExist(film, studioName);
	printf("\n%d\n", studioExist);
	system("pause");
	
	while(film != NULL) {
		if(studioExist) {
			schedule = firstSchedule(*film);
			while(schedule != NULL) {
				printf("%s", ctime(&schedule->time));
				printf("%s", ctime(&timeLocalTime_t));
				if((difftime(timeLocalTime_t, schedule->time) > duration * 60) && (!strcmp(studioName, schedule->nextStudio->studioName))) return 1;
				schedule = nextSchedule(*schedule);
			}
		} else {
			return 0;
		}
		film = nextFilm(*film);		
	}
	
	return 0;
}

void EditFilm(List *L) {
	Date *date;
	Film *film;
	Schedule *schedule;
	struct tm *time;
	date = firstDate(*L);
	String title = (String) malloc(sizeof(char));
	String tempString = (String) malloc(sizeof(char));
	int i;
	int tempNumber;
	int jumlahPilihan = 5;
	
	printf("Masukan judul film yang ingin diubah : "); scanf(" %[^\n]", title);
	
	while(date != NULL) {
		film = GetFilm(*L, date->time, title);
		if(film != NULL) break;
		date = nextDate(*date);
	}
	
	tampilkanPilihanMenuEditFilm(*film);
	
	if(firstSchedule(*film) == NULL) jumlahPilihan = 4;
	
	
	switch(Cursor(jumlahPilihan, 48, 8)) {
		case 1:
			printf("Masukan Judul Baru : "); scanf(" %[^\n]", tempString);
			filmTitle(*film) = tempString;
			break;
		case 2:
			printf("Masukan kategori baru : "); scanf(" %[^\n]", tempString);
			filmCategory(*film) = tempString;
			break;
		case 3: 
			printf("Masukan umur baru : "); scanf("%d", &tempNumber);
			filmAge(*film) = tempNumber;
			break;
		case 4:
			printf("Masukan durasi baru : "); scanf("%d", &tempNumber);
			filmDuration(*film) = tempNumber;
			break;
		case 5:
			schedule = firstSchedule(*film);
			tampilkanPilihanMenuEditJamTayang(*film);
			printf("test");
			for(i = 0; i < Cursor(CountSchedule(*film), 48, 8) - 1; i++) {
				schedule = nextSchedule(*schedule);
			}
			time = localtime(&schedule->time);
			printf("Masukan Jam Tayang : "); scanf("%d", &tempNumber);
			time->tm_hour = tempNumber;
			printf("Masuka Meni Tayang : "); scanf("%d", &tempNumber);
			time->tm_min = tempNumber;
			schedule->time = mktime(time);
			break;
	}
}

void DeleteFilm(List *L) {
	Date *date = firstDate(*L);
	Film *film = NULL;
	String title = (String) malloc(sizeof(char));
	if(date != NULL) {
		printf("\n\n\t\t\t\tMasukan Judul Film yang ingin dihapus : ");
		scanf("% [^\n], title");
		
		while(date != NULL) {
			if(SearchFilmNext(*date, title)) {
				film = SearchFilmNext(*date, title);
				break;
			}
			date = nextDate(*date);
		}
	
		if(film == NULL) {
			printf("\nFilm tersebut tidak ada");
		} else {
			delFilmAfter(film, date);
		}
	} else {
		printf("\nList film kosong");
	}
}

void DeleteAllData(List *L) {
	if(L->firstDate != NULL) {
		while(L->firstDate != NULL) {
			delDateFirst(L);
		}
		L->firstDate = NULL;
		L->lastDate = NULL;	
	} else {
		printf("\nData Kosong");
	}
}




