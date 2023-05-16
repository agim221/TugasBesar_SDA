#include "StrukturData.h"


void saveAllData(List L) {
	remove("data.txt");
	FILE *fp = fopen("data.txt", "w");
	saveAllDate(*L.firstDate, fp);
	printf("keluar");
	fclose(fp);
	printf("ditutup");
}

void saveAllDate(Date date, FILE *fp) {
	Date *bantu = &date;
	while(bantu != NULL) {
		struct tm *time = (struct tm *) malloc(sizeof(struct tm));
		memset(time, 0, sizeof(struct tm));
		time = localtime(&bantu->time);
		
		fprintf(fp, "%s\n", "Date");
		fprintf(fp, "%d\n",time->tm_year);
		fprintf(fp, "%d\n", time->tm_mon);
		fprintf(fp, "%d\n", time->tm_mday);

		saveAllFilm(*firstFilm(*bantu), fp);
		
		bantu = nextDate(*bantu);
	}
}

void saveAllFilm(Film film, FILE *fp) {
	Film *bantu = &film;
	while(bantu != NULL) {
		
		fprintf(fp, "%s\n", "Film");
		fprintf(fp, "%s\n", bantu->judul);
		fprintf(fp, "%s\n", bantu->kategori);
		fprintf(fp, "%d\n", bantu->durasi);
		fprintf(fp, "%d\n", bantu->umur);
		
		saveAllSchedule(*firstSchedule(*bantu), fp);
		
		bantu = nextFilm(*bantu);
	}
}

void saveAllSchedule(Schedule schedule, FILE *fp) {
	Schedule *bantu = &schedule;
	while(bantu != NULL) {
		
		struct tm *time = (struct tm *) malloc(sizeof(struct tm));
		memset(time, 0, sizeof(struct tm));
		time = localtime(&bantu->time);
		
		fprintf(fp, "%s\n", "Schedule");
		fprintf(fp, "%d\n", time->tm_hour);
		fprintf(fp, "%d\n", time->tm_min);
		printf("5");
		saveStudio(*bantu->nextStudio, fp);
		
		bantu = nextSchedule(*bantu);
	}
}

void saveStudio(Studio studio, FILE *fp) {
	
	fprintf(fp, "%s\n", "Studio");
	fprintf(fp, "%s\n", studio.studioName);
	printf("%s", studio.studioName);
//	saveAllChair(*studio.Chair, fp);
}

void saveAllChair(Kursi chair, FILE *fp) {
	int i;
	
	fprintf(fp, "%s\n", "Kursi");
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.A[i]->status);
		} else {
			fprintf(fp, "%d", chair.A[i]->status);
		}
	}
	
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.B[i]->status);
		} else {
			fprintf(fp, "%d", chair.B[i]->status);
		}
	}
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.C[i]->status);
		} else {
			fprintf(fp, "%d", chair.C[i]->status);
		}
	}
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.D[i]->status);
		} else {
			fprintf(fp, "%d", chair.D[i]->status);
		}
	}
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.E[i]->status);
		} else {
			fprintf(fp, "%d", chair.E[i]->status);
		}
	}
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.F[i]->status);
		} else {
			fprintf(fp, "%d", chair.F[i]->status);
		}
	}
	for(i = 0; i < 10;i++) {
		if(i == 9) {
			fprintf(fp, "%d\n", chair.G[i]->status);
		} else {
			fprintf(fp, "%d", chair.G[i]->status);
		}
	}	
}

void getAllData(List *L) {
	FILE *fp = fopen("data.txt", "r");
	
	Date *date;
	Film *film;
	Schedule *schedule;
	Studio *studio;
	Kursi *chair;
	String temp, title, category, duration, age;
	
	struct tm *timeStruct = (struct tm *) malloc(sizeof(struct tm));
	memset(timeStruct, 0, sizeof(struct tm));
	time_t timeDate;
	time_t timeSchedule;
	
	while(!feof(fp)) {
		temp = (String) malloc(sizeof(char));
		fgets(temp, BUFSIZ, fp);
		
		if(!strcmp(temp, "Date\n")) {
			temp = (String) malloc(sizeof(char));
			fgets(temp, BUFSIZ, fp);
			temp[strlen(temp) - 1] = '\0';
			timeStruct->tm_year = atoi(temp);
			fgets(temp, BUFSIZ, fp);
			temp[strlen(temp) - 1] = '\0';
			timeStruct->tm_mon = atoi(temp);
			fgets(temp, BUFSIZ, fp);
			temp[strlen(temp) - 1] = '\0';
			timeStruct->tm_mday = atoi(temp);
		
			addDateLast(L, timeStruct->tm_year, timeStruct->tm_mon, timeStruct->tm_mday);
			
			timeDate = mktime(timeStruct);
			
			date = GetDate(*L, timeDate);
		} else if(!strcmp(temp, "Film\n")) {
			title = (String) malloc(sizeof(char));
			category = (String) malloc(sizeof(char));
			duration = (String) malloc(sizeof(char));
			age = (String) malloc(sizeof(char));
	
			fgets(title, BUFSIZ, fp);
			title[strlen(title) - 1] = '\0';
			fgets(category, BUFSIZ, fp);
			category[strlen(category) - 1] = '\0';
			fgets(duration, BUFSIZ, fp);
			duration[strlen(duration) - 1] = '\0';
			fgets(age, BUFSIZ, fp);
			age[strlen(age) - 1] = '\0';			
			
			addFilmLast(date, title, category, atoi(age), atoi(duration));
			
			film = GetFilm(*L, timeDate, title);
		} else if(!strcmp(temp, "Schedule\n")) {		
			memset(timeStruct, 0, sizeof(struct tm));
			fgets(temp, BUFSIZ, fp);
			temp[strlen(temp) - 1] = '\0';
			timeStruct->tm_hour = atoi(temp);
			fgets(temp, BUFSIZ, fp);
			temp[strlen(temp) - 1] = '\0';
			timeStruct->tm_min = atoi(temp);
			
			timeStruct->tm_year = 2020-1900;
			timeStruct->tm_mon = 0;
			timeStruct->tm_mday = 1;
			
			timeSchedule = mktime(timeStruct);
	
			addScheduleLast(film, timeStruct->tm_hour, timeStruct->tm_min);
			
			schedule = GetSchedule(*L, timeDate, title, timeSchedule);
		} else if(!strcmp(temp,"Studio\n")) {
			temp = (String) malloc(sizeof(char));
			fgets(temp, BUFSIZ, fp);
			temp[strlen(temp) - 1] = '\0';
		
			addStudio(schedule, temp);
			
			studio = GetStudio(*L, timeDate, title, timeSchedule, temp);
		} else if(!strcmp(temp, "Kursi")) {
			
		}
	}
	
	fclose(fp);
}
