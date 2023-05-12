#include "StrukturData.h"

void saveAllData(List L) {
	FILE *fp = fopen("data.txt", "w");
	saveAllDate(*L.firstDate, fp);
	fclose(fp);
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
		fprintf(fp, "%d\n", time->tm_hour);
		fprintf(fp, "%d\n", time->tm_min);
		fprintf(fp, "%d\n", time->tm_sec);
		printf("disimpan");
		system("pause");
		break;
//		saveAllFilm(*firstFilm(*bantu));
		
		bantu = nextDate(*bantu);
	}
}

void saveAllFilm(Film film) {
	
}

void saveAllSchedule(Schedule schedule) {
	
}

void saveStudio(Studio studio) {
	
}

void saveAllChair(Kursi chair) {
	
}
