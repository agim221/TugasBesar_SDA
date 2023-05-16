/*
	File 				: checkAlgorithm.c
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include"NRLL.c"

int isTransactionEmpty(List *L) {
	
	if(L->firstTransaction == NULL) return 1;
	
	return 0;
}

//almtDate SearchDate(List L, time_t time) {
//	Date *date;
//	date = firstDate(L);
//	struct tm *timeStruct = (struct tm *) malloc(sizeof(struct tm));
//	timeStruct = localtime(&date->time);
//	
//	while(date != NULL) {
//		if(timeLocalStruct->tm_mday == timeStruct->tm_mday) return date;
//		date = date->nextDate;
//		printf("%d %d", timeLocalStruct->tm_mday, timeStruct->tm_mday);
//	}
//	
//	return NULL;
//}

almtDate SearchDate(List L, time_t time) {
	Date *date;
	date = firstDate(L);
	
	while(date != NULL) {
		if(difftime(date->time, time) == 0) return date;
		date = date->nextDate;
	}
	
	return NULL;
}

almtFilm SearchFilm(Date D,String name) {
	Film *film;
	film = firstFilm(D);
	
	while(film != NULL) {
		if(!strcmp(name, film->judul)) return film;
		film = nextFilm(*film);
	}
	
	return NULL;
}

almtFilm SearchFilmNext(Date D,String name) {
	Film *film;
	film = firstFilm(D);
	
	while(nextFilm(*film) != NULL) {
		if(!strcmp(name, nextFilm(*film)->judul)) return film;
		film = nextFilm(*film);
	}
	
	return NULL;
}

almtSchedule SearchSchedule(Film F, time_t time) {
	Schedule *schedule;
	schedule = firstSchedule(F);
	
	while(schedule != NULL) {
		if(difftime(schedule->time, time) == 0) {
			return schedule;
		}
		schedule = nextSchedule(*schedule);
	}
	
	return NULL;
}

almtStudio SearchStudio(Schedule S, String name) {
	Studio *studio;
	studio = nextStudio(S);
	
	if(!strcmp(studioName(*studio), name)) return studio;
	
	return NULL;
}

//almtChair SearchChair(Studio studio, String noKursi) {
//	Chair *chair;
//	chair = studio.nextChair;
//	
//	while(chair != NULL) {
//		if(strcmp(chair->noKursi, noKursi)) return chair;
//		chair = chair->nextChair;
//	}
//	
//	return NULL;
//}

almtDate GetDate(List L, time_t time) {
	return SearchDate(L, time);
}

almtFilm GetFilm(List L, time_t time, String name) {
	return SearchFilm(*GetDate(L, time), name);
}

almtSchedule GetSchedule(List L, time_t timeDate, String name,time_t timeFilm) {
	return SearchSchedule(*GetFilm(L, timeDate, name),timeFilm);
}

almtStudio GetStudio(List L, time_t timeDate, String name, time_t timeFilm,String studioName) {
	return SearchStudio(*GetSchedule(L, timeDate, name, timeFilm), studioName);
}

//almtChair GetChair(List L, String name, time_t time, String studioName, String noKursi) {
//	return SearchChair(GetStudio(L, name, time, studioName), noKursi);
//}

int CountSchedule(Film f) {
	Schedule *bantu;
	bantu = firstSchedule(f);
	int hasil = 0;
	
	while(bantu != NULL) {
		hasil++;
		bantu = nextSchedule(*bantu);
	}
	
	return hasil;
}

almtSchedule SearchSchedulePrev(Film f, int hour, int minute) {
	Schedule *bantu;
	struct tm time;
	memset(&time, 0, sizeof(struct tm));
	time.tm_year = 2020-1900;
	time.tm_mon = 0;
	time.tm_mday = 1;
	time.tm_hour = hour;
	time.tm_min = minute;
	time_t time2 = mktime(&time);
	bantu = firstSchedule(f);
	
	while(bantu != NULL) {
		if(difftime(time2, bantu->time) > 0) return bantu;
		bantu = nextSchedule(*bantu);
	}
	
	return NULL;
}

int CountPerson(lockets queue, int index) {
	Person *bantu;
	bantu = firstPerson(queue, index);
	int hasil = 0;
	
	while(bantu != NULL) {
		hasil++;
		bantu = nextPerson(*bantu);
	}
	
	return hasil;
}

//int ScheduleIsAvailable(List L, time_t time, int duration, int hour, int minute, String studio) {
//	Date *date = firstDate(L);
//	Film *film;
//	Schedule *schedule;
//	int studioExist = 0;
//	struct tm timeStruct;
//	memset(&timeStruct, 0, sizeof(struct tm));
//	timeStruct.tm_year = 2020-1900;
//	timeStruct.tm_mon = 0;
//	timeStruct.tm_mday = 1;
//	timeStruct.tm_hour = hour;
//	timeStruct.tm_min = minute;
//	time_t time2 = mktime(&timeStruct);
//	
//	while(date != NULL) {
//		if(difftime(date->time, time) == 0) {
//			film = firstFilm(*date);
//			break;
//		}
//		date = nextDate(*date);
//	}
//	
//	studioExist = isStudioExist(film, studio);
//	
//	while(film != NULL) {
//		schedule = firstSchedule(*film);
//		
//		if(studioExist) {
//			while(schedule != NULL) {
//				if((difftime(time2, schedule->time) > duration * 60) && (!strcmp(studio, schedule->nextStudio->studioName))) return 1;
//				schedule = nextSchedule(*schedule);
//			}
//		} else {
////			while(schedule != NULL) {
////				printf("%s", ctime(&time2));
////				printf("%s", ctime(&schedule->time));
////				system("pause");
////				if(difftime(time2, schedule->time) > duration * 60) return 1;
////				schedule = nextSchedule(*schedule);
////			}
//			return 0;
//		}
//			
//		film = nextFilm(*film);
//	}
//	
//	return 0;
//}

int CountFilm(Date *D) {
	Film *bantu;
	bantu = firstFilm(*D);
	int hasil = 0;
	
	while(bantu != NULL) {
		hasil++;
		bantu = nextFilm(*bantu);
	}
	
	return hasil;
}

int isStudioExist(Film *film, String studioName) {
	Film *bantu = film;
	Schedule *schedule;
	
	while(bantu != NULL) {
		schedule = firstSchedule(*bantu);
		while(schedule != NULL) {
			if(!strcmp(studioName, schedule->nextStudio->studioName)) {
				return 1;
			}
			schedule = schedule->nextSchedule;
		}
		bantu = nextFilm(*bantu);
	}
		
	return 0;
}
