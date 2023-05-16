/*
	File 				: NRLL.c
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include"LocalTime.c"


/*NRLL Date*/
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
	time->tm_year = year;
	time->tm_mon = month;
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
			firstDate(*L) = baru;
//			lastDate(*L) = baru;
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
		time->tm_year = year;
		time->tm_mon = month;
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

void delDateFirst(List *L) {
	Date *hapus;
	hapus = firstDate(*L);
	
	if(hapus != NULL) {
		if(nextDate(*hapus) == NULL) {
			firstDate(*L) = NULL;
			lastDate(*L) = NULL;
		} else {
			firstDate(*L) = nextDate(*hapus);
		}
		while(hapus->firstFilm != NULL) {
			delFilmFirst(hapus);
		}
		free(hapus);
	} else {
		printf("Data Kosong\n");
	}
}

void delDateAfter(Date *prev, List *L) {
	if(prev != NULL) {
		Date *hapus;
		hapus = nextDate(*prev);
		if(hapus != NULL) {
			if(nextDate(*hapus) == NULL) {
				lastDate(*L) = prev;
				nextDate(*prev) = NULL;
			} else {
				nextDate(*prev) = nextDate(*hapus);
			}
			while(hapus->firstFilm != NULL) {
				delFilmFirst(hapus);
			}
			free(hapus);
		} else {
			printf("Data Kosong");
		}
	}
}

void delDateLast(List *L) {
	if(firstDate(*L) != NULL) {
		Date *last, *beforeLast;
		last = firstDate(*L);
		beforeLast = NULL;
		if(nextDate(*last) == NULL) {
			delDateFirst(L);
		} else {
			while(last != NULL) {
				beforeLast = last;
				last = nextDate(*last);
			}
			delDateAfter(beforeLast, L);
		}
	} else {
		printf("Data Kosong\n");
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
			last = last->nextFilm;
		}

		addFilmAfter(beforeLast, D, title, category, age, duration);
	}
}

void delFilmFirst(Date *D) {
	Film *hapus;
	hapus = firstFilm(*D);
	
	if(hapus != NULL) {
		if(nextFilm(*hapus) == NULL) {
			firstFilm(*D) = NULL;
			lastFilm(*D) = NULL;
		} else {
			firstFilm(*D) = nextFilm(*hapus);
		}
		while(hapus->firstSchedule != NULL) {
			delScheduleFirst(hapus);
		}
		free(hapus);
	} else {
		printf("Data Kosong\n");
	}
}

void delFilmAfter(Film *prev, Date *D) {
	if(prev != NULL) {
		Film *hapus;
		hapus = nextFilm(*prev);
		if(hapus != NULL) {
			if(nextFilm(*hapus) == NULL) {
				lastFilm(*D) = prev;
				nextFilm(*prev) = NULL;
			} else {
				nextFilm(*prev) = nextFilm(*hapus);
			}
			while(hapus->firstSchedule != NULL) {
				delScheduleFirst(hapus);
			}
			free(hapus);
		} else {
			printf("Data Kosong");
		}
	}
}

void delFilmLast(Date *D) {
	if(firstFilm(*D) != NULL) {
		Film *last, *beforeLast;
		last = firstFilm(*D);
		beforeLast = NULL;
		if(nextFilm(*last) == NULL) {
			delFilmFirst(D);
		} else {
			while(last != NULL) {
				beforeLast = last;
				last = nextFilm(*last);
			}
			delFilmAfter(beforeLast, D);
		}
	} else {
		printf("Data Kosong\n");
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

void printAllFilm(List L) {
	Date *date = firstDate(L);
	Film *film;
	int i = 1;
	gotoxy(45, 2); printf("List Full Film");
	if(date != NULL) {
		while(date != NULL) {
			film = firstFilm(*date);
			while(film != NULL) {
				gotoxy(35, 2 + i++); printf("%s", filmTitle(*film));
				film = nextFilm(*film);
			}
			date = nextDate(*date);
		}
	} else {
		printf("\nFilm Kosong");
	}
}

/*NRLL Schedule*/
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

void delScheduleFirst(Film *F) {
	Schedule *hapus;
	hapus = firstSchedule(*F);
	
	if(hapus != NULL) {
		if(nextSchedule(*hapus) == NULL) {
			firstSchedule(*F) = NULL;
			lastSchedule(*F) = NULL;
		} else {
			firstSchedule(*F) = nextSchedule(*hapus);
		}
		delStudio(hapus);
		free(hapus);
	} else {
		printf("Data Kosong\n");
	}
}

void delScheduleAfter(Schedule *prev, Film *F) {
	if(prev != NULL) {
		Schedule *hapus;
		hapus = nextSchedule(*prev);
		if(hapus != NULL) {
			if(nextSchedule(*hapus) == NULL) {
				lastSchedule(*F) = prev;
				nextSchedule(*prev) = NULL;
			} else {
				nextSchedule(*prev) = nextSchedule(*hapus);
			}
			delStudio(hapus);
			free(hapus);
		} else {
			printf("Data Kosong");
		}
	}
}

void delScheduleLast(Film *F) {
	if(firstSchedule(*F) != NULL) {
		Schedule *last, *beforeLast;
		last = firstSchedule(*F);
		beforeLast = NULL;
		if(nextSchedule(*last) == NULL) {
			delScheduleFirst(F);
		} else {
			while(last != NULL) {
				beforeLast = last;
				last = nextSchedule(*last);
			}
			delScheduleAfter(beforeLast, F);
		}
	} else {
		printf("Data Kosong\n");
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
void addStudio(Schedule *S, String name) {
	Studio *studio;
	int i;
	
	studio = (Studio *) malloc(sizeof(Studio));
	studio->Chair = (almtKursi)malloc(sizeof(Kursi));
	
	jmlhPenonton(*studio) = 0;
	studioName(*studio) = name;
	
	for(i = 0; i < 10; i++){
		studio->Chair->A[i] = (almtChair)malloc(sizeof(Chair));
		studio->Chair->B[i] = (almtChair)malloc(sizeof(Chair));
		studio->Chair->C[i] = (almtChair)malloc(sizeof(Chair));
		studio->Chair->D[i] = (almtChair)malloc(sizeof(Chair));
		studio->Chair->E[i] = (almtChair)malloc(sizeof(Chair));
		studio->Chair->F[i] = (almtChair)malloc(sizeof(Chair));
		studio->Chair->G[i] = (almtChair)malloc(sizeof(Chair));
	}
	
	for(i = 0; i < 10; i++){
		studio->Chair->A[i]->status = 0;
		studio->Chair->B[i]->status = 0;
		studio->Chair->C[i]->status = 0;
		studio->Chair->D[i]->status = 0;
		studio->Chair->E[i]->status = 0;
		studio->Chair->F[i]->status = 0;
		studio->Chair->G[i]->status = 0;
	}

	nextStudio(*S) = studio;
}

void delStudio(Schedule *S) {
	Studio *hapus;
	hapus = nextStudio(*S);
	
	if(hapus != NULL) {
//		firstChair(*hapus) = NULL;
//		lastChair(*hapus) = NULL;
		nextStudio(*S) = NULL;
			
		free(hapus);
	} else {
		printf("\nStudio tidak ada");
	}
	
}

void printStudio(Schedule S) {
	Studio *bantu;
	bantu = S.nextStudio;
	
	printf("Nama Studio : %s\nJumlah Penonton : %d\n", bantu->studioName, bantu->jmlhPenonton);
}
