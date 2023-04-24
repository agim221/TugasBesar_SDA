#include"Queue.c"

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
