#include"Queue.c"

void serveQueue(lockets queue, List *X, int index){
	if(isLocketEmpty(queue, index)){
		system("cls");
		gotoxy(30, 8); printf("Antrian Kosong, Silahkan Input Antrian Terlebih Dahulu.\n");
		system("pause"); system("cls");
	}else{
		List *bantu = X;
		printPilihFilmDanJadwal(queue, bantu);
		system("cls");
		addStudio(bantu->firstDate->firstFilm->firstSchedule, "Studio 1");
		printChairStudio(queue, bantu);
	}
}

void CreateFilm(List *L) {
	int year, month, date, hour, minute;
	String title, category, studioName;
	title = (String) malloc(sizeof(char));
	category = (String) malloc(sizeof(char));
	studioName = (String) malloc(sizeof(char));
	int age, duration;
	char lagi = 'Y';
	
	struct tm timeStruct;
	time_t time;
	time_t timeSchedule;
	
	printf("\nIngin Menambahkan Film di Tanggal Berapa ? ");
	printf("\nMasukan Tahun : "); scanf("%d", &year);
	printf("\nMasukan Bulan : "); scanf("%d", &month);
	printf("\nMasukan Tanggal : "); scanf("%d", &date);
	
	memset(&time, 0, sizeof(struct tm));
	timeStruct.tm_year = year - 1900;
	timeStruct.tm_mon = month - 1;
	timeStruct.tm_mday = date;
	time = mktime(&timeStruct);
	
	if(GetDate(*L, time) == NULL) {
		addDateLast(L, year, month, date);
	}
	
	Date *dateFilm = GetDate(*L, time);
	
	printf("\nMasukan Informasi Film");
	printf("\nTitle : "); scanf(" %[^\n]", title);
	printf("\nCategory : "); scanf(" %[^\n]", category);
	printf("\nAge : "); scanf("%d", &age);
	printf("\nDuration : "); scanf("%d", &duration);
	
	addFilmLast(dateFilm , title, category, age, duration);
	
	Film *film = GetFilm(*L, time, title);

	while(CountSchedule(*film) < 36000 / filmDuration(*film) && lagi == 'Y') {
		printf("\nMasukan Jam Tayang : "); scanf("%d", &hour);
		printf("\nMasukan Menit Tayang : "); scanf("%d", &minute);
		printf("\nMasukan Studio yang Menayangkan : "); scanf(" %[^\n]", studioName);
		
		if(ScheduleIsAvailable(*L, time, duration, hour, minute, studioName)) {
			printf("\nMasukan Jam dan Menit tayang yang berbeda");
			continue;
		}
		
		if(firstSchedule(*film) == NULL) {
			addScheduleFirst(film, hour, minute);
		} else {
			addScheduleAfter(SearchSchedulePrev(*film, hour, minute), film, hour, minute);
		}
		
		timeStruct.tm_year = 2020-1900;
		timeStruct.tm_mon = 0;
		timeStruct.tm_mday = 1;
		timeStruct.tm_hour = hour;
		timeStruct.tm_min = minute;
		timeSchedule = mktime(&timeStruct);
		
		Schedule *schedule = GetSchedule(*L, time, title, timeSchedule);
		
		addStudio(schedule, studioName);
		printf("\nIngin Memasukan Jam Tayang Lainnya ? (Y/N)"); scanf(" %c", &lagi);
	}
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




