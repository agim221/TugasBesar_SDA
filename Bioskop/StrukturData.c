#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

#define locketName(L, I) (L[I]).loket
#define age(L) (L).age
#define namePerson(L) (L).name
#define nextPerson(L) (L).nextPerson
#define firstPerson(L, I) (L[I]).firstPerson
#define lastPerson(L, I) (L[I]).lastPerson

#define nextStudio(L) (L).nextStudio

#define firstFilm(L) (L).firstFilm
#define lastFilm(L) (L).lastFilm
#define filmTitle(L) (L).judul
#define filmDuration(L) (L).durasi
#define filmCategory(L) (L).kategori
#define filmAge(L) (L).umur
#define nextFilm(L) (L).nextFilm

#define firstDate(L) (L).firstDate
#define lastDate(L) (L).lastDate
#define nextDate(L) (L).nextDate

#define nextSchedule(L) (L).nextSchedule
#define firstSchedule(L) (L).firstSchedule
#define lastSchedule(L) (L).lastSchedule

#define jmlhPenonton(L) (L).jmlhPenonton
#define studioName(L) (L).studioName
#define firstChair(L) (L).firstChair
#define lastChair(L) (L).lastChair
#define nextChair(L) (L).nextChair

typedef char * String;

typedef struct film *almtFilm;
typedef struct date *almtDate;
typedef struct schedule *almtSchedule;
typedef struct studio *almtStudio;
typedef struct person *almtPerson;
typedef struct chair *almtChair;

typedef struct date {
	time_t time;
	almtFilm nextFilm;
	almtDate nextDate;
	almtFilm firstFilm;
	almtFilm lastFilm;	
} Date;

typedef struct film {
	String judul;
	int durasi;
	String kategori;
	int umur;
	almtFilm nextFilm;
	almtSchedule firstSchedule;
	almtSchedule lastSchedule;
	almtSchedule nextSchedule;
} Film;

typedef struct schedule {
	time_t time;
	almtSchedule nextSchedule;
	almtStudio nextStudio;
} Schedule;

typedef struct studio {
	String studioName;
	int jmlhPenonton;
	almtChair nextChair;
	almtChair firstChair;
	almtChair lastChair;
} Studio;

typedef struct person {
	String name;
	int age;
	almtPerson nextPerson;
} Person;

typedef struct chair {
	String noKursi;
	Person person;
	almtChair *nextChair;
} Chair;

typedef struct loket {
	String loket;
	almtPerson firstPerson;
	almtPerson lastPerson;
} Loket;
typedef Loket lockets[2];

typedef struct {
	almtDate firstDate;
	almtDate lastDate;
} List;

void createLocket(lockets L, String name, int index) {
	locketName(L, index) = name;
	firstPerson(L, index) = NULL;
	lastPerson(L, index) = NULL;
}




