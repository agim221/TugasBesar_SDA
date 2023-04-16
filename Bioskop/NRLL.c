#include"StrukturData.c"


/*NRLL Date*/
void createDate(List *L);
void addDateFirst(List *L, int year, int month, int date);
void addDateAfter(Date *prev, List *L, int year, int month, int date);
void addDateLast(List *L, int year, int month, int date);

void createDate(List *L) {
	firstDate(*L) = NULL;
	lastDate(*L) = NULL;
}

void addDateFirst(List *L, int year, int month, int date) {
	
	struct tm *time;
	time = (struct tm *) malloc(sizeof(struct tm));
	Date *baru;
	baru = (Date *) malloc(sizeof(Date));
	memset(time, 0, sizeof(struct tm));
	time->tm_year = year - 1900;
	time->tm_mon = month - 1;
	time->tm_mday = date;
	baru->time = mktime(time);
	nextFilm(*baru) = NULL;
	firstFilm(*baru) = NULL;
	lastFilm(*baru) = NULL;
	
	if(baru != NULL) {
		if(isDateEmpty(*L)) {
			firstDate(*L) = baru;
			lastDate(*L) = baru;
		} else {
			nextDate(*lastDate(*L)) = baru;
			lastDate(*L) = baru;
		}
		nextDate(*baru) = NULL;
	} else {
		printf("\nMemori Penuh");
	}
}

void addDateAfter(Date *prev, List *L,int year, int month, int date) {
	if(prev != NULL) {
		struct tm *time;
		time = (struct tm *) malloc(sizeof(struct tm));
		Date *baru;
		baru = (Date *) malloc(sizeof(Date));
		memset(time, 0, sizeof(struct tm));
		time->tm_year = year - 1900;
		time->tm_mon = month - 1;
		time->tm_mday = date;
		baru->time = mktime(time);
		nextFilm(*baru) = NULL;
		firstFilm(*baru) = NULL;
		lastFilm(*baru) = NULL;
		
		if(nextDate(*prev) == NULL) {
			nextDate(*baru) = NULL;
			lastDate(*L) = baru;
		} else {
			nextDate(*baru) = nextDate(*prev);
		}
		nextDate(*prev) = baru;
	}
}

void addDateLast(List *L, int year, int month, int date) {
	if(firstDate(*L) == NULL) {
		addDateFirst(L, year, month, date);
	} else {
		Date *beforeLast, *last;
		last = firstDate(*L);
		beforeLast = NULL;
		
		while(last != NULL) {
			beforeLast = last;
			last = nextDate(*last);
		}
		addDateAfter(beforeLast, L, year, month, date);
	}
}

void printDate(List L) {
	Date *bantu;
	bantu = L.firstDate;
	
	while(bantu != NULL) {
		printf("%s\n", ctime(&bantu->time));
		bantu = nextDate(*bantu);
	}
}

/*NRLL Film*/
void addFilmFirst(Date *D, String title, String category, int age, int duration);
void addFilmAfter(Film *prev, Date *D, String title, String category, int age, int duration);
void addFilmLast(Date *D, String title, String category, int age, int duration);

int isFilmEmpty(Date D) {
	
	if(nextFilm(D) == NULL) return 1;
	
	return 0;
}

void addFilmFirst(Date *D, String title, String category, int age, int duration) {
	Film *baru;
	baru = (Film *) malloc(sizeof(Film));
	filmDuration(*baru) = duration;
	filmAge(*baru) = age;
	filmTitle(*baru) = title;
	filmCategory(*baru) = category;
	firstSchedule(*baru) = NULL;
	lastSchedule(*baru) = NULL;
	nextSchedule(*baru) = NULL;
	
	if(baru != NULL) {
		if(isFilmEmpty(*D)) {
			firstFilm(*D) = baru;
			lastFilm(*D) = baru;
		} else {
			nextFilm(*lastFilm(*D)) = baru;
			lastFilm(*D) = baru;
		}
		nextFilm(*baru) = NULL;
	} else {
		printf("\nMemori Penuh");
	}
}

void addFilmAfter(Film *prev, Date *D, String title, String category, int age, int duration) {
	if(prev != NULL) {
		Film *baru;
		baru = (Film *) malloc(sizeof(Film));
		filmDuration(*baru) = duration;
		filmAge(*baru) = age;
		filmTitle(*baru) = title;
		filmCategory(*baru) = category;
		firstSchedule(*baru) = NULL;
		lastSchedule(*baru) = NULL;
		nextSchedule(*baru) = NULL;
		
		if(nextFilm(*prev) == NULL) {
			nextFilm(*baru) = NULL;
			lastFilm(*D) = baru;
		} else {
			nextFilm(*baru) = nextFilm(*prev);
		}
		nextFilm(*prev) = baru;
	}
}

void addFilmLast(Date *D, String title, String category, int age, int duration) {
	
	if(firstFilm(*D) == NULL) {
		addFilmFirst(D, title, category, age, duration);
	} else {
		Film *beforeLast, *last;
		last = firstFilm(*D);
		beforeLast = NULL;
		
		while(last != NULL) {
			beforeLast = last;
			last = nextFilm(*last);
		}
		addFilmAfter(beforeLast, D, title, category, age, duration);
	}
}

void printFilm(Date D) {
	Film *bantu;
	bantu = D.firstFilm;
	
	while(bantu != NULL) {
		printf("%s %s %d %d\n", bantu->judul, bantu->kategori, bantu->durasi, bantu->umur);
		bantu = nextFilm(*bantu);
	}
}

/*NRLL Schedule*/
void addScheduleFirst(Film *F, int hour, int minute);
void addScheduleAfter(Schedule *prev, Film *F, int hour, int minute);
void addScheduleLast(Film *F, int hour, int minute);

int isScheduleEmpty(Film F) {
	
	if(firstSchedule(F) == NULL) return 1;
	
	return 0;
}

void addScheduleFirst(Film *F, int hour, int minute) {
	Schedule *baru;
	baru = (Schedule *) malloc(sizeof(Schedule));
	struct tm *time;
	time = (struct tm *) malloc(sizeof(struct tm));
	memset(time, 0, sizeof(struct tm));
	time->tm_year = 2020-1900;
	time->tm_mon = 0;
	time->tm_mday = 1;
	time->tm_hour = hour;
	time->tm_min = minute;
	baru->time = mktime(time);
	nextStudio(*baru) = NULL;
		
	if(baru != NULL) {
		if(isScheduleEmpty(*F)) {
			firstSchedule(*F) = baru;
			lastSchedule(*F) = baru;
		} else {
			nextSchedule(*lastSchedule(*F)) = baru;
			lastSchedule(*F) = baru;
		}
		nextSchedule(*baru) = NULL;
	} else {
		printf("\nMemori Penuh");
	}
}

void addScheduleAfter(Schedule *prev, Film *F, int hour, int minute) {
	if(prev != NULL) {
		Schedule *baru;
		baru = (Schedule *) malloc(sizeof(Schedule));
		struct tm *time;
		time = (struct tm *) malloc(sizeof(struct tm));
		memset(time, 0, sizeof(struct tm));
		time->tm_year = 2020-1900;
		time->tm_mon = 0;
		time->tm_mday = 1;
		time->tm_hour = hour;
		time->tm_min = minute;
		baru->time = mktime(time);
		nextStudio(*baru) = NULL;
		
		if(nextSchedule(*prev) == NULL) {
			nextSchedule(*baru) = NULL;
			lastSchedule(*F) = baru;
		} else {
			nextSchedule(*baru) = nextSchedule(*prev);
		}
		nextSchedule(*prev) = baru;
	}
}

void addScheduleLast(Film *F, int hour, int minute) {
	if(firstSchedule(*F) == NULL) {
		addScheduleFirst(F, hour, minute);
	} else {
		Schedule *beforeLast, *last;
		last = firstSchedule(*F);
		beforeLast = NULL;
		
		while(last != NULL) {
			beforeLast = last;
			last = nextSchedule(*last);
		}
		addScheduleAfter(beforeLast, F, hour, minute);
	}
}

void printSchedule(Film F) {
	Schedule *bantu;
	struct tm *waktu;
	bantu = F.firstSchedule;
	
	while(bantu != NULL) {
		waktu = localtime(&bantu->time);
		printf("%d %d\n", waktu->tm_hour, waktu->tm_min);
		bantu = nextSchedule(*bantu);
	}
}

/*NRLL Film*/
void addStudio(Schedule *S, String name);

void addStudio(Schedule *S, String name) {
	Studio *studio;
	
	jmlhPenonton(*studio) = 0;
	studioName(*studio) = name;
	firstChair(*studio) = NULL;
	lastChair(*studio) = NULL;
	nextChair(*studio) = NULL;
	nextStudio(*S) = studio;
}

void printStudio(Schedule S) {
	Studio *bantu;
	bantu = S.nextStudio;
	
	printf("Nama Studio : %s \nJumlah Penonton : %d", bantu->studioName, bantu->jmlhPenonton);
}
