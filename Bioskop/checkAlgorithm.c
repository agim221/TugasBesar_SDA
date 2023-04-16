#include"NRLL.c"

//Film SearchFilm(List L,String name);
//
//Film SearchFilm(List L,String name) {
//	Film *film;
//	film = L.firstFilm;
//	
//	while(film != NULL) {
//		if(strcmp(name, film->judul)) return film;
//		film = film.nextFilm;
//	}
//	
//	return NULL;
//}
//
//Date SearchDate(Film film, time_t time) {
//	Date *date;
//	date = film.nextDate;
//	
//	while(date != NULL) {
//		if(difftime(date->time, time) == 0) return date;
//		date = date->nextDate;
//	}
//	
//	return NULL;
//}
//
//Studio SearchStudio(Date date, String name) {
//	Studio *studio;
//	studio = date.nextStudio;
//	
//	while(stduio != NULL) {
//		if(strcmp(studio->studioName, name)) return studio;
//		studio = studio->nextStudio;
//	}
//	
//	return NULL;
//}
//
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
//
//Film GetFilm(List L, String name) {
//	return SearchFilm(L, name);
//}
//
//Date GetDate(List L, String name, time_t time) {
//	return SearchDate(GetFilm(L, name), time);
//}
//
//Studio GetStudio(List L, String name, time_t time, String studioName) {
//	return SearchStudio(GetDate(L, name, time), studioName);
//}
//
//Chair GetChair(List L, String name, time_t time, String studioName, String noKursi) {
//	return SearchChair(GetStudio(L, name, time, studioName), noKursi);
//}
