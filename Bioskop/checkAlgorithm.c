#include"NRLL.c"

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
	
	if(strcmp(studioName(*studio), name)) return studio;
	
	return NULL;
}

//Chair SearchChair(Studio studio, String noKursi) {
//	Chair *chair;
//	chair = studio->nextChair;
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

int ScheduleIsAvailable(List L, time_t time, int duration, int hour, int minute, String studio) {
	Date *date = firstDate(L);
	Film *film;
	Schedule *schedule;
	int studioExist = 0;
	struct tm timeStruct;
	memset(&timeStruct, 0, sizeof(struct tm));
	timeStruct.tm_year = 2020-1900;
	timeStruct.tm_mon = 0;
	timeStruct.tm_mday = 1;
	timeStruct.tm_hour = hour;
	timeStruct.tm_min = minute;
	time_t time2 = mktime(&timeStruct);
	
	while(date != NULL) {
		if(difftime(date->time, time) == 0) {
			film = firstFilm(*date);
			break;
		}
		date = nextDate(*date);
	}
	
	if(date == NULL) return 0;
	
	studioExist = isStudioExist(*date, studio);
	
	while(film != NULL) {
		schedule = firstSchedule(*film);
		
		if(studioExist) {
			while(schedule != NULL) {
				if((difftime(time2, schedule->time) < duration * 60) && (!strcmp(studio, schedule->nextStudio->studioName))) return 1;
				schedule = nextSchedule(*schedule);
			}
		} else {
			while(schedule != NULL) {
				if(difftime(time2, schedule->time) < duration * 60) return 1;
				schedule = nextSchedule(*schedule);
			}
		}
			
		film = nextFilm(*film);
	}
	
	return 0;
}

int totalFilm(Date *D) {
	Film *bantu;
	bantu = firstFilm(*D);
	int hasil = 0;
	
	while(bantu != NULL) {
		hasil++;
		bantu = nextFilm(*bantu);
	}
	
	return hasil;
}

int isStudioExist(Date D, String studioName) {
	Film *film;
	Schedule *schedule;
	film = firstFilm(D);
	
	while(film != NULL) {
		schedule = firstSchedule(*film);
		while(schedule != NULL) {
			printf("%s\n", schedule->nextStudio->studioName);
			if(!strcmp(studioName, schedule->nextStudio->studioName)) {
				printf("\nKeluar Karena ada\n");
				return 1;
			}
			schedule = schedule->nextSchedule;
		}
		film = nextFilm(*film);
		printf("Next film\n");
	}
	
	return 0;
}
